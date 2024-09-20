#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

using namespace std;

const int PRIMARIA = 1;
const int SECUNDARIA = 2;
const int SUPERIOR = 3;

struct persona{
    string grado;
    int edad;
};

int generarAleatorio(int min, int max); //Funcion que genera numeros aleatorios
void imprimirPersonas(persona personas[], int n);

int generarAleatorio(int min, int max){
    return rand() % (max - min + 1) + min;
}

void imprimirPersonas(persona personas[], int n){
    for(int i = 0; i < n; i++){
        cout << "Persona " << i + 1 << ": Edad = " << personas[i].edad << ", Grado = " << personas[i].grado << endl;
    }
}

int main(){
    int n = 10; //numero de personas
    int edadMin = 15;
    int edadMax = 80;
    srand(time(0));
    
    persona personas[n];

    for(int i = 0; i < n ; i++){
        personas[i].edad = generarAleatorio(edadMin, edadMax);
        int g = generarAleatorio(PRIMARIA, SUPERIOR);
        
        switch(g){
            case PRIMARIA:
                personas[i].grado = "Primaria";
                break;
            case SECUNDARIA:
                personas[i].grado = "Secundaria";
                break;
            case SUPERIOR:
                personas[i].grado = "Superior";
                break;
        }
    }
    
    imprimirPersonas(personas, n);
    return 0;
}