#include <iostream>
#include "Object.cpp"
using namespace std;

class ToyFactory {
public:
    static Toy *createToy(int type) {
        Toy *toy = nullptr;
        switch (type) {
            case 1: {
                toy = new Car;
                break;
            }
            case 2: {
                toy = new Bike;
                break;
            }
            case 3: {
                toy = new Plane;
                break;
            }
            default: {
                cout << "Tipo de juguete inválido, ingresa otra opción" << endl;
                return nullptr;
            }
        }
        toy->prepareParts();
        toy->combineParts();
        toy->assembleParts();
        toy->applyLabel();
        return toy;
    }
};
