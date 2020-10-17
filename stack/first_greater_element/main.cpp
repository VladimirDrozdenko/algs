//
// First greater element problem for all elements of a given array O(N)
//
// INPUT: an array of integers
// a = [7, 3, 2, 6, 11, 3]
//
// OUTPUT: an array of the first element greater than the element in input array
// result = [11, 6, 6, 11, 0]

#include <iostream>
#include <stack>
using namespace std;


const int a[] = {7, 3, 2, 6, 11, 3, 8, 10, 13};
const size_t n = sizeof(a) / sizeof(*a);


int main() {
    int* res = new int[n];    

    stack<pair<int, size_t>> s;
    
    for (size_t i = 0; i < n; ++i) {
        if (s.empty() || s.top().first > a[i]) {
            s.push(make_pair(a[i], i));
        } else {
            while (!s.empty() && s.top().first < a[i]) {
                res[s.top().second] = a[i];
                s.pop();
            }
            s.push(make_pair(a[i], i));
        }
    }

    for (size_t i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete [] res;
}