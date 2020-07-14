#include <iostream>
#include <vector>
using namespace std;


class RangeUpdate {
    vector<int> arr;
    vector<int> s;

public:
    RangeUpdate(const vector<int>& a) 
        : arr(a.cbegin(), a.cend())
    {
        for (size_t i = 0; i < a.size(); ++i) {
            s.push_back(0);
        }

        s.push_back(0);
    }

public:
    void Update(size_t b, size_t e, int val) {
        if (b >= arr.size() || e >= arr.size()) {
            throw out_of_range("index is more than array size.");
        }

        s[b] += val;
        s[e+1] -= val;
    }

    void Print() {
        vector<int> partial_sum;
        for (size_t i = 0; i < arr.size(); ++i) {
            partial_sum.push_back(0);
        }

        partial_sum[0] = s[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            partial_sum[i] = partial_sum[i-1] + s[i];
        }

        for (size_t i = 0; i < arr.size(); ++i) {
            cout << (arr[i] + partial_sum[i]) << " ";
        }

        cout << endl;
    }
};


int main() {
    int a[] = {2, -7, 10, 3, -1, 19, -20, 23, 17};
    const size_t sz = sizeof(a) / sizeof(*a);

    RangeUpdate ru(vector<int>(a, a+sz));
    ru.Update(2, 6, 5);
    ru.Update(3, 7, 2);
    ru.Update(1, 5, -1);
    ru.Print();
}