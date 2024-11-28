#pragma once
#include "GUIFactory.h"
#include "MacButton.h"
#include "MacCheckBox.h"

// Fábrica de Mac
class MacFactory : public GUIFactory {
public:
    void CrearButton() const override {
        MacButton button;
        button.Draw();
    }

    void CrearCheckBox() const override {
        MacCheckBox checkbox;
        checkbox.Draw();
    }
};
