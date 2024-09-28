#include <iostream>

typedef unsigned short int USHORT;

int main() {
    USHORT myAge;
    USHORT* pAge = 0;

    myAge = 5;
    std::cout << "myAge: " << myAge << "\n";
    std::cout << "pAge: " << pAge << "\n";

    pAge = &myAge;
    std::cout << "*pAge: " << *pAge << "\n";
    std::cout << "pAge: " << pAge << "\n\n";

    std::cout << "Asignar nuevo valor al puntero\n";
    *pAge = 7;

    std::cout << "*pAge: " << *pAge << "\n";
    std::cout << "myAge: " << myAge << "\n";
    std::cout << "pAge: " << pAge << "\n\n";

    std::cout << "Asignar nuevo valor al puntero\n";
    myAge = 9;

    std::cout << "myAge: " << myAge << "\n";
    std::cout << "*pAge: " << *pAge << "\n";
    std::cout << "pAge: " << pAge << "\n";

    return 0;
}
