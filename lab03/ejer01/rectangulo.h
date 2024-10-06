#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <iostream>
typedef unsigned short int USHORT;
using namespace std;

class Rectangulo {
private:
    USHORT* miancho; 
    USHORT* mialto;
    int* val1,* val2,* val3; //temperatura, profundidad, color

public:
    Rectangulo();
    Rectangulo(USHORT ancho, USHORT alto);
    Rectangulo(const Rectangulo& R);    
    ~Rectangulo() {}

    void Dibujar();
    void Dibujar(USHORT xancho, USHORT xalto);
};

#endif

