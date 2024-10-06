#include "rectangulo.h"
#include <memory>
using namespace std;

int main(int argc, char const *argv[]) {
    unique_ptr<Rectangulo> x = make_unique<Rectangulo>();
    std::cout << "Dibujar(): \n";
    x->Dibujar();

    unique_ptr<Rectangulo> y = make_unique<Rectangulo>(30, 5);
    std::cout << "Dibujar (30, 5): \n";
    y->Dibujar();

    std::cout << "Dibujar (40, 2): \n";
    x->Dibujar(40, 2);

    unique_ptr<Rectangulo> obj1 = make_unique<Rectangulo>(*x);
    obj1->Dibujar();

    unique_ptr<Rectangulo> obj2 = make_unique<Rectangulo>(*y);
    obj2->Dibujar();

    // Destructor is called for all objects
    //delete x;
    //delete y;
    //delete obj1;
    //delete obj2;

    return 0;
}
