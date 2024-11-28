#ifndef RECIPE_H
#define RECIPE_H

#include <string>
using namespace std;

class Recipe {
protected:
    string name;
    string ingredients;
public:
    virtual void prepareIngredients() = 0;
    virtual void cook() = 0;
    virtual void showRecipe() = 0;
    virtual ~Recipe() {}
};

#endif // RECIPE_H
