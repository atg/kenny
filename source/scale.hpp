#import "util.hpp"
#import "pitch.hpp"
#define build_scale(...) Scale(list<Note>({ __VA_ARGS__ }))

struct Scale {
    static Scale minor(Note root) { return build_scale(C, D, Eb, F, G, A, B).reroot(root); }
    
    static Scale major(Note root) { return build_scale(C, D, E, F, G, A, B).reroot(root); }
    static Scale dorian(Note root) { return build_scale(D, E, F, G, A, B, C).reroot(root); }
    static Scale phrygian(Note root) { return build_scale(E, F, G, A, B, C, D).reroot(root); }
    static Scale lydian(Note root) { return build_scale(F, G, A, B, C, D, E).reroot(root); }
    static Scale mixolydian(Note root) { return build_scale(G, A, B, C, D, E, F).reroot(root); }
    static Scale aeolian(Note root) { return build_scale(A, B, C, D, E, F, G).reroot(root); }
    static Scale locrian(Note root) { return build_scale(B, C, D, E, F, G, A).reroot(root); }
    
    list<Note> tones;
    Scale(list<Note> _tones) : tones(_tones) { }
    
    Scale reroot(Note newroot);
    Scale minorize(int toneidx);
    Scale majorize(int toneidx);
};
