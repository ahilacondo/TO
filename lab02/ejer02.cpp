#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo* anterior;
    
    Nodo(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoblementeEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int tamano;

public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr), tamano(0) {}

    void insertarAlFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacia()) {
            cabeza = cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
        tamano++;
    }

    void insertarAlInicio(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacia()) {
            cabeza = cola = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        tamano++;
    }

    void eliminar(T valor) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                if (actual->anterior) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                if (actual->siguiente) {
                    actual->siguiente->anterior = actual->anterior;
                } else {
                    cola = actual->anterior;
                }
                delete actual;
                tamano--;
                return;
            }
            actual = actual->siguiente;
        }
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    int obtenerTamano() const {
        return tamano;
    }

    void imprimir() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    ~ListaDoblementeEnlazada() {
        while (cabeza != nullptr) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// Ejemplo de uso
int main() {
    ListaDoblementeEnlazada<int> lista;  // Especificar el tipo de dato aquí
    int opcion, valor;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Agregar elemento al final\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a agregar: ";
                cin >> valor;
                lista.insertarAlFinal(valor);
                cout << valor << " agregado a la lista.\n";
                break;
            case 2:
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                cout << valor << " eliminado de la lista (si estaba presente).\n";
                break;
            case 3:
                cout << "Elementos en la lista: ";
                lista.imprimir();
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}