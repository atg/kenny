#import <string>
#import <utility>
#import "util.hpp"

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
    
    static Qualities parse(std::string str);
    static list<std::pair<std::string, Qualities> > conventionalChords();
    
    std::string toString();
};

