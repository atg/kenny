#import <stdio.h>
#import <string>

#import "scale.hpp"
#import "interval.hpp"
#import "functions.hpp"


Scale Scale::reroot(Note newroot) {
    Note oldroot = tones[0];
    
    Scale transposed = *this;
    for (Note& note : transposed.tones) {
        note = note.transpose(oldroot, newroot);
    }
    return transposed;
}

Scale Scale::minorize(int toneidx) {
    // If the tone at toneidx is a major interval, then turn it into a minor one. E.g. minorizing the third of a dorian scale wild nothing, but it'll work for a lydian.
    Scale altered = *this;
    Interval d = delta(tones[0], tones[toneidx - 1]);
    Note& note = altered.tones[toneidx - 1];
    if (d.isMajor())
        note = note.flat();
    return altered;
}

Scale Scale::majorize(int toneidx) {
    // Same thing as minorize turns minor intervals into major ones
    Scale altered = *this;
    Interval d = delta(tones[0], tones[toneidx - 1]);
    Note& note = altered.tones[toneidx - 1];
    if (d.isMinor())
        note = note.sharp();
    return altered;
}

Scale Scale::rotate(int amount) {
    if (amount >= tones.size()) amount = sanemod(amount, tones.size());
    if (amount == 0) return *this;
    
    // Take amount from the front, and stick it on the back, e.g. for a phrygian
    // C D E F G A B -> [C D] [E F G A B] -> [E F G A B C D]
    Scale altered = *this;
    
    // Get the first `amount` notes and put them in the buffer
    list<Note> buffer;
    for (int i = 0; i < amount; i++) {
        buffer.push_back(altered.tones[i]);
    }
    
    // Drop the first `amount` notes from the scale
    altered.tones.erase(altered.tones.begin(), altered.tones.begin() + amount);
    
    // Append the buffer to the end of the scale
    for (Note n : buffer) {
        altered.tones.push_back(n);
    }
    
    return altered;
}

void Scale::print() {
    const char* sep = "";
    printf("[");
    for (Note n : tones) {
        printf("%s", sep);
        sep = ", ";
        
        n.print();
    }
    printf("]");
}
