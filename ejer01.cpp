#include <iostream>
#include <cctype>

using namespace std;

int esAnstrong(int n); //Funcion que nos dice si un numero es cubo perfecto
inline int cubo(int n); //Funcion que nos da el cubo de un numero

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

int main(){
    char seguir = 's';
    while (tolower(seguir) == 's'){
        int num;
        cout << "''''''''''''''''INGRESE UN NUMERO ''''''''''''''''" << endl;
        cin >> num;
        
        if(esAnstrong(num))
            cout << "El numero ingresado es cubo perfecto" << endl;
        else
            cout << "El numero ingresado NO es cubo perfecto" << endl;

        cout << "Desea ingresar otro numero? (s/n)" << endl;
        cin >> seguir;
    }

    return 0;
}