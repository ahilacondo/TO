#include "RecipeFactory.h"
#include <iostream>

int main() {
    int type;
    while (true) {
        cout << endl << "Ingresa un tipo de receta (1: Pasta, 2: Dessert, 3: Soup) o '0' para salir: ";
        cin >> type;
        if (type == 0) {
            break;
        }
        Recipe* recipe = RecipeFactory::createRecipe(type);
        if (recipe) {
            recipe->showRecipe();
            delete recipe; // Liberar memoria
        }
    }
    cout << "Saliendo..." << endl;
    return 0;
}
