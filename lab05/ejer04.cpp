#include <iostream>
using namespace std;

template <class T, int MAX_SIZE = 10>
class Stack {
private:
    T elements[MAX_SIZE];  // Array para almacenar los elementos de la pila
    int topIndex;          // Índice del elemento superior de la pila

public:
    Stack() : topIndex(-1) {}  // Constructor, inicializa la pila vacía

    // Método para insertar un elemento en la pila
    bool push(T value) {
        if (topIndex >= MAX_SIZE - 1) {  // Verifica si la pila está llena
            cout << "Stack overflow\n";
            return false;
        }
        elements[++topIndex] = value;
        return true;
    }

    // Método para eliminar el elemento superior de la pila
    bool pop() {
        if (topIndex < 0) {  // Verifica si la pila está vacía
            cout << "Stack underflow\n";
            return false;
        }
        --topIndex;
        return true;
    }

    // Método para obtener el elemento superior de la pila sin eliminarlo
    T top() const {
        if (topIndex < 0) {
            cout << "Stack is empty\n";
            return T();  // Retorna un valor por defecto si la pila está vacía
        }
        return elements[topIndex];
    }

    // Método para verificar si la pila está vacía
    bool isEmpty() const {
        return topIndex < 0;
    }
};

int main() {
    Stack<int> pilaEnteros;    // Pila de enteros
    Stack<char> pilaCaracteres; // Pila de caracteres

    // Insertar y manipular elementos en la pila de enteros
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    cout << "Elemento superior de pilaEnteros: " << pilaEnteros.top() << endl;  // Debe imprimir 20
    pilaEnteros.pop();
    cout << "Elemento superior de pilaEnteros despues de pop: " << pilaEnteros.top() << endl;  // Debe imprimir 10

    // Insertar y manipular elementos en la pila de caracteres
    pilaCaracteres.push('A');
    pilaCaracteres.push('B');
    cout << "Elemento superior de pilaCaracteres: " << pilaCaracteres.top() << endl;  // Debe imprimir 'B'
    pilaCaracteres.pop();
    cout << "Elemento superior de pilaCaracteres despues de pop: " << pilaCaracteres.top() << endl;  // Debe imprimir 'A'

    return 0;
}

