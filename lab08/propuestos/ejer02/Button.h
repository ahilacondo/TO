#pragma once
#include <iostream>

// Interfaz para los botones
class Button {
public:
    virtual ~Button() {}
    virtual void Draw() const = 0;
};
