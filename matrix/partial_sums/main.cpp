/*
Given a matrix A[NxM].
Find the sum of all elements in submatrix defined by 
- upper left corner (r1, c1)
- down right corner (r2, c2)
*/

#include <iostream>
#include <vector>
using namespace std;


class Algorithm {
    const size_t n;
    const size_t m;
    vector<vector<long>> s;

public:
    Algorithm(const vector<vector<int>>& a)
        : n(a.size()), m(a.at(0).size()) {
            for (size_t r = 0; r < n; ++r) {
                s.push_back(vector<long>());
                for (size_t c = 0; c < m; ++c) {
                    if (r == 0 && c == 0)
                        s[r].push_back(a[r][c]);
                    else if (r == 0)
                        s[r].push_back(a[r][c] + s[r][c-1]);
                    else if (c == 0)
                        s[r].push_back(a[r][c] + s[r-1][c]);
                    else
                        s[r].push_back(a[r][c] + s[r][c-1] + s[r-1][c] - s[r-1][c-1]);
                }
            }
    }

    long getSubMatrixSum(size_t r1, size_t c1, size_t r2, size_t c2) {
        long sum = s[r2][c2];
        if (r1 > 0)
            sum -= s[r1-1][c2];
        if (c1 > 0)
            sum -= s[r2][c1-1];
        if (r1 > 0 && c1 > 0)
            sum += s[r1-1][c1-1];
        return sum;
    }
};


int main() {
    const vector<vector<int>> a = {
        vector<int>({1, 7, 12, 10, 1, 0}),
        vector<int>({11, 7, -10, 1, 3, 13}),
        vector<int>({-2, 9, -5, 2, 4, 7}),
        vector<int>({4, 14, -9, 3, 13, -6}),
        vector<int>({-7, -8, -9, 12, 6, 4}),
        vector<int>({2, -13, 10, 11, 8, 7})
    };

    Algorithm alg(a);
    cout << alg.getSubMatrixSum(0, 2, 2, 4) << endl;
    cout << alg.getSubMatrixSum(2, 3, 5, 5) << endl;
    cout << alg.getSubMatrixSum(0, 0, 5, 1) << endl;
}