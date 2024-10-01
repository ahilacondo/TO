#include <iostream>
#include <map>

using namespace std;

class MaquinaExpendedoraDeGolosinas{
    private:
        //structura golosina -> precio, cantidad
        struct Golosina{
            string cod;
            float precio;
            int cantidad;
        };

        map<string, Golosina> golosinas;
        double saldo;

    public:
        MaquinaExpendedoraDeGolosinas(){
            this->saldo = 0;
        }


        //agregar saldo
        void agregarSaldo(double saldo){
            this->saldo += saldo;
        }
        
        //escoger golosina
        void escogerGolosina(string cod){
            if(this->golosinas.find(cod) != this->golosinas.end()){
                if(this->golosinas[cod].cantidad > 0){
                    if(this->saldo >= this->golosinas[cod].precio){
                        this->golosinas[cod].cantidad--;
                        this->saldo -= this->golosinas[cod].precio;
                        cout << "Golosina entregada" << endl;
                    }else{
                        cout << "Saldo insuficiente" << endl;
                    }
                }else{
                    cout << "Golosina agotada" << endl;
                }
            }else{
                cout << "Golosina no existe" << endl;
            }
        }

};

int main(){
    cout << "Hello World" << endl;
    return 0;
}


