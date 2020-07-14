#include <iostream>

using namespace std;

unsigned int power(unsigned int a, unsigned int pow, unsigned int mod) {
    if (a == 0 || a == 1)
        return a;

    if (pow == 0)
        return 1;

    if (pow % 2 == 0)
        return power((1LL * a * a)%mod, pow/2, mod);
    return (1LL * a * power(a, pow-1, mod)) % mod;
}


int main() {
    unsigned int a = 5;
    unsigned int p = 13;
    unsigned int m = 1000000007;

    cout << a << "^" << p << " % " << m << " = " << power(a, p, m) << endl;
}