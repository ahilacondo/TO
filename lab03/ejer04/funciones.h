#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "nodo.h"
#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <stdexcept>
using namespace std;

// Declaraciones de las funciones
bool esOperador(char c);
int prioridad(char operador);
string infijaAPostfija(const string& expresion);
unique_ptr<Nodo> construirArbol(const string& expresionPostfix);
int evaluar(const unique_ptr<Nodo>& raiz);

#endif
