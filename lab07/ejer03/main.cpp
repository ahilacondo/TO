#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

// Clase Producto
class Auto {
public:
    string modelo;
    string motor;
    string color;
    string pais;
    vector<string> componentes;

    void mostrarEspecificaciones() const {
        cout << "Especificaciones del Auto:\n";
        cout << "Modelo: " << modelo << "\n";
        cout << "Motor: " << motor << "\n";
        cout << "Color: " << color << "\n";
        cout << "País: " << pais << "\n";
        cout << "Componentes: ";
        for (const auto& componente : componentes) {
            cout << componente << " ";
        }
        cout << "\n";
    }
};

// Interfaz Builder
class IBuilder {
public:
    virtual ~IBuilder() = default;
    virtual void establecerModelo(const string& modelo) = 0;
    virtual void establecerMotor(const string& motor) = 0;
    virtual void establecerColor(const string& color) = 0;
    virtual void establecerPais(const string& pais) = 0;
    virtual void agregarComponente(const string& componente) = 0;
    virtual shared_ptr<Auto> obtenerAuto() = 0;
};

// Builder Concreto
class ConstructorAuto : public IBuilder {
private:
    shared_ptr<Auto> autoConstruido;
public:
    ConstructorAuto() { reiniciar(); }
    void reiniciar() { autoConstruido = make_shared<Auto>(); }
    void establecerModelo(const string& modelo) override { autoConstruido->modelo = modelo; }
    void establecerMotor(const string& motor) override { autoConstruido->motor = motor; }
    void establecerColor(const string& color) override { autoConstruido->color = color; }
    void establecerPais(const string& pais) override { autoConstruido->pais = pais; }
    void agregarComponente(const string& componente) override { autoConstruido->componentes.push_back(componente); }
    shared_ptr<Auto> obtenerAuto() override {
        auto resultado = autoConstruido;
        reiniciar();
        return resultado;
    }
};

// Director
class Director {
private:
    shared_ptr<IBuilder> builder;
public:
    void asignarBuilder(const shared_ptr<IBuilder>& nuevoBuilder) { builder = nuevoBuilder; }

    void construirAutoDeportivo() {
        builder->establecerModelo("Auto Deportivo");
        builder->establecerMotor("V8");
        builder->establecerColor("Rojo");
        builder->establecerPais("Italia");
        builder->agregarComponente("Puertas");
        builder->agregarComponente("Llantas");
        builder->agregarComponente("Timón");
    }

    void construirSUV() {
        builder->establecerModelo("SUV");
        builder->establecerMotor("V6");
        builder->establecerColor("Negro");
        builder->establecerPais("EEUU");
        builder->agregarComponente("Puertas");
        builder->agregarComponente("Llantas");
        builder->agregarComponente("Timón");
        builder->agregarComponente("Techo solar");
    }
};

// Código del Cliente
int main() {
    shared_ptr<ConstructorAuto> constructor = make_shared<ConstructorAuto>();
    Director director;
    director.asignarBuilder(constructor);

    // Construir un auto deportivo
    director.construirAutoDeportivo();
    shared_ptr<Auto> autoDeportivo = constructor->obtenerAuto();
    autoDeportivo->mostrarEspecificaciones();

    // Construir un SUV
    director.construirSUV();
    shared_ptr<Auto> suv = constructor->obtenerAuto();
    suv->mostrarEspecificaciones();

    // Construir un auto personalizado
    constructor->establecerModelo("Auto Personalizado");
    constructor->establecerMotor("Eléctrico");
    constructor->establecerColor("Azul");
    constructor->establecerPais("Alemania");
    constructor->agregarComponente("Puertas");
    constructor->agregarComponente("Llantas");
    constructor->agregarComponente("Timón");
    constructor->agregarComponente("Autopiloto");
    shared_ptr<Auto> autoPersonalizado = constructor->obtenerAuto();
    autoPersonalizado->mostrarEspecificaciones();

    return 0;
}
