#ifndef NODO_H
#define NODO_H

#include <memory>
using namespace std;

class Nodo {
public:
    char valor;
    unique_ptr<Nodo> izquierda;
    unique_ptr<Nodo> derecha;

    Nodo(char valor);
};

#endif
