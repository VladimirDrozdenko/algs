#include <iostream>
#include "simple_stack.h"
using namespace std;

int main() {
    
    SimpleStack<int> stack;

    try
    {
        for (int i = 0; i < stack.GetCapacity(); ++i) {
            stack.Push(i);
        }    
    }
    catch(const std::out_of_range& e)
    {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    cout << stack << endl;
    return EXIT_SUCCESS;
}