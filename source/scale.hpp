#import "util.hpp"
#import "pitch.hpp"
#define build_scale(...) Scale(list<Note>({ __VA_ARGS__ }))

struct Scale {
    // https://en.wikipedia.org/wiki/List_of_musical_scales_and_modes
    
    // 7 note scales
    static Scale major(Note root) { return build_scale(C, D, E, F, G, A, B).reroot(root); }
    static Scale dorian(Note root) { return build_scale(D, E, F, G, A, B, C).reroot(root); }
    static Scale phrygian(Note root) { return build_scale(E, F, G, A, B, C, D).reroot(root); }
    static Scale lydian(Note root) { return build_scale(F, G, A, B, C, D, E).reroot(root); }
    static Scale mixolydian(Note root) { return build_scale(G, A, B, C, D, E, F).reroot(root); }
    static Scale aeolian(Note root) { return build_scale(A, B, C, D, E, F, G).reroot(root); }
    static Scale locrian(Note root) { return build_scale(B, C, D, E, F, G, A).reroot(root); }
    
    static Scale melodicMinor(Note root) { return build_scale(C, D, Eb, F, G, A, B).reroot(root); }
    static Scale harmonicMinor(Note root) { return build_scale(C, D, Eb, F, G, Ab, B).reroot(root); }
    
    static Scale acoustic(Note root) { return build_scale(C, D, E, Fshp, G, A, Bb).reroot(root); }
    static Scale adonaiMalakh(Note root) { return build_scale(C, D, E, F, G, Ab, Bb).reroot(root); }
    static Scale altered(Note root) { return build_scale(C, Db, Eb, E, Gb, Ab, Bb).reroot(root); }
    static Scale doubleHarmonicMajor(Note root) { return build_scale(C, Db, E, F, G, Ab, B).reroot(root); }
    static Scale enigmatic(Note root) { return build_scale(C, Db, E, Fshp, Gshp, Ashp, B).reroot(root); } // 1 b2 3 #4 #5 #6 7
    static Scale flamenco(Note root) { return build_scale(C, Db, E, F, G, Ab, B).reroot(root); } // 1 b2 3 4 5 b6 7
    static Scale gypsy(Note root) { return build_scale(C, D, Eb, Fshp, G, Ab, Bb).reroot(root); } // 1 2 b3 #4 5 b6 b7
    static Scale harmonicMajor(Note root) { return build_scale(C, D, E, F, G, Ab, B).reroot(root); }
    static Scale hungarianMinor(Note root) { return build_scale(C, D, Eb, Fshp, G, Ab, B).reroot(root); } // 1 2 b3 #4 5 b6 7
    static Scale lydianAugmented(Note root) { return build_scale(C, D, E, Fshp, Gshp, A, B).reroot(root); } // 1 2 3 #4 #5 6 7
    static Scale majorLocrian(Note root) { return build_scale(C, D, E, F, Gb, Ab, Bb).reroot(root); } // 1 2 3 4 b5 b6 b7
    static Scale neapolitanMajor(Note root) { return build_scale(C, Db, Eb, F, G, A, B).reroot(root); } // 1 b2 b3 4 5 6 7
    static Scale neapolitanMinor(Note root) { return build_scale(C, Db, Eb, F, G, Ab, B).reroot(root); } // 1 b2 b3 4 5 b6 7
    static Scale persian(Note root) { return build_scale(C, Db, E, F, Gb, Ab, B).reroot(root); } // 1 b2 3 4 b5 b6 7
    static Scale phrygianDominant(Note root) { return build_scale(C, Db, E, F, G, Ab, Bb).reroot(root); } // 1 b2 3 4 5 b6 b7
    static Scale tritone(Note root) { return build_scale(C, Db, E, F, Gb, G, Bb).reroot(root); } // 1 b2 3 4 b5 6 b7
    static Scale ukrainianDorian(Note root) { return build_scale(C, D, Eb, Fshp, G, A, Bb).reroot(root); }
    
    // 8 note scales
    static Scale majorBebop(Note root) { return build_scale(C, D, E, F, G, Ab, A, B).reroot(root); } // 1 2 3 4 5 (#5/b6) 6 7
    static Scale bebopDominant(Note root) { return build_scale(C, D, E, F, G, A, Bb, B).reroot(root); }
    static Scale diminishedSemitone(Note root) { return build_scale(C, Db, Eb, E, Fshp, G, A, Bb).reroot(root); } // 1 b2 b3 3 #4 5 6 b7
    static Scale diminishedTone(Note root) { return build_scale(C, D, Eb, F, Gb, Ab, A, B).reroot(root); } // 1 2 b3 4 b5 b6 6 7
    
    // 6 note scales
    static Scale blues(Note root) { return build_scale(C, Eb, F, Gb, G, Bb).reroot(root); }
    static Scale wholetone(Note root) { return build_scale(C, D, E, Fshp, Gshp, Ashp).reroot(root); } // 1 2 3 #4 #5 #6
    static Scale prometheus(Note root) { return build_scale(C, D, E, Fshp, A, Bb).reroot(root); } // 1 2 3 #4 6 b7
    static Scale istrian(Note root) { return build_scale(C, Db, Eb, E, Gb, G).reroot(root); } // 1 b2 b3 b4 b5 5
    static Scale augmented(Note root) { return build_scale(C, Eb, E, G, Gshp, B).reroot(root); } // 1 b3 3 5 #5 7        
    
    
    list<Note> tones;
    Scale(list<Note> _tones) : tones(_tones) { }
    
    Scale reroot(Note newroot);
    Scale minorize(int toneidx);
    Scale majorize(int toneidx);
    Scale rotate(int amount); // e.g. major(C).rotate(1) is D dorian
    
    void print();
};
