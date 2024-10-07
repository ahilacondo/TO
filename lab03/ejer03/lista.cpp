#include "lista.h"

// Constructores por defecto
Lista::Lista(): inicio(nullptr), fin(nullptr){
    cout << "constructor por defecto\n";
}

void Lista::copiaArreglo(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = arreglo[i];
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->anterior = fin;

        if (inicio == nullptr) {
            inicio = nuevoNodo; // Si es el primer nodo
        } else {
            fin->siguiente = nuevoNodo; // Enlaza el nodo anterior con el nuevo
        }

        fin = nuevoNodo; // Actualiza el último nodo
    }
}

void Lista::imprimeAdelante() {
    Nodo* iNodo = inicio;
    while (iNodo != nullptr) {
        cout << iNodo->valor << " "; 
        iNodo = iNodo->siguiente;
    }
    cout << endl;
}

void Lista::imprimeAtras() {
    Nodo* iNodo = fin; 
    while (iNodo != nullptr) {
        cout << iNodo->valor << " ";
        iNodo = iNodo->anterior; 
    }
    cout << endl;
}

Nodo* Lista::buscarAdelante(int valor) {
    Nodo* iNodo = inicio;
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return iNodo; 
        }
        iNodo = iNodo->siguiente;
    }
    return nullptr;
}

Nodo* Lista::buscarAtras(int valor) {
    Nodo* iNodo = fin;
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return iNodo; 
        }
        iNodo = iNodo->anterior;
    }
    return nullptr; 
}

void Lista::destruyeLista() { 
    Nodo* iNodo = inicio; 
    while (iNodo != nullptr) {
        Nodo* auxNodo = iNodo;
        iNodo = iNodo->siguiente;
        delete auxNodo;
    }
    inicio = nullptr;
    fin = nullptr; 
}
