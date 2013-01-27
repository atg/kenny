#import "pitch.hpp"
#define build_scale(...) Scale({ __VA_ARGS__ })

struct Scale {
    static Scale minor(root) { return build_scale(C, D, Eb, F, G, A, B).reroot(root); }
    
    static Scale major(root) { return build_scale(C, D, E, F, G, A, B).reroot(root); }
    static Scale dorian(root) { return build_scale(D, E, F, G, A, B, C).reroot(root); }
    static Scale phrygian(root) { return build_scale(E, F, G, A, B, C, D).reroot(root); }
    static Scale lydian(root) { return build_scale(F, G, A, B, C, D, E).reroot(root); }
    static Scale mixolydian(root) { return build_scale(G, A, B, C, D, E, F).reroot(root); }
    static Scale aeolian(root) { return build_scale(A, B, C, D, E, F, G).reroot(root); }
    static Scale locrian(root) { return build_scale(B, C, D, E, F, G, A).reroot(root); }
    
    list<Note> tones;
    Scale(list<Note> _tones) : tones(_tones) { }
    
    Scale reroot(Note newroot);
    Scale minorize(int toneidx);
    Scale majorize(int toneidx);
};
