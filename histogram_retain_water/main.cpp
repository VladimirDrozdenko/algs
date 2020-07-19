/*
For a given histogram a[] = {...}
How much water will be retained?
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //const vector<int> hist = {0, 2, 4, 3, 3, 6, 1, 5, 4, 2, 4, 1, 3, 1}; // res = 10
    const vector<int> hist = {0, 2, 4, 5, 4, 3, 2, 0, 100}; // res = 11

    deque<int> left_max;
    left_max.push_back(hist[0]);
    for (int i = 1; i < hist.size(); ++i)
        left_max.push_back(max(hist[i], left_max.back()));

    deque<int> right_max;
    right_max.push_front(hist[hist.size()-1]);
    for (int i = hist.size() - 2; i >= 0; --i)
        right_max.push_front(max(hist[i], right_max.front()));
    
    int sum = 0;
    for (int i = 0; i < hist.size(); ++i)
        sum += min(left_max[i] - hist[i], right_max[i] - hist[i]);
    
    cout << "Amount of water retained: " << sum << endl;
}