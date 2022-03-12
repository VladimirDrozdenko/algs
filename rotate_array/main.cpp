#include <iostream>
using namespace std;


int main() {

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    const int N = sizeof(a)/sizeof(*a);

    int k = 123;
    k %= N;

    if (N - k < N/2) {
        for (int b = 0, e = N - k; e < N; ++e) {
            swap(a[b++], a[e]);
        }
    } else {
        for (int e = N - 1, b = N - k - 1; b >= 0; --b) {
            swap(a[b], a[e--]);
        }
    }

    cout << "Rotated: [";
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << a[i];
    }
    cout << "]" << endl;
}