#import "interval.hpp"
#import "pitch.hpp"

static Interval delta(Note lower, Note higher) {
    int a = (int)lower;
    int b = (int)higher;
    if (a < b)
        return b - a;
    if (a > b)
        return (b + 12) - a;
    return 0;
}
