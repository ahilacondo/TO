#include "rectangulo.h"

int main(int argc, char const *argv[]) {

    Rectangulo* x = new Rectangulo(); // Calls the default constructor
    std::cout << "Dibujar(): \n";
    x->Dibujar();

    Rectangulo* y = new Rectangulo(30, 5); // Calls the parameterized constructor
    std::cout << "Dibujar (30, 5): \n";
    y->Dibujar();

    std::cout << "Dibujar (40, 2): \n";
    x->Dibujar(40, 2);

    Rectangulo* obj1 = new Rectangulo(*x); // Calls the copy constructor
    obj1->Dibujar();

    Rectangulo* obj2 = new Rectangulo(*y); // Calls the copy constructor
    obj2->Dibujar();

    // Destructor is called for all objects
    delete x;
    delete y;
    delete obj1;
    delete obj2;
    
    return 0;
}
