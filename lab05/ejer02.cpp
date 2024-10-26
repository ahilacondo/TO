#include <iostream>
using namespace std;

template <class T>
class Contenedor {
    T elemento;
public:
    Contenedor(T arg) : elemento(arg) {}  // Constructor que inicializa 'elemento' con 'arg'

    T add() { 
        return ++elemento;  // Incrementa 'elemento' y lo retorna
    }
};

// Especialización de la plantilla de clase Contenedor para el tipo 'char'
template <>
class Contenedor<char> {
    char elemento;
public:
    Contenedor(char arg) : elemento(arg) {}  // Constructor que inicializa 'elemento' con 'arg'

    char uppercase() {
        if (elemento >= 'a' && elemento <= 'z') {  // Convierte a mayúscula si es minúscula
            elemento -= ('a' - 'A');
        }
        return elemento;
    }
};

int main() {
    Contenedor<int> cint(5);     // Crea un contenedor de tipo int con valor inicial 5
    Contenedor<char> cchar('t'); // Crea un contenedor de tipo char con valor inicial 't'

    cout << cint.add() << endl;          // Incrementa el valor de cint y lo imprime
    cout << cchar.uppercase() << endl;   // Convierte a mayúscula y lo imprime
    return 0;
}
