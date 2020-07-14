#include <iostream>
#include <vector>
using namespace std;


class PartialSumRangeQuery {
    vector<int> ps;

public:
    PartialSumRangeQuery(const vector<int>& a) {
        for (size_t i = 0; i < a.size(); ++i) {
            if (i == 0)
                ps.push_back(a[i]);
            else {
                ps.push_back(ps[i-1] + a[i]);
            }
        }
    }

    int queryRange(size_t b, size_t e) {
        if (e >= ps.size())
            throw out_of_range("end index is beyond array size");

        return (b == 0)
            ? ps[e]
            : ps[e] - ps[b - 1];
    }
};

int main() {

    const int a[] = { 7, -2, 4, 10, -11, 0, 6};
    PartialSumRangeQuery alg(vector<int>(a, a + sizeof(a)/sizeof(*a)));
    cout << alg.queryRange(2, 4) << endl;
}