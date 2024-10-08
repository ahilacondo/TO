#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int esAnstrong(int n); //Funcion que nos dice si un numero es cubo perfecto
inline int cubo(int n); //Funcion que nos da el cubo de un numero
bool esNumValido(const string &str); //Funcion que nos dice si un string es un numero valido
void obtenerDigitos(int n, int digitos[], int &tam); //Funcion que nos da los digitos de un numero

inline int cubo(int n){
    return n * n * n;
}

void obtenerDigitos(int n, int digitos[], int &tam){
    tam = 0;
    while (n > 0){
        digitos[tam++] = n % 10;
        n /= 10;
    }
}

int esAnstrong(int n){
    int tam;
    int digitos[10];
    obtenerDigitos(n, digitos, tam);

    int suma = 0;
    while(tam > 0){
        suma += cubo(digitos[--tam]);
    }
    return suma == n;
}

bool esNumValido(const string &str){
    for(char c: str){
        if(!isdigit(c))
            return false;
    }
    return true;
}
int main(){
    char seguir = 's';
    string str;

    while (tolower(seguir) == 's'){
        int num = 0;
        cout << "''''''''''''''''INGRESE UN NUMERO ''''''''''''''''" << endl;
        getline(cin, str);
        
        if(esNumValido(str)){
            stringstream ss(str);
            ss >> num;

            if(esAnstrong(num))
                cout << "El numero ingresado es cubo perfecto" << endl;
            else
                cout << "El numero ingresado NO es cubo perfecto" << endl;

        }else{
            cout << "El valor ingresado no es un numero valido" << endl;
        }
        cout << "Desea ingresar otro numero? (s/n)" << endl;
        cin >> seguir;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}