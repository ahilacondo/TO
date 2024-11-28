#pragma once
#include "Button.h"

// Botón de Windows
class WinButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Windows" << std::endl;
    }
};
