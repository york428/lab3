#ifndef __TARITHMETICEXPRESSION_H__
#define __TARITHMETICEXPRESSION_H__

#include <string>
#include <vector>
#include <map>
#include <cctype>
#include "Stack.h"

class TArithmeticExpression {
    std::string infix;
    std::string postfix;
    std::vector<char> lexem;
    std::map<char, int> priority;
    std::map<char, double> operands;

    void Parse() {
        for (char c : infix) {
            if (c != ' ') { // Игнорируем пробелы
                lexem.push_back(c);
            }
        }
    }

    void ToPostfix() {
        Parse();
        Stack<char> st(lexem.size() + 1); // Выделяем память с запасом

        for (char item : lexem) {
            if (std::isdigit(item) || std::isalpha(item)) {
                // Если это операнд (буква или цифра)
                operands.insert({ item, 0.0 });
                postfix += item;
            }
            else if (item == '(') {
                st.Push(item);
            }
            else if (item == ')') {
                while (!st.IsEmpty() && st.Top() != '(') {
                    postfix += st.Top();
                    st.Pop();
                }
                if (!st.IsEmpty() && st.Top() == '(') {
                    st.Pop(); // Удаляем '(' из стека
                }
            }
            else if (priority.find(item) != priority.end()) {
                // Если это оператор (+, -, *, /)
                while (!st.IsEmpty() && st.Top() != '(' && priority[item] <= priority[st.Top()]) {
                    postfix += st.Top();
                    st.Pop();
                }
                st.Push(item);
            }
        }

        // Выгружаем оставшиеся операторы
        while (!st.IsEmpty()) {
            postfix += st.Top();
            st.Pop();
        }
    }

public:
    TArithmeticExpression(std::string str_infix) {
        infix = str_infix;
        priority = { { '+', 1 },{ '-', 1 },{ '*', 2 },{ '/', 2 } };
        ToPostfix();
    }

    std::vector<char> GetOperands() const {
        std::vector<char> op;
        for (const auto& item : operands) {
            op.push_back(item.first);
        }
        return op;
    }

    std::string GetInfix() const {
        return infix;
    }

    std::string GetPostfix() const {
        return postfix;
    }

    double Calculate(const std::map<char, double>& values) {
        // Обновляем значения операндов
        for (const auto& val : values) {
            if (operands.find(val.first) != operands.end()) {
                operands[val.first] = val.second;
            }
        }

        Stack<double> st(postfix.size() + 1);

        for (char lexemChar : postfix) {
            // Если символ является оператором
            if (priority.find(lexemChar) != priority.end()) {
                double right = st.Top(); st.Pop();
                double left = st.Top(); st.Pop();

                switch (lexemChar) {
                case '+': st.Push(left + right); break;
                case '-': st.Push(left - right); break;
                case '*': st.Push(left * right); break;
                case '/': st.Push(left / right); break;
                }
            }
            else {
                // Если символ является операндом
                st.Push(operands[lexemChar]);
            }
        }
        return st.Top();
    }
};

#endif