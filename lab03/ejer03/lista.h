#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {
public:
    Lista();
    void copiaArreglo(int arreglo[], int size);
    void imprimeAdelante();
    void imprimeAtras();
    Nodo* buscarAdelante(int valor);
    Nodo* buscarAtras(int valor);
    void destruyeLista();
    ~Lista() {}

private:
    Nodo* inicio; // Puntero al primer nodo
    Nodo* fin;    // Puntero al último nodo
};

#endif
