#import "chordquality.hpp"
#import "scale.hpp"

struct Chord {
    list<Note> tones; // The first item is the root, by convention
    Scale scale; // All the notes in the scale, must be a superset of tones, with tones[0] == scale[0]
    // e.g. if we have C E G Bb, then our scale would be C D E F G A Bb
    
    static Chord build(Note root, Qualities q) { return Chord::build(Scale::major(root), q); }
    static Chord build(Scale scale, Qualities q);
    
    Chord() : tones(), scale(Scale::major(C)) { }
    
    void print();
};
