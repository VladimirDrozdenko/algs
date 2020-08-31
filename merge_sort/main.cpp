//
// Implement merge sort
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int merge_buffer[INT16_MAX];

void merge_arrays(vector<int>& a, int l, int m, int r) {
    int o = 0;
    int p1 = l, p2 = m;
    while (p1 < m && p2 < r) {
        if (a[p1] < a[p2]) {
            merge_buffer[o++] = a[p1++];
        } else {
            merge_buffer[o++] = a[p2++];
        }
    }

    int p = (p1 < m) ? p1 : p2;
    int e = (p1 < m) ? m : r;
    while (p < e) {
        merge_buffer[o++] = a[p++];
    }

    for (int i = l, j = 0; i < r; ++i) {
        a[i] = merge_buffer[j++];
    }
}

void merge_sort(vector<int>& a, int l, int r) {
    if (r - l > 1) {
        int m = l + (r - l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m, r);
        merge_arrays(a, l, m, r);
    }
}

int main() {
    vector<int> arr = {3, 5, 1, 9, 8, 0, -3, 5, 11, 0, 2, 9, 7, 0};

    merge_sort(arr, 0, arr.size());

    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
}