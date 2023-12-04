#include <iostream>
#include <cmath>
#include <stdexcept>
#include <Windows.h>
// Варіант без специфікації виключень
double calculateTriangleArea(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Сторони трикутника повинні бути додатні");
    }

    // Перевірка на умову існування трикутника
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("Трикутник із заданими сторонами не існує");
    }

    // Розрахунок площі за формулою Герона
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Варіант зі специфікацією throw();
double calculateTriangleAreaWithThrow(double a, double b, double c) throw(std::invalid_argument) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Сторони трикутника повинні бути додатні");
    }

    // Перевірка на умову існування трикутника
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("Трикутник із заданими сторонами не існує");
    }

    // Розрахунок площі за формулою Герона
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Варіант з конкретною специфікацією з відповідним стандартним виключенням
double calculateTriangleAreaWithStdException(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Сторони трикутника повинні бути додатні");
    }

    // Перевірка на умову існування трикутника
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::domain_error("Трикутник із заданими сторонами не існує");
    }

    // Розрахунок площі за формулою Герона
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Варіант із власним реалізованим виключенням
class TriangleException : public std::exception {
private:
    std::string message;

public:
    TriangleException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

double calculateTriangleAreaWithCustomException(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw TriangleException("Сторони трикутника повинні бути додатні");
    }

    // Перевірка на умову існування трикутника
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw TriangleException("Трикутник із заданими сторонами не існує");
    }

    // Розрахунок площі за формулою Герона
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Функція для обробки всіх перехоплених виключень
void handleExceptions(double a, double b, double c) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Без специфікації виключень" << std::endl;
    try {
        // Виклик функції без специфікації виключень
        std::cout << "Площа трикутника: " << calculateTriangleArea(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Зі специфікацією throw()" << std::endl;
    try {
        // Виклик функції зі специфікацією throw()
        std::cout << "Площа трикутника: " << calculateTriangleAreaWithThrow(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "З конкретною специфікацією з відповідним стандартним виключенням" << std::endl;
    try {
        // Виклик функції з конкретною специфікацією з відповідним стандартним виключенням
        std::cout << "Площа трикутника: " << calculateTriangleAreaWithStdException(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Із власним реалізованим виключенням" << std::endl;
    try {
        // Виклик функції із власним реалізованим виключенням
        std::cout << "Площа трикутника: " << calculateTriangleAreaWithCustomException(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    std::cout << "Введіть сторону a: ";
    std::cin >> a;

    std::cout << "Введіть сторону b: ";
    std::cin >> b;

    std::cout << "Введіть сторону c: ";
    std::cin >> c;
    std::cout << std::endl;

    // Виклик функції обробки виключень
    handleExceptions(a, b, c);

    return 0;
}