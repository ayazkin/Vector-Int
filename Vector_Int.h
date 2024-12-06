#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

class Vector_Int {
private:
    int size;
    int* mas;

public:
    Vector_Int() : size(0), mas(nullptr) {} // задаю параметры через список конструктора. ƒо выполнени€ тела.

    Vector_Int(int s);

    Vector_Int(const Vector_Int& other);

    Vector_Int& operator=(const Vector_Int& other);

    ~Vector_Int() { /////////////
        delete[] mas;
    }

    int& operator[](int index);

    // ќператор делени€ на некоторое число
    Vector_Int operator/(int number) const;

    int dotProduct(const Vector_Int& other) const;

    Vector_Int operator+(const Vector_Int& other) const;

    friend istream& operator>>(istream& in, Vector_Int& v);

    friend ostream& operator<<(ostream& out, const Vector_Int& v);

    int getSize() const {
        return size;
    }

    void print() const;
};