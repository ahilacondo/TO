#ifndef PASTA_H
#define PASTA_H

#include "Recipe.h"
#include <iostream>

class Pasta : public Recipe {
public:
    void prepareIngredients() override {
        ingredients = "Pasta, tomate, queso";
        cout << "Preparando ingredientes para Pasta" << endl;
    }
    void cook() override {
        cout << "Cocinando Pasta" << endl;
    }
    void showRecipe() override {
        name = "Pasta";
        cout << "Receta: " << name << endl;
        cout << "Ingredientes: " << ingredients << endl;
    }
};

#endif // PASTA_H
