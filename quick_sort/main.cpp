//
// Implement quick sort
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int pval = a[l];
    int p = l;
    for (int i = l; i < r; ++i) {
        if (a[i] < pval) {
            swap(a[++p], a[i]);
        }
    }
    swap(a[l], a[p]);
    return p;
}

void quick_sort(vector<int>& a, int l, int r) {
    if (r - l > 1) {
        int part = partition(a, l, r);
        quick_sort(a, l, part);
        quick_sort(a, part+1, r);
    }
}

int main() {
    vector<int> arr = {4, 0, 3, 2, 1, 3, 5, 1, 9, 8, 0, -3, 5, 11, 0, 2, 9, 7, 0};

    quick_sort(arr, 0, arr.size());

    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
}