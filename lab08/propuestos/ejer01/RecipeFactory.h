#ifndef RECIPEFACTORY_H
#define RECIPEFACTORY_H

#include "Pasta.h"
#include "Dessert.h"
#include "Soup.h"
#include <iostream>

class RecipeFactory {
public:
    static Recipe* createRecipe(int type) {
        Recipe* recipe = nullptr;
        switch (type) {
            case 1: recipe = new Pasta; break;
            case 2: recipe = new Dessert; break;
            case 3: recipe = new Soup; break;
            default:
                cout << "Tipo de receta inválido, ingresa otra opción" << endl;
                return nullptr;
        }
        recipe->prepareIngredients();
        recipe->cook();
        return recipe;
    }
};

#endif // RECIPEFACTORY_H
