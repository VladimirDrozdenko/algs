/*
Given a matrix A[NxM] filled with ones and zeros.
Find the largest square submatrix of ones.
*/

#include <iostream>
#include <vector>
using namespace std;

int GetLargestSquare(const vector<vector<size_t>>& a) {
    const size_t n = a.size();
    const size_t m = a.at(0).size();
    size_t max_size_result = 0;

    vector<vector<size_t>> s;

    for (size_t r = 0; r < n; ++r) {
        s.push_back(vector<size_t>());
        for (size_t c = 0; c < m; ++c) {
            if (a[r][c] < 0 || a[r][c] > 1)
                throw invalid_argument("expected binary matrix.");

            if (r == 0 || c == 0)
                s[r].push_back(a[r][c]);
            else {
                if (a[r][c] == 0)
                    s[r].push_back(0);
                else
                    s[r].push_back(min(s[r-1][c], min(s[r][c-1], s[r-1][c-1])) + 1);
            }

            max_size_result = max(max_size_result, s[r][c]);
        }
    }

    return max_size_result;
}

int main() {
    const vector<vector<size_t>> a = {
        vector<size_t>({0, 0, 1, 1, 1, 1, 1}),
        vector<size_t>({1, 1, 1, 1, 1, 1, 0}),
        vector<size_t>({1, 0, 1, 1, 1, 1, 1}),
        vector<size_t>({0, 1, 1, 1, 1, 1, 1}),
        vector<size_t>({1, 1, 1, 1, 0, 1, 1}),
        vector<size_t>({1, 1, 1, 0, 1, 0, 0})
    };

    try {
        size_t square_size = GetLargestSquare(a);
        cout << "Max square is " << square_size << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}