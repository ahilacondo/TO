#pragma once
#include "GUIFactory.h"

// Clase Application que utiliza la fábrica
class Application {
private:
    const GUIFactory& factory;

public:
    Application(const GUIFactory& f) : factory(f) {}

    void CrearInterfaz() {
        factory.CrearButton();
        factory.CrearCheckBox();
    }
};
