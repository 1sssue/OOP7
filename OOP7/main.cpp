#include <iostream>
#include <cmath>
#include <stdexcept>
#include <Windows.h>
// ������ ��� ������������ ���������
double calculateTriangleArea(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("������� ���������� ������ ���� ������");
    }

    // �������� �� ����� ��������� ����������
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("��������� �� �������� ��������� �� ����");
    }

    // ���������� ����� �� �������� ������
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ������ � ������������� throw();
double calculateTriangleAreaWithThrow(double a, double b, double c) throw(std::invalid_argument) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("������� ���������� ������ ���� ������");
    }

    // �������� �� ����� ��������� ����������
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("��������� �� �������� ��������� �� ����");
    }

    // ���������� ����� �� �������� ������
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ������ � ���������� ������������� � ��������� ����������� �����������
double calculateTriangleAreaWithStdException(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("������� ���������� ������ ���� ������");
    }

    // �������� �� ����� ��������� ����������
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::domain_error("��������� �� �������� ��������� �� ����");
    }

    // ���������� ����� �� �������� ������
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ������ �� ������� ����������� �����������
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
        throw TriangleException("������� ���������� ������ ���� ������");
    }

    // �������� �� ����� ��������� ����������
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw TriangleException("��������� �� �������� ��������� �� ����");
    }

    // ���������� ����� �� �������� ������
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ������� ��� ������� ��� ������������ ���������
void handleExceptions(double a, double b, double c) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "��� ������������ ���������" << std::endl;
    try {
        // ������ ������� ��� ������������ ���������
        std::cout << "����� ����������: " << calculateTriangleArea(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "ǳ ������������� throw()" << std::endl;
    try {
        // ������ ������� � ������������� throw()
        std::cout << "����� ����������: " << calculateTriangleAreaWithThrow(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "� ���������� ������������� � ��������� ����������� �����������" << std::endl;
    try {
        // ������ ������� � ���������� ������������� � ��������� ����������� �����������
        std::cout << "����� ����������: " << calculateTriangleAreaWithStdException(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "�� ������� ����������� �����������" << std::endl;
    try {
        // ������ ������� �� ������� ����������� �����������
        std::cout << "����� ����������: " << calculateTriangleAreaWithCustomException(a, b, c) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "�������: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, c;

    std::cout << "������ ������� a: ";
    std::cin >> a;

    std::cout << "������ ������� b: ";
    std::cin >> b;

    std::cout << "������ ������� c: ";
    std::cin >> c;
    std::cout << std::endl;

    // ������ ������� ������� ���������
    handleExceptions(a, b, c);

    return 0;
}