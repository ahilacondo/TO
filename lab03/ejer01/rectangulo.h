#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <iostream>
#include <memory>
typedef unsigned short int USHORT;
using namespace std;

class Rectangulo {
private:
    unique_ptr<USHORT> miancho;
    unique_ptr<USHORT> mialto;
    unique_ptr<int> val1, val2, val3;

public:
    Rectangulo();
    Rectangulo(USHORT ancho, USHORT alto);
    Rectangulo(const Rectangulo& R);    
    //~Rectangulo() {}

    void Dibujar();
    void Dibujar(USHORT xancho, USHORT xalto);
};

#endif

