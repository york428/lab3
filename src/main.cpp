#include <iostream>
#include <clocale>
#include <gtest/gtest.h> // Подключаем GTest
#include "TArithmetic.h"

// Твой обычный код программы (например, демонстрация работы)
void RunMyProgram() {
    TArithmeticExpression expr("(a+b)*c");
    std::map<char, double> vars = { { 'a', 2.0 },{ 'b', 3.0 },{ 'c', 4.0 } };
    std::cout << "Result of (a+b)*c: " << expr.Calculate(vars) << std::endl;
}

// Главная функция
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== ЗАПУСК ОСНОВНОЙ ПРОГРАММЫ ===" << std::endl;
    RunMyProgram(); // Вызов твоей логики

    std::cout << "\n=== ЗАПУСК ТЕСТОВ ===" << std::endl;
    // Инициализируем GTest
    ::testing::InitGoogleTest(&argc, argv);

    // Запускаем все тесты, которые найдены в проекте
    return RUN_ALL_TESTS();
}