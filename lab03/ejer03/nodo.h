#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente; //siguiente
    Nodo* anterior; //anterior
    ~Nodo() {
        cout << "\nNodo eliminado " << valor;
    }
};

#endif