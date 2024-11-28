#pragma once
#include <iostream>

// Interfaz para los CheckBox
class CheckBox {
public:
    virtual ~CheckBox() {}
    virtual void Draw() const = 0;
};
