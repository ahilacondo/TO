#pragma once
#include "CheckBox.h"

// CheckBox de Mac
class MacCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Mac" << std::endl;
    }
};
