#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Given an array of natural numbers, find the longest subarray with at most K distinct elements.
*/
int main() {

    const vector<int> a = {1, 5, 2, 1, 7, 2, 1, 5, 5, 7};
    const size_t k = 3;

    const size_t n = a.size();
    
    unordered_map<int, size_t> fr;

    pair<size_t, size_t> max_range = make_pair(0, 0);
    size_t max_cnt = 0;

    size_t left = 0, right = 0;
    for (; right < n; ++right) {
        fr[a[right]]++;
        if (fr.size() > k)
            break;
    }

    if (max_cnt < right - left) {
        max_cnt = right - left;
        max_range = make_pair(left, right-1);
    }

    while (right < n && left < right) {
        do {
            fr[a[left]]--;
            if (fr[a[left]] == 0)
                fr.erase(a[left]);
            ++left;
        } while (fr.size() > k);

        for (++right; right < n; ++right) {
            fr[a[right]]++;
            if (fr.size() > k)
                break;
        }

        if (max_cnt < right - left) {
            max_cnt = right - left;
            max_range = make_pair(left, right-1);
        }
    }

    cout << "Longest subarr: (" << max_range.first << ", " << max_range.second << ") = " << max_cnt << endl;
}