#include "lista.h"

int main() {
    int arreglo[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const int longitud = sizeof(arreglo) / sizeof(*arreglo);

    Lista lista1; // Llama al constructor por defecto
    lista1.copiaArreglo(arreglo, longitud);
    
    cout << "Imprimir hacia adelante: ";
    lista1.imprimeAdelante();

    cout << "Imprimir hacia atrás: ";
    lista1.imprimeAtras();

    int valorBuscado = 5;
    Nodo* encontradoAdelante = lista1.buscarAdelante(valorBuscado);
    Nodo* encontradoAtras = lista1.buscarAtras(valorBuscado);
    
    if (encontradoAdelante) {
        cout << "Encontrado " << valorBuscado << " hacia adelante.\n";
    } else {
        cout << valorBuscado << " no encontrado hacia adelante.\n";
    }

    if (encontradoAtras) {
        cout << "Encontrado " << valorBuscado << " hacia atrás.\n";
    } else {
        cout << valorBuscado << " no encontrado hacia atrás.\n";
    }

    lista1.destruyeLista(); // Destruir la lista

    return 0;
}
