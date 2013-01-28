#include <vector>
#include <stdint.h>

template<class T>
using list = std::vector<T>;

// The C % operator is IDIOTIC
static int sanemod(int n, int m) {
    return ((n % m) + m) % m;
}

static int popcount(uint64_t x) {
    int count = 0;
    while (x) {
        count++;
        x &= x - 1; // reset LS1B
    }
    return count;
}
