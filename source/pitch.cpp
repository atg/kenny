#import <stdio.h>
#import <string>

#import "pitch.hpp"

void Note::print() {
    // I hate this business of "correct" enharmonic spelling and wish eternal damnation on anybody perpetuating it.
    // idfk what a Gb is -- it's always an F#, that's what I can read quicker. Gb is FIVE flats. F# is ONE sharp. So fuck you, people who write Gb (*cough* sax players).
    // Why do notes have to have more than one name? That's not very mathematical.
    // Besides, when you get to more generalized theory, the whole "enharmonics" thing really falls apart. If the underlying scale is obscured or non-standard, then there's really no "proper" spelling. The true purpose of enharmonics is to make classical musicians feel better about themselves, safe in their little diatonic bubble. Fuck. That.
    
    if (pitch == C) printf("C");
    else if (pitch == Cshp) printf("C#"); // C# not Db
    else if (pitch == D) printf("D");
    else if (pitch == Eb) printf("Eb"); // Eb not D#
    else if (pitch == E) printf("E");
    else if (pitch == F) printf("F");
    else if (pitch == Fshp) printf("F#"); // F# not Gb
    else if (pitch == G) printf("G");
    else if (pitch == Gshp) printf("G#"); // I use G# because I'm a bassist. Ha! (on the bass you have a G string, and you sharpen it, A is an open string so you cannot flatten it)
    else if (pitch == A) printf("A");
    else if (pitch == Bb) printf("Bb"); // Bb not A# - seeing a pattern?
    else if (pitch == B) printf("B");
    else printf("[UNKNOWN PITCH %d]", (int)pitch);
}
