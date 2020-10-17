#ifndef ___MY_SIMPLE_STACK_H___
#define ___MY_SIMPLE_STACK_H___

#include <iostream>
#include <stdexcept>

template <typename T, int SIZE = 10>
class SimpleStack {

    T* array;
    int top;
    int count;

public:
    SimpleStack() {
        static_assert(SIZE > 0);
        array = new T[SIZE];
        top = -1;
        count = 0;
    }

    int GetCapacity() const {
        return SIZE;
    }

    const T& Top() const {
        if (count > 0) {
            return array[top];
        }
        throw std::out_of_range("Stack is empty.");
    }

    void Push(const T& element) {
        if (count == SIZE) {
            throw std::out_of_range("Stack is full.");
        }

        array[++top] = element;
        ++count;
    }

    void Pop() {
        if (count == 0) {
            throw std::out_of_range("Stack is empty.");
        }

        --top;
        --count;
    }

    friend std::ostream& operator << (std::ostream& os, const SimpleStack<T, SIZE>& stack) {
        for (int i = stack.top; i >= 0; --i) {
            os << stack.array[i] << " ";
        }
        return os;
    }
};

#endif //___MY_SIMPLE_STACK_H___
