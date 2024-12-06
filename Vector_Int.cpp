#include "Vector_Int.h"

Vector_Int::Vector_Int(int s) : size(s) {
        mas = new int[size];  
        for (int i = 0; i < size; ++i) {
            mas[i] = 0;  
        }
    }

Vector_Int::Vector_Int(const Vector_Int& other) : size(other.size) {
        mas = new int[size];
        for (int i = 0; i < size; ++i) {
            mas[i] = other.mas[i];
        }
    }

    Vector_Int& Vector_Int::operator=(const Vector_Int& other) {
        if (this != &other) {
            delete[] mas;  // Освобождаем старую память
            size = other.size;
            mas = new int[size];
            for (int i = 0; i < size; ++i) {
                mas[i] = other.mas[i];
            }
        }
        return *this;
    }

    int& Vector_Int::operator[](int index) {
        if (index >= 0 && index < size) {
            return mas[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Оператор деления на некоторое число
    Vector_Int Vector_Int::operator/(int number) const {
        if (number == 0) {
            throw invalid_argument("Division by zero");
        }
        Vector_Int result(size);
        for (int i = 0; i < size; ++i) {
            result.mas[i] = mas[i] / number;
        }
        return result;
    }

    int Vector_Int::dotProduct(const Vector_Int& other) const {
        if (size != other.size) {
            throw invalid_argument("Vector_Ints must have the same size for dot product");
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result += mas[i] * other.mas[i];
        }
        return result;
    }

    Vector_Int Vector_Int::operator+(const Vector_Int& other) const { // покомпонетно
        if (size != other.size) {
            throw invalid_argument("Vector_Ints must have the same size for addition");
        }
        Vector_Int result(size);
        for (int i = 0; i < size; ++i) {
            result.mas[i] = mas[i] + other.mas[i];
        }
        return result;
    }

     istream& operator>>(istream& in, Vector_Int& v) {
        for (int i = 0; i < v.size; ++i) {
            in >> v.mas[i];
        }
        return in;
    }


    ostream& operator<<(ostream& out, const Vector_Int& v) {
        for (int i = 0; i < v.size; ++i) {
            out << v.mas[i] << " ";
        }
        return out;
    }

    void Vector_Int::print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << mas[i] << " ";
        }
        std::cout << std::endl;
    }