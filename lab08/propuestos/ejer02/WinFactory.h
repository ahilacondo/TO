#pragma once
#include "GUIFactory.h"
#include "WinButton.h"
#include "WinCheckBox.h"

// Fábrica de Windows
class WinFactory : public GUIFactory {
public:
    void CrearButton() const override {
        WinButton button;
        button.Draw();
    }

    void CrearCheckBox() const override {
        WinCheckBox checkbox;
        checkbox.Draw();
    }
};
