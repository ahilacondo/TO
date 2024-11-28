#include <iostream>
#include <string>
#include "ToyFactory.cpp"
using namespace std;

int main() {
    int type;
    while (true) {
        cout << endl << "Ingresa un tipo (1 a 3) o '0' para salir: ";
        cin >> type;
        if (type == 0) {
            break;
        }
        Toy *v = ToyFactory::createToy(type);
        if (v) {
            v->showProduct();
            delete v; // Liberar memoria
        }
    }
    cout << "Saliendo..." << endl;
    return 0;
}
