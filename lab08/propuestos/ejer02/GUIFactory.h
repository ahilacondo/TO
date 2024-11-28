#pragma once
#include <iostream>

// Interfaz para la fábrica abstracta
class GUIFactory {
public:
    virtual ~GUIFactory() {}
    virtual void CrearButton() const = 0;
    virtual void CrearCheckBox() const = 0;
};
