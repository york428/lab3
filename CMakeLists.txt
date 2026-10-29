cmake_minimum_required(VERSION 3.14)
project(ArithmeticParser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Скачиваем и подключаем Google Test ---
include(FetchContent)

# Эта строка нужна, чтобы VS не выдавал ошибку линковки (MDd/MTd)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# --- 2. Сборка основной программы И тестов ВМЕСТЕ ---
# Обрати внимание: здесь два файла .cpp
add_executable(ArithmeticApp src/main.cpp tests/tests.cpp)

# Указываем, где искать заголовочные файлы
target_include_directories(ArithmeticApp PRIVATE include)

# ВАЖНО: Линкуем GTest::gtest (без _main, так как main() мы написали сами)
target_link_libraries(ArithmeticApp PRIVATE GTest::gtest)

# --- 3. Регистрация тестов (опционально) ---
include(GoogleTest)
gtest_discover_tests(ArithmeticApp DISCOVERY_MODE PRE_TEST)