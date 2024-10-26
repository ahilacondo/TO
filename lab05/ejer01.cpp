#include <iostream>
#include <string>

template<typename T>
class ListaEnlazada {
private:
    // Estructura del nodo
    struct Nodo {
        T dato;
        Nodo* siguiente;
        
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };
    
    Nodo* cabeza;
    int tamano;

public:
    // Constructor
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}
    
    // Destructor
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    // Insertar al inicio
    void insertarInicio(const T& valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        tamano++;
    }
    
    // Insertar al final
    void insertarFinal(const T& valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
        tamano++;
    }
    
    // Eliminar primer elemento
    void eliminarInicio() {
        if (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamano--;
        }
    }
    
    // Obtener tamaño de la lista
    int getTamano() const {
        return tamano;
    }
    
    // Verificar si la lista está vacía
    bool estaVacia() const {
        return cabeza == nullptr;
    }
    
    // Imprimir lista
    void imprimir() const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
    
    // Buscar un elemento
    bool buscar(const T& valor) const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }
};

int main() {
    // Lista de edades
    ListaEnlazada<int> listaEdades;
    listaEdades.insertarFinal(25);
    listaEdades.insertarFinal(30);
    listaEdades.insertarFinal(35);
    
    std::cout << "Lista de edades: ";
    listaEdades.imprimir();
    
    // Lista de palabras
    ListaEnlazada<std::string> listaPalabras;
    listaPalabras.insertarFinal("Hola");
    listaPalabras.insertarFinal("Mundo");
    listaPalabras.insertarFinal("C++");
    
    std::cout << "Lista de palabras: ";
    listaPalabras.imprimir();
    
    return 0;
}