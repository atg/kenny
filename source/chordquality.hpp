#import <string>

enum class Quality {
    // Relative to the scale:
    //   if we have a major scale, then the third would be *flat*, not normal.
    //   but if the base scale is minor, then the third is normal.
    Missing = 0,
    Flat,
    Included,
    Sharp,
};

struct Qualities {
    Quality second;
    Quality third;
    Quality fourth;
    Quality fifth;
    Quality sixth;
    Quality seventh;
    Quality ninth;
    Quality eleventh;
    Quality thirteenth;
    
    Qualities() {
        memset(this, 0, sizeof(Qualities));
        third = Quality::Included;
        fifth = Quality::Included;
    }
    
    static Qualities parse(std::string str) {
        Qualities q;
        
        bool majorSeven = false;
        Quality accidental = Quality::Included;
        const char* s = str.c_str();
        for (const char *it = s, *et = s + str.size(); it != et; it++) {
            // -        (affects 3)
            // o        (affects 3 5 6)
            // 2        (affects 2)
            // +        (affects 5th)
            // [b]5     (affects 5th)
            // [b#]6    (affects 6)
            // [^]?7    (affects 7)
            // [b#]?9   (affects 9)
            // [b#]?11  (affects 11)
            // [b#]?13  (affects 13)
            // sus      (affects 4)
            // alt      (affects - fuck it) https://en.wikipedia.org/wiki/Altered_chord#Jazz
            // susadd3  (affects 3 4)
            
            // TODO: Coax iTunes into letting me buy that iReal Book IAP so that I can find out what the fuck a "-^9" chord is and what it does for alt chords
            
            // Minor third
            if (*it == '-')
                q.third = Quality::Flat;
            
            // Diminished
            else if (*it == 'o') {
                q.third = Quality::Flat;
                q.fifth = Quality::Flat;
                q.sixth = Quality::Included;
            }
            
            // sus2
            else if (*it == '2') {
                q.second = Quality::Included;
                q.third = Quality::Missing;
            }
            // sus4
            else if (it - s >= 3 && strncmp("sus", it - 3, 3) == 0) {
                q.fourth = Quality::Included;
                q.third = Quality::Missing;
            }
            
            // add2
            else if (it - s >= 4 && strncmp("add2", it - 4, 4) == 0)
                q.second = Quality::Included;
            // add3
            else if (it - s >= 4 && strncmp("add3", it - 4, 4) == 0)
                q.third = Quality::Included;
            // add4
            else if (it - s >= 4 && strncmp("add4", it - 4, 4) == 0)
                q.fourth = Quality::Included;
            // add5
            else if (it - s >= 4 && strncmp("add5", it - 4, 4) == 0)
                q.fifth = Quality::Included;
            
            // #5
            if (*it == '+')
                q.fifth = Quality::Sharp;
            
            // Sixth chords
            if (*it == '6') {
                q.sixth = accidental;
                q.fifth = Quality::Missing;
            }
            
            // Sevenths
            if (*it == '^')
                majorSeven = true;
            else if (*it == '7')
                q.seventh = majorSeven ? Quality::Flat : Quality::Included;
            
            // Extensional
            else if (*it == '9')
                q.ninth = accidental;
            else if (it - s >= 2 && strncmp("11", it - 2, 2) == 0)
                q.eleventh = accidental;
            else if (it - s >= 2 && strncmp("13", it - 2, 2) == 0)
                q.thirteenth = accidental;
            
            // Accidentials
            if (*it == '#')
                accidental = Quality::Sharp;
            else if (*it == 'b')
                accidental = Quality::Flat;
            else
                accidental = Quality::Included;
        }
        
        return q;
    }
};
