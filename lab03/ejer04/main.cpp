#include <iostream>
#include <string>
#include "Funciones.h"
#include "Nodo.h"

int main() {
    string i;
    cout << "Ingrese una expresion matematica (solo numeros y operadores +, -, *, /): ";
    cin >> i;

    string expresionPostfix = infijaAPostfija(i);

    try {
        unique_ptr<Nodo> raiz = construirArbol(expresionPostfix);

        cout << "Resultado de la expresion: " << evaluar(raiz) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
