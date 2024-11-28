#include <iostream>
#include <string>

// Interfaces abstractas para la fábrica y productos
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual class AbstractProductoA* CrearProductoA() const = 0;
    virtual class AbstractProductoB* CrearProductoB() const = 0;
};

class AbstractProductoA {
public:
    virtual ~AbstractProductoA() {}
    virtual std::string Funcion1_A() const = 0;
};

class AbstractProductoB {
public:
    virtual ~AbstractProductoB() {}
    virtual std::string Funcion1_B() const = 0;
    virtual std::string Funcion2_B(const AbstractProductoA& colaborador) const = 0;
};

// Implementaciones de ProductoA
class CProductoA1 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override { return "Producto A1."; }
};

class CProductoA2 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override { return "Producto A2."; }
};

// Implementaciones de ProductoB
class CProductoB1 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override { return "Producto B1."; }
    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        return "B1 con ayuda de " + colaborador.Funcion1_A();
    }
};

class CProductoB2 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override { return "Producto B2."; }
    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        return "B2 con ayuda de " + colaborador.Funcion1_A();
    }
};

// Implementaciones de Fábrica
class CFactory1 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override { return new CProductoA1(); }
    AbstractProductoB* CrearProductoB() const override { return new CProductoB1(); }
};

class CFactory2 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override { return new CProductoA2(); }
    AbstractProductoB* CrearProductoB() const override { return new CProductoB2(); }
};

// Cliente
void Cliente(const AbstractFactory& factory) {
    const AbstractProductoA* producto_a = factory.CrearProductoA();
    const AbstractProductoB* producto_b = factory.CrearProductoB();

    std::cout << producto_b->Funcion1_B() << "\n";
    std::cout << producto_b->Funcion2_B(*producto_a) << "\n";

    delete producto_a;
    delete producto_b;
}

int main() {
    std::cout << "Cliente: Tipo 1\n";
    CFactory1* f1 = new CFactory1();
    Cliente(*f1);
    delete f1;

    std::cout << "\nCliente: Tipo 2\n";
    CFactory2* f2 = new CFactory2();
    Cliente(*f2);
    delete f2;

    return 0;
}
