#import "chord.hpp"
#import "chordquality.hpp"
#import "functions.hpp"
#import "interval.hpp"
#import "pitch.hpp"
#import "scale.hpp"
#import "util.hpp"

int main() {
    Scale::locrian(D).majorize(3).print();
    printf("\n");
}
