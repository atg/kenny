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
    Interval d = delta(tones[0], tones[toneidx]);
    Note& note = altered.tones[toneidx];
    if (d.isMajor())
        note = note.flat();
    return altered;
}

Scale Scale::majorize(int toneidx) {
    // Same thing as minorize turns minor intervals into major ones
    Scale altered = *this;
    Interval d = delta(tones[0], tones[toneidx]);
    Note& note = altered.tones[toneidx];
    if (d.isMinor())
        note = note.sharp();
    return altered;
}
