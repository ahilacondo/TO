#pragma once
#include "CheckBox.h"

// CheckBox de Windows
class WinCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Windows" << std::endl;
    }
};
