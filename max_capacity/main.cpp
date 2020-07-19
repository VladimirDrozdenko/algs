/*
N noxes: g[i]= weight of a box i.
Transport them using a truck with capacity C, in the order they are given. 
Sum of the weights of the boxes taken at each transport can't exceed C.
Find the minimum C such that we can move all boxes using maximum K transports.
*/

#include <iostream>
#include <vector>
using namespace std;

unsigned int getArrMax(const vector<unsigned int>& a) {
    unsigned int m = a[0];
    for (size_t i = 1; i < a.size(); ++i)
        m = max(m, a[i]);
    return m;
}

unsigned int getArrSum(const vector<unsigned int>& a) {
    unsigned int sum = a[0];
    for (size_t i = 1; i < a.size(); ++i)
        sum += a[i];
    return sum;
}

unsigned int getNumberOfRides(const vector<unsigned int>& a, const size_t truck_capacity) {
    size_t rides = 1;
    unsigned int capacity = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (capacity + a[i] <= truck_capacity) {
            capacity += a[i];
        } else {
            ++rides;
            capacity = a[i];
        }
    }
    return rides;
}

void bruteForceSolution(const vector<unsigned int>& a, size_t k) {
    const size_t n = a.size();

    unsigned int min_truck_capacity = getArrMax(a);
    unsigned int max_truck_capacity = getArrSum(a);
    
    for (size_t truck_capacity = min_truck_capacity; truck_capacity <= max_truck_capacity; ++truck_capacity) {

        size_t pos = 0; // array position
        for (size_t ride = 1; ride <= k; ++ride) {

            size_t cap = 0; // capacity for a given ride
            while (pos < n && cap + a[pos] <= truck_capacity) {
                cap += a[pos++];
            }

            if (pos == n) {
                cout << "Minimum truck capacity " << truck_capacity << endl;
                return;
            }
        }

        cout << "Capacity " << truck_capacity << " requires more than " << k << " rides." << endl;
    }
}

void nlognSolution(const vector<unsigned int>& a, size_t k) {

    size_t min_capacity_res = 0;
    size_t left_cap = getArrMax(a);
    size_t right_cap = getArrSum(a);

    while (left_cap <= right_cap) {
        size_t mid_cap = left_cap + (right_cap - left_cap)/2;

        size_t rides = getNumberOfRides(a, mid_cap);
        if (rides < k) {
            right_cap = mid_cap - 1;
        } else if (rides > k) {
            left_cap = mid_cap + 1;
        } else {
            min_capacity_res = mid_cap;
            right_cap = mid_cap - 1;
        }
    }

    cout << "*Minimum truck capacity " << min_capacity_res << endl;
}

int main() {
    
    const vector<unsigned int> a = {7, 3, 2, 3, 1, 4};
    const size_t k = 2;

    bruteForceSolution(a, k);

    nlognSolution(a, k);
}
