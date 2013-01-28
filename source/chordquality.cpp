#import "chordquality.hpp"

std::string Qualities::toString() {
    #define serialize_quality(k, mm, MM, nn, missing) do { \
        if (k == Quality::Missing) str.append(missing); \
        else if (k == Quality::Flat) str.append(mm); \
        else if (k == Quality::Sharp) str.append(MM); \
        else str.append(nn); \
    } while (0)
    
    std::string str;
    
    serialize_quality(second, "b2", "#2", "2", "");
    serialize_quality(third, "-", "#3", "", "no3");
    serialize_quality(fourth, "b4", "#4", "4", "");
    serialize_quality(fifth, "b5", "#5", "", "no5");
    serialize_quality(sixth, "b6", "#6", "6", "");
    serialize_quality(seventh, "7", "#7", "^7", "");
    serialize_quality(ninth, "b9", "#9", "9", "");
    serialize_quality(eleventh, "b11", "#11", "11", "");
    serialize_quality(thirteenth, "b13", "#13", "13", "");
    
    return str;
}

Qualities Qualities::parse(std::string str) {
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
        else if (*it == '5')
            q.fifth = accidental;
        
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

list<std::pair<std::string, Qualities> > Qualities::conventionalChords() {
    #define add_conventional(str) do { \
        std::string s = std::string(str); \
        Qualities q = Qualities::parse(str); \
        qs.push_back(std::pair<std::string, Qualities>(s, q)); } while (0)
    
    list<std::pair<std::string, Qualities> > qs;
    add_conventional("");
    add_conventional("+");
    add_conventional("o");
    add_conventional("-b5");
    add_conventional("sus");
    add_conventional("^7");
    add_conventional("-");
    add_conventional("-7");
    add_conventional("7");
    add_conventional("7sus");
    add_conventional("-7b5");
    add_conventional("o7");
    add_conventional("o^7");
    add_conventional("9");
    add_conventional("13");
    add_conventional("6");
    add_conventional("69");
    add_conventional("^7#11");
    add_conventional("^9#11");
    add_conventional("^7#5");
    add_conventional("-6");
    add_conventional("-69");
    add_conventional("-b6");
    add_conventional("-^7");
    add_conventional("-9");
    add_conventional("-11");
    add_conventional("-9b5");
    add_conventional("7b9");
    add_conventional("7#9");
    add_conventional("7#11");
    add_conventional("7b5");
    add_conventional("7#5");
    add_conventional("9#11");
    add_conventional("9b5");
    add_conventional("9#5");
    add_conventional("7b13");
    add_conventional("#9#5");
    add_conventional("#9b5");
    add_conventional("#9#11");
    add_conventional("b9#11");
    add_conventional("b9b5");
    add_conventional("b9#5");
    // add_conventional("b9#9"); // <- shit
    add_conventional("b9b13");
    // add_conventional("7alt"); // <- no idea yet
    add_conventional("13#11");
    add_conventional("13b9");
    add_conventional("13#9");
    add_conventional("7b9sus");
    add_conventional("7susadd3");
    add_conventional("9sus");
    add_conventional("13sus");
    add_conventional("7b13sus");
    add_conventional("11");
    
    return qs;
}

