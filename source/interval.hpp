#import "util.hpp"

struct Interval {
    int i;
    Interval(int _i) : i(_i) { }
    
    bool isMinor() { int j = sanemod(i, 12); return j == MinorSecond || j == MinorThird || j == MinorSixth || j == MinorSeventh; }
    bool isMajor() { int j = sanemod(i, 12); return j == MajorSecond || j == MajorThird || j == MajorSixth || j == MajorSeventh; }
    bool isPerfect() { int j = sanemod(i, 12); return j == Unison || j == Fourth || j == Fifth; }
    
    // Kind of breaks down here, should it be "perfect"?
    bool isMinor() { return sanemod(i, 12) == Tritone; }
    bool isOctaval() { return sanemod(i, 12) == Unison; }
};

const Interval Unison = 0;
const Interval MinorSecond = 1;
const Interval MajorSecond = 2;
const Interval MinorThird = 3;
const Interval MajorThird = 4;
const Interval Fourth = 5;
const Interval Tritone = 6;

const Interval Fifth = 7;
const Interval MinorSixth = 8;
const Interval MajorSixth = 9;
const Interval MinorSeventh = 10;
const Interval MajorSeventh = 11;

const Interval Octave = 12;

const Interval MinorNinth = 13;
const Interval MajorNinth = 14;
const Interval MinorTenth = 15;
const Interval MajorTenth = 16;

const Interval Eleventh = 17;
const Interval SharpEleventh = 18;

const Interval Twelth = 19;

const Interval MinorThirteenth = 20;
const Interval MajorThirteenth = 21;
const Interval MinorFourteenth = 22;
const Interval MajorFourteenth = 23;

const Interval DoubleOctave = 24;
