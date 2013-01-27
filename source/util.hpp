#include <vector>

template<class T>
using list<T> = std::vector<T>;

// The C % operator is IDIOTIC
static int sanemod(int n, int m) {
    return ((n % m) + m) % m;
}
