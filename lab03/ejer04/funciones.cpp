#include "Funciones.h"
#include "Nodo.h"

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prioridad(char operador) {
    if (operador == '*' || operador == '/') return 2;
    if (operador == '+' || operador == '-') return 1;
    return 0;
}

string infijaAPostfija(const string& expresion) {
    stack<char> operadores;
    string postfija;

    for (char c : expresion) {
        if (isdigit(c)) {
            postfija += c; // Si es un número, lo añadimos directamente
        } else if (esOperador(c)) {
            // Desapilar operadores de mayor o igual precedencia y añadirlos a la expresión postfija
            while (!operadores.empty() && prioridad(operadores.top()) >= prioridad(c)) {
                postfija += operadores.top();
                operadores.pop();
            }
            operadores.push(c);
        }
    }

    while (!operadores.empty()) {
        postfija += operadores.top();
        operadores.pop();
    }

    return postfija;
}

unique_ptr<Nodo> construirArbol(const string& expresionPostfix) {
    stack<unique_ptr<Nodo>> pila;

    for (char c : expresionPostfix) {
        if (isdigit(c)) {
            pila.push(make_unique<Nodo>(c));
        }
        else if (esOperador(c)) {
            auto nuevoNodo = make_unique<Nodo>(c);

            nuevoNodo->derecha = move(pila.top());
            pila.pop();
            nuevoNodo->izquierda = move(pila.top());
            pila.pop();

            pila.push(move(nuevoNodo));
        }
    }

    return move(pila.top());
}

int evaluar(const unique_ptr<Nodo>& raiz) {
    if (!raiz) return 0;

    if (!esOperador(raiz->valor)) {
        return raiz->valor - '0'; 
    }

    int izquierda = evaluar(raiz->izquierda);
    int derecha = evaluar(raiz->derecha);

    switch (raiz->valor) {
        case '+':
            return izquierda + derecha;
        case '-':
            return izquierda - derecha;
        case '*':
            return izquierda * derecha;
        case '/':
            if (derecha == 0) throw invalid_argument("Error: División por cero.");
            return izquierda / derecha;
        default:
            throw invalid_argument("Operador no soportado.");
    }
}
