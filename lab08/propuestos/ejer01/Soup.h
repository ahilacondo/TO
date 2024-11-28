#ifndef SOUP_H
#define SOUP_H

#include "Recipe.h"
#include <iostream>

class Soup : public Recipe {
public:
    void prepareIngredients() override {
        ingredients = "Verduras, pollo, especias";
        cout << "Preparando ingredientes para Soup" << endl;
    }
    void cook() override {
        cout << "Cocinando Soup" << endl;
    }
    void showRecipe() override {
        name = "Soup";
        cout << "Receta: " << name << endl;
        cout << "Ingredientes: " << ingredients << endl;
    }
};

#endif // SOUP_H
