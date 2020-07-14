#include <algorithm>
#include <iostream>
using namespace std;

template <unsigned int N>
struct PrimeSelector {
    bool primes[N+1];

    PrimeSelector() {
        for (size_t i = 0; i <= N; ++i)
            primes[i] = true;
    }

    void run() {
        for (size_t i = 2; i < N/2; ++i) {
            if (!primes[i]) continue;
            for (size_t j = i*2; j <= N; ++j) {
                if (j % i == 0) {
                    primes[j] = false;
                }
            }
        }
    }
};

int main() {

    const size_t N = 17;
    PrimeSelector<N> ps;
    ps.run();

    for (size_t i = 2; i <= N; ++i) {
        if (ps.primes[i])
            cout << i << " ";
    }
}