#include <iostream>
#include <string>
using namespace std;

// Clase base
class Toy {
protected:
    string name;
    float price;
public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
    virtual ~Toy() {} // Destructor virtual
};

// Clase Car
class Car : public Toy {
public:
    void prepareParts() override { cout << "Preparando partes de Car" << endl; }
    void combineParts() override { cout << "Combinando partes de Car" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Car" << endl; }
    void applyLabel() override { 
        name = "Car";
        price = 10.0; 
        cout << "Aplicando etiquetado de Car" << endl;
    }
    void showProduct() override {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

// Clase Bike
class Bike : public Toy {
public:
    void prepareParts() override { cout << "Preparando partes de Bike" << endl; }
    void combineParts() override { cout << "Combinando partes de Bike" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Bike" << endl; }
    void applyLabel() override { 
        name = "Bike";
        price = 20.0; 
        cout << "Aplicando etiquetado de Bike" << endl;
    }
    void showProduct() override {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

// Clase Plane
class Plane : public Toy {
public:
    void prepareParts() override { cout << "Preparando partes de Plane" << endl; }
    void combineParts() override { cout << "Combinando partes de Plane" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Plane" << endl; }
    void applyLabel() override { 
        name = "Plane";
        price = 30.0; 
        cout << "Aplicando etiquetado de Plane" << endl;
    }
    void showProduct() override {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};
