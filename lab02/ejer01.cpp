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

            for (size_t i = 1; i < elementos.size(); i += 2) {
                double operando = stod(elementos[i + 1]);
                resultado = calculadora.calcular(resultado, operando, elementos[i]);
            }

            return resultado;
        }
};

int main(){
    string operacion;
    cout << "Ingrese la operacion matematica: ";
    getline(cin, operacion);

    Procesador procesador(operacion);
    cout << "El resultado es: " << procesador.procesar() << endl;

    return 0;
}