#import "chord.hpp"
#import "chordquality.hpp"
#import "functions.hpp"
#import "interval.hpp"
#import "pitch.hpp"
#import "scale.hpp"
#import "util.hpp"

bool appropriate(list<Chord*>& candidate, Chord& next) {
    if (candidate.empty())
        return true;
    
    Chord& prev = *(candidate.back());
    
    // Check that it has exactly two notes in common
    uint64_t mask1 = prev.bitmask();
    uint64_t mask2 = next.bitmask();
    
    return popcount(mask1 & mask2) == 2;
}

int main() {
    /*
    Scale s = Scale::major(Eb);//Scale::locrian(D).majorize(3);
    s.print();
    printf("\n");

    Scale s2 = Scale::major(C).rotate(2);//Scale::locrian(D).majorize(3);
    s2.print();
    printf("\n");
    
    for (std::pair<std::string, Qualities> kq : Qualities::conventionalChords()) {
        printf("  %s: ", kq.first.c_str());
        Chord ch = Chord::build(s, kq.second);
        ch.print();
        printf("\n");
    }
    */
    
    /*
    # Say we have a 12 bar form
    # For each bar,
    #     for each candidate
    #         loop through each possible NEXT chord (there's not that many of them)
    #         if it's appropriate, generate a new candidate
    #         if it's not appropriate, ignore it
    */
    
    auto quals = Qualities::conventionalChords();
    list<Chord> chords;
    for (int i = 0; i < 12; i++) {
        Scale scale = Scale::major(Note(i));
        for (auto qualpair : quals) {
            chords.push_back(Chord::build(scale, qualpair.second));
        }
    }
    
    list<list<Chord*> > candidates;
    const int numbars = 8;
    for (int bar = 0; bar < numbars; bar++) {
        list<list<Chord*> > new_candidates;
        for (list<Chord*>& candidate : candidates) {
            for (Chord& ch : chords) {
                if (appropriate(candidate, ch)) {
                    list<Chord*> new_candidate = candidate;
                    new_candidate.push_back(&ch);
                    
                    new_candidates.push_back(new_candidate);
                }
            }
        }
        candidates = new_candidates;
    }
    
    for (list<Chord*>& candidate : candidates) {
        printf("| ");
        for (Chord* ch : candidate) {
            ch->print();
            printf(" | ");
        }
        printf("\n");
    }
    
}
