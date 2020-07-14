/*
Given a matrix A[NxM].
After multiple updates for a given range return a result matrix.

Update(r1, c2, r2, c2, value) will add a value to all elements in submatrix, defined by 
upper left coordinate (r1, c2) and bottom right coordinate (r2, c2).
*/

#include <iostream>
#include <vector>
using namespace std;


class Algorithm {
    const size_t n;
    const size_t m;
    const vector<vector<int>>& a;
    vector<vector<int>> b;

public:
    Algorithm(const vector<vector<int>>& arr)
        : n(arr.size()), m(arr.at(0).size()), a(arr) {
        for (size_t r = 0; r < n; ++r) {
            b.push_back(vector<int>());
            for (size_t c = 0; c < m; ++c) {
                b[r].push_back(0);
            }
        }
    }

    void Update(size_t r1, size_t c1, size_t r2, size_t c2, int value) {
        b[r1][c1] += value;
        if (r2+1 < n && c2+1 < m)
            b[r2+1][c2+1] += value;
        if (c2+1 < m)
            b[r1][c2+1] -= value;
        if (r2+1 < n)
            b[r2+1][c1] -= value;
    }

    vector<vector<int>> GetResultMatrix() const {
        vector<vector<int>> res, s;
        for (size_t r = 0; r < n; ++r) {
            res.push_back(vector<int>());
            s.push_back(vector<int>());
            for (size_t c = 0; c < m; ++c) {
                res[r].push_back(a[r][c]);
                s[r].push_back(0);
            }
        }

        // building a partial sum matrix
        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < m; ++c) {
                if (r == 0 && c == 0) {
                    s[r][c] = b[r][c];
                } else if (r == 0) {
                    s[r][c] = s[r][c-1] + b[r][c];
                } else if (c == 0) {
                    s[r][c] = s[r-1][c] + b[r][c];
                } else {
                    s[r][c] = s[r-1][c] + s[r][c-1] - s[r-1][c-1] + b[r][c];
                }
            }
        }

        // building result
        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < m; ++c) {
                res[r][c] = a[r][c] + s[r][c];
            }
        }

        return res;
    }
};

ostream& operator << (ostream& os, const vector<vector<int>>& a) {
    for (size_t r = 0; r < a.size(); ++r) {
        for (size_t c = 0; c < a.at(0).size(); ++c) {
            os << a[r][c] << " ";
        }
        os << endl;
    }
    return os;
}


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
    alg.Update(0, 2, 2, 4, 2);
    alg.Update(2, 3, 5, 5, -1);
    alg.Update(0, 0, 5, 1, 3);
    
    cout << alg.GetResultMatrix() << endl;
}