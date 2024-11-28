#ifndef DESSERT_H
#define DESSERT_H

#include "Recipe.h"
#include <iostream>

class Dessert : public Recipe {
public:
    void prepareIngredients() override {
        ingredients = "Harina, azúcar, chocolate";
        cout << "Preparando ingredientes para Dessert" << endl;
    }
    void cook() override {
        cout << "Cocinando Dessert" << endl;
    }
    void showRecipe() override {
        name = "Dessert";
        cout << "Receta: " << name << endl;
        cout << "Ingredientes: " << ingredients << endl;
    }
};

#endif // DESSERT_H
