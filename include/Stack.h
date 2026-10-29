#ifndef __STACK_H__
#define __STACK_H__

#include <cstddef>
#include <stdexcept>

template <class T>
class Stack
{
private:
    int top;
    size_t sz;
    T* pMem;

public:
    Stack(size_t n = 1) : sz(n), top(-1), pMem(new T[n]) {}

    ~Stack() {
        delete[] pMem;
    }

    bool IsEmpty() const {
        return top == -1;
    }

    bool IsFull() const {
        return top == static_cast<int>(sz) - 1;
    }

    void Push(const T& val) {
        if (IsFull()) {
            throw std::overflow_error("Stack is full");
        }
        pMem[++top] = val;
    }

    void Pop() {
        if (IsEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        --top;
    }

    T Top() const {
        if (IsEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return pMem[top];
    }
};

#endif