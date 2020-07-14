#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {

    const vector<int> a = {7, 3, 7, 1, 4, 2, 5, 3, 0, 8, 6, -1, 7, 10, 0, 9};

    size_t max_len = 0;
    pair<size_t, size_t> range;

    for (size_t b = 0; b < a.size(); ++b) {
        unordered_map<int, size_t> ht;
        int max_a = a[b], min_a = a[b];
        for (size_t e = b, len = 0; e < a.size(); ++e) {
            ++ht[a[e]];
            if (ht[a[e]] > 1) {
                break; // duplicate
            }
            
            max_a = max(max_a, a[e]);
            min_a = min(min_a, a[e]);

            ++len;
            if (max_a - min_a + 1 == e - b + 1) {
                if (len > max_len) {
                    max_len = len;
                    range = make_pair(b, e);
                }
            }
        }
    }

    cout << "Longest subarr: (" << range.first << ", " << range.second << ") = " << max_len << endl;
}