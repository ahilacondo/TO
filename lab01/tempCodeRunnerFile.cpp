#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int esAnstrong(int n); //Funcion que nos dice si un numero es cubo perfecto
inline int cubo(int n); //Funcion que nos da el cubo de un numero
bool esNumValido(const string &str); //Funcion que nos dice si un string es un numero valido

inline int cubo(int n){
    return n * n * n;
}

int esAnstrong(int n){
    int suma = 0;
    int aux = n;
    while(aux > 0){
        suma += cubo(aux % 10);
        aux /= 10;
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