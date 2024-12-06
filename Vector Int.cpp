#include <iostream>
#include <fstream>
#include "Vector_Int.h"

using namespace std;

int main() {
    Vector_Int v1(5);
    for (int i = 0; i < v1.getSize(); ++i) {
        v1[i] = i + 1;  // перегрузка индекса
    }

    Vector_Int v2(5);
    std::cin >> v2;  

    std::cout << "Vector_Int 1: " << v1 << std::endl;
    std::cout << "Vector_Int 2: " << v2 << std::endl;


    Vector_Int v3 = v1 + v2;
    cout << "v1 + v2: " << v3 << std::endl;

    int dot = v1.dotProduct(v2);
    cout << "Dot product of v1 and v2: " << dot << std::endl;

    Vector_Int v5 = v1 / 2;
    cout << "v1 / 2: " << v5 << std::endl;

    return 0;
}
