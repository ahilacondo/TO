#include "rectangulo.h"
#include <memory>

// Default constructor
Rectangulo::Rectangulo() {
    cout << "Constructor por defecto\n";
    miancho = new USHORT(10);
    mialto = new USHORT(2);
    val1 = new int(0); 
    val2 = new int(0); 
    val3 = new int(0);
}

// Parameterized constructor
Rectangulo::Rectangulo(USHORT ancho, USHORT alto) {
    cout << "Constructor normal\n";
    miancho = new USHORT(ancho); 
    mialto = new USHORT(alto);  
    val1 = new int(0); 
    val2 = new int(0); 
    val3 = new int(0);
}

// Copy constructor
Rectangulo::Rectangulo(const Rectangulo& F) {
    cout << "Constructor copia\n";
    miancho = new USHORT(*(F.miancho));
    mialto = new USHORT(*(F.mialto));
    val1 = new int(*(F.val1));
    val2 = new int(*(F.val2));
    val3 = new int(*(F.val3));
}

// Destructor
Rectangulo::~Rectangulo(){
    cout << "Destructor\n";
    delete miancho;
    delete mialto;
    delete val1;
    delete val2;
    delete val3;
}

// Function to draw the rectangle using member variables
void Rectangulo::Dibujar() {
    val1 = new int(1); 
    val2 = new int(4);
    val3 = new int(8);
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
