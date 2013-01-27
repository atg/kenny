enum PitchClass {
    C = 0,
    Cshp = 1,
    
    Db = 1,
    D = 2,
    Dshp = 3,
    
    Eb = 3,
    E = 4,
    Eshp = 5,
    
    F = 5,
    Fshp = 6,
    
    Gb = 6,
    G = 7,
    Gshp = 8,
    
    Ab = 8,
    A = 9,
    Ashp = 10,
    
    Bb = 10,
    B = 11,
};

struct Note {
    PitchClass pitch;
    
    Note(PitchClass p) : pitch(p) { }
    operator PitchClass () { return p; }
};
