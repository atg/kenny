#import "chord.hpp"
#import "chordquality.hpp"
#import "functions.hpp"
#import "interval.hpp"
#import "pitch.hpp"
#import "scale.hpp"
#import "util.hpp"

int main() {
    Scale s = Scale::major(Eb);//Scale::locrian(D).majorize(3);
    s.print();
    printf("\n");
    
    for (std::pair<std::string, Qualities> kq : Qualities::conventionalChords()) {
        printf("  %s: ", kq.first.c_str());
        Chord ch = Chord::build(s, kq.second);
        ch.print();
        printf("\n");
    }
}
