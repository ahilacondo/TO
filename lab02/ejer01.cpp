#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// clase para analizar la operacion matematica
class Analizador{
    private:
        string operacion;
        
    public:
        Analizador(const string& operacion){
            this->operacion = operacion;
        } 

        vector<string> obtenerElementos() {
            vector<string> elementos;
            string elemento;

            for (char c : operacion) {
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    if (!elemento.empty()) {
                        elementos.push_back(elemento);
                        elemento.clear();
                    }
                    elementos.push_back(string(1, c)); // Agregar el operador
                } else {
                    elemento += c; // Acumular el operando
                }
            }

            if (!elemento.empty()) {
                elementos.push_back(elemento); // Agregar el último operando
            }

            return elementos;
        }
};

// clase para administrar la operacion matematica
class Calculadora{
    //por ahora no private
    public:
        double calcular(double a, double b, const string& operador) {
            if (operador == "+") return a + b;
            if (operador == "-") return a - b;
            if (operador == "*") return a * b;
            if (operador == "/") {
                if (b != 0) return a / b;
                throw invalid_argument("Cuidado!! Division por cero");
            }
            throw invalid_argument("Operador desconocido ¿?");
        }

    double evaluar(vector<string>& elementos) {
        // Primero * y /
        for (size_t i = 0; i < elementos.size(); i++) {
            if (elementos[i] == "*" || elementos[i] == "/") {
                double a = stod(elementos[i - 1]);
                double b = stod(elementos[i + 1]);
                double resultado = calcular(a, b, elementos[i]);
                
                // Reemplazar el operador y sus operandos en el vector
                elementos[i - 1] = to_string(resultado);
                elementos.erase(elementos.begin() + i, elementos.begin() + i + 2);
                i--; 
            }
        }

        // Luego + y -
        double resultado = stod(elementos[0]);
        for (size_t i = 1; i < elementos.size(); i += 2) {
            string operador = elementos[i];
            double siguiente = stod(elementos[i + 1]);
            resultado = calcular(resultado, siguiente, operador);
        }

        return resultado;
    }

};

// clase para procesar la operacion matematica
class Procesador{
    private:
        Analizador analizador;
        Calculadora calculadora;

    public:
        Procesador(const string& operacion) : analizador(operacion) {}

        double procesar() {
            vector<string> elementos = analizador.obtenerElementos();
            double resultado = stod(elementos[0]);

            if (elementos.size() < 3 || elementos.size() > 13) { //teniendo en cuenta lo que nos pide el ejercicio
                throw invalid_argument("Se necesitan entre 2 y 6 números y al menos 1 operador.");
            }

            return calculadora.evaluar(elementos); // para la prioridad
        }
};

int main() {
    string operacion;
    cout << "Bienvenido a la calculadora." << endl;
    cout << "Ingrese la operación matematica (maximo 6 números). Escriba 'salir' para terminar." << endl;

    while (true) {
        cout << "Ingrese la operacion: ";
        getline(cin, operacion);

        if (operacion == "salir") {
            cout << "Gracias por usar la calculadora. ¡Hasta luego!" << endl;
            break; // Salir del bucle
        }

        try {
            Procesador procesador(operacion);
            double resultado = procesador.procesar();
            cout << "El resultado es: " << resultado << endl;
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl; // Mensaje de error específico
        } catch (...) {
            cout << "Error inesperado. Por favor, verifique su entrada." << endl;
        }
    }

    return 0;
}