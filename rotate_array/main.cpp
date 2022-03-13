#include <iostream>
using namespace std;


void shiftOneRight(int* a, int size) {
    
    int tmp = a[size-1];
    for (int i = size-2; i >= 0; --i) {
        a[i+1] = a[i];
    }
    a[0] = tmp;
}


int main() {

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    const int N = sizeof(a)/sizeof(*a);

    int k = 123;
    k %= N;

    for (int i = 0; i < k; ++i) {
        shiftOneRight(a, N);
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
