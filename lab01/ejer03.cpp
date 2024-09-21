#include <iostream>
#include <vector>

using namespace std;

vector<int> cantDivisores(int n);
void printDatos(vector<int> v);

vector<int> cantDivisores(int n){
    vector<int> divisores;

    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            divisores.push_back(i);
        }
    }
    return divisores;
}

void printDatos(vector<int> v){
    cout << "La cantidad de divisores es: " << v.size() << endl;
    cout << "Los divisores son: " << endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

int main(){
    int n;
    cout << "Ingrese un numero para sacar su cantidad de divisores: " << endl;
    cin >> n;
    vector<int> divisores = cantDivisores(n);
    printDatos(divisores);
    return 0;
}