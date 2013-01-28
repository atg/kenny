#import "chord.hpp"

Chord Chord::build(Scale scale, Qualities q) {
    Chord ch;
    ch.scale = scale;
    
    #define add_note(n, k) do { \
        int t = int(scale.tones[n - 1].pitch); \
        if (q . k == Quality::Flat) t -= 1; \
        else if (q . k == Quality::Sharp) t += 1; \
        else if (q . k == Quality::Missing) break; \
        ch.tones.push_back(Note(sanemod(t, 12))); \
    } while (0)
    
    ch.tones.push_back(scale.tones[0]);
    
    add_note(2, second);
    add_note(3, third);
    add_note(4, fourth);
    add_note(5, fifth);
    add_note(6, sixth);
    add_note(7, seventh);
    
    add_note(2, ninth);
    add_note(4, eleventh);
    add_note(6, thirteenth);
    
    return ch;
}

static uint64_t mask_fromNoteIndex(int i) {
    return 1 << i;
}

uint64_t Chord::bitmask() {
    // The rule is that the root is always the lowest note
    uint64_t mask = 0;
    
    int mini = -1;
    for (Note note : tones) {
        int i = note.pitch;
        while (i <= mini)
            i += 12;
        mini = i;
        
        mask |= mask_fromNoteIndex(i);
    }
    
    return mask;
}

void Chord::print() {
    const char* sep = "";
    printf("{");
    for (Note n : tones) {
        printf("%s", sep);
        sep = ", ";
        
        n.print();
    }
    printf("}");
}
