#import "interval.hpp"

bool Interval::isMinor() { const Interval j = sanemod(i, 12); return j == MinorSecond || j == MinorThird || j == MinorSixth || j == MinorSeventh; }
bool Interval::isMajor() { const Interval j = sanemod(i, 12); return j == MajorSecond || j == MajorThird || j == MajorSixth || j == MajorSeventh; }
bool Interval::isPerfect() { const Interval j = sanemod(i, 12); return j == Unison || j == Fourth || j == Fifth; }

// Kind of breaks down here, should it be "perfect"?
bool Interval::isTritone() { return (const Interval)sanemod(i, 12) == Tritone; }
bool Interval::isOctaval() { return (const Interval)sanemod(i, 12) == Unison; }
