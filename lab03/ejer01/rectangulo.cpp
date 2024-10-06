#include "rectangulo.h"
#include <memory>

// Default constructor
Rectangulo::Rectangulo() 
    : miancho(std::make_unique<USHORT>(10)), 
      mialto(std::make_unique<USHORT>(2)), 
      val1(std::make_unique<int>(0)), 
      val2(std::make_unique<int>(0)), 
      val3(std::make_unique<int>(0)) {
    cout << "Constructor por defecto\n";
}

// Parameterized constructor
Rectangulo::Rectangulo(USHORT ancho, USHORT alto) 
    : miancho(std::make_unique<USHORT>(ancho)), 
      mialto(std::make_unique<USHORT>(alto)), 
      val1(std::make_unique<int>(0)), 
      val2(std::make_unique<int>(0)), 
      val3(std::make_unique<int>(0)) {
    cout << "Constructor normal\n";
}

// Copy constructor
Rectangulo::Rectangulo(const Rectangulo& F) 
    : miancho(std::make_unique<USHORT>(*F.miancho)), 
      mialto(std::make_unique<USHORT>(*F.mialto)), 
      val1(std::make_unique<int>(*F.val1)), 
      val2(std::make_unique<int>(*F.val2)), 
      val3(std::make_unique<int>(*F.val3)) {
    cout << "Constructor copia\n";
}

// Destructor
//Rectangulo::~Rectangulo(){
//    cout << "Destructor\n";
//    delete miancho;
//    delete mialto;
//    delete val1;
//    delete val2;
//    delete val3;
//}

// Function to draw the rectangle using member variables
void Rectangulo::Dibujar() {
    *val1 = 1; 
    *val2 = 4;
    *val3 = 8;
    Dibujar(*miancho, *mialto); // Use member variables
}

// Function to draw the rectangle with specified dimensions
void Rectangulo::Dibujar(USHORT ancho, USHORT alto) {
    for (USHORT i = 0; i < alto; i++) {
        for (USHORT j = 0; j < ancho; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
