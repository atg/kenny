enum PitchClass : int {
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
    
    Note(int p) : pitch(PitchClass(p)) { }
    Note(PitchClass p) : pitch(p) { }
    operator PitchClass () { return pitch; }
    
    Note flat() { return Note(sanemod(int(pitch) - 1, 12)); }
    Note sharp() { return Note(sanemod(int(pitch) + 1, 12)); }
    
    Note transpose(Note oldroot, Note newroot) {
        int p = pitch;
        int o = oldroot;
        int n = newroot;
        
        // If oldroot is C and newroot is D and pitch is E, then we want to add 2 to the pitch 
        return Note(sanemod(p + (n - o), 12));
    }
};
