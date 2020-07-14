#include <iostream>
#include <vector>
using namespace std;


int main() {

    const vector<int> a = {5, -6, 3, 4, -2, 3, -3};
    //const vector<int> a = {-11, -6, -2, -3};

    int sum = a[0];
    int max_sum = a[0];

    for (size_t i = 1; i < a.size(); ++i) {
        sum += a[i];
        if (max_sum < sum)
            max_sum = sum;

        if (sum < 0)
            sum = 0;
    }

    cout << max_sum << endl;
}