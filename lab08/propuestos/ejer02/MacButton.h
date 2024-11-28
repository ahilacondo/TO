#pragma once
#include "Button.h"

// Botón de Mac
class MacButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Mac" << std::endl;
    }
};
