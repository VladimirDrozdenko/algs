#include <iostream>
#include <cmath>

using namespace std;


struct PrimeFactors {
    unsigned int factors[INT16_MAX];
    unsigned int exps[INT16_MAX];
    size_t len;

    void factorize(unsigned int n) {
        len = 0;

        unsigned int prime_factor = 2;
        while (n > 1 && prime_factor*prime_factor <= n) {
            size_t count_expos = 0;
            while (n % prime_factor == 0) {
                n /= prime_factor;
                ++count_expos;
            }

            if (count_expos > 0) {
                factors[len] = prime_factor;
                exps[len] = count_expos;
                ++len;
            }

            ++prime_factor;
        }

        if (n > 1) {
            factors[len] = n;
            exps[len] = 1;
            ++len;
        }
    }
};

int main()
{
    const unsigned int number = 238;

    cout << "For the " << number << " the prime factors: " << endl;

    PrimeFactors pf;
    pf.factorize(number);

    for (size_t i = 0; i < pf.len; ++i) {
        cout << "(" << pf.factors[i] << ", " << pf.exps[i] << ")" << endl;
    }

    return 0;
}
 