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
