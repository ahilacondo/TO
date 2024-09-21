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
void imprimirDatos(); //Esta funcion va imprimir los datos que requiere el ejercicio
int edadMayor(persona persona[], int n);


int generarAleatorio(int min, int max){
    return rand() % (max - min + 1) + min;
}

void imprimirPersonas(persona personas[], int n){
    for(int i = 0; i < n; i++){
        cout << "Persona " << i + 1 << ": Edad = " << personas[i].edad << ", Grado = " << personas[i].grado << endl;
    }
}

int edadMayor(persona personas[], int n){
    int mayor = personas[0].edad;
    for(int i = 1; i < n; i++){
        if(mayor < personas[i].edad)
            mayor = personas[i].edad;
    }

    return mayor;
}

void imprimirDatos(persona personas[], int n, int cantPrimaria, int cantSecundaria, int cantSuperior){
    cout << "Cantidad de personas con grado de primaria: " << cantPrimaria << endl;
    cout << "Cantidad de personas con grado de secundaria: " << cantSecundaria << endl;
    cout << "Cantidad de personas con grado de superior: " << cantSuperior << endl;
    cout << "Edad de la persona mayor: " << edadMayor(personas, n) << endl;
}

int main(){
    int n = 10; //numero de personas
    int edadMin = 15;
    int edadMax = 80;
    int cantPrimaria = 0;
    int cantSecundaria = 0;
    int cantSuperior = 0;
    srand(time(0));
    
    persona personas[n];

    for(int i = 0; i < n ; i++){
        personas[i].edad = generarAleatorio(edadMin, edadMax);
        int g = generarAleatorio(PRIMARIA, SUPERIOR);
        
        switch(g){
            case PRIMARIA:
                personas[i].grado = "Primaria";
                cantPrimaria++;
                break;
            case SECUNDARIA:
                personas[i].grado = "Secundaria";
                cantSecundaria++;
                break;
            case SUPERIOR:
                personas[i].grado = "Superior";
                cantSuperior++;
                break;
        }
    }
    
    imprimirPersonas(personas, n);
    imprimirDatos(personas, n, cantPrimaria, cantSecundaria, cantSuperior);
    return 0;
}