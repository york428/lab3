#include <gtest/gtest.h>
#include <map>
#include <vector>
#include <stdexcept>
#include "Stack.h"
#include "TArithmetic.h"

// ТЕСТ 1: Стек
TEST(StackTest, BasicOperationsAndExceptions) {
    Stack<int> stack(3);
    EXPECT_TRUE(stack.IsEmpty());
    stack.Push(10);
    stack.Push(20);
    EXPECT_EQ(stack.Top(), 20);
    stack.Pop();
    EXPECT_EQ(stack.Top(), 10);

    stack.Pop();
    EXPECT_THROW(stack.Pop(), std::underflow_error);
    EXPECT_THROW(stack.Top(), std::underflow_error);

    stack.Push(1); stack.Push(2); stack.Push(3);
    EXPECT_TRUE(stack.IsFull());
    EXPECT_THROW(stack.Push(4), std::overflow_error);
}

// ТЕСТ 2: Постфиксная запись
TEST(ArithmeticTest, ToPostfixConversion) {
    TArithmeticExpression expr1("a+b*c");
    EXPECT_EQ(expr1.GetPostfix(), "abc*+");

    TArithmeticExpression expr2("(a+b)*c");
    EXPECT_EQ(expr2.GetPostfix(), "ab+c*");
}

