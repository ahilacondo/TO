#include <iostream>
#include <string>
#include <vector>

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

};

// clase para procesar la operacion matematica
class Procesador{

};

int main(){
    return 0;
}