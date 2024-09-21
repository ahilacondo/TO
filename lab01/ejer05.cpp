#include <iostream>
#include <string>
#include <vector>

using namespace std;

//clase producto
class Producto{
    private:
        string nombre;
        float precio;

    public:
        Producto(string name, float price){
            nombre = name;
            precio = price;
        }

        string getNombre(){
            return nombre;
        }

        float getPrecio(){
            return precio;
        }
};

//clase billetera electronica
class BilleteraElectronica {
    private:
        float saldo;
        vector<Producto> carrito;
        int numProductosComprados;

    public:
        //billetera recien generada
        BilleteraElectronica(float s){
            saldo = s;
            numProductosComprados = 0;
        }

        int consultarSaldo(){
            return saldo;
        }

        void agregarFondos(float f){
            saldo += f;
        }

        bool retirarFondos(float f){
            if(saldo >= f){
                saldo -= f;
                return true;
            }
            return false;
        }

        void agregarAlCarrito(Producto p){
            carrito.push_back(p);
        }

        void removerDelCarrito(Producto p){
            for(int i = 0; i , carrito.size(); i++){
                if(carrito[i].getNombre() == p.getNombre()){
                    carrito.erase(carrito.begin() + i);
                    break;
                }
            }
        }

        bool realizarCompra(){
            float total = 0;
            for(int i = 0; i < carrito.size(); i++){
                total += carrito[i].getPrecio();
            }
            if(saldo >= total){
                saldo -= total;
                numProductosComprados = carrito.size();
                carrito.clear();
                return true;
            }
            return false;
        }

        int obtenerNumeroProductosComprados(){
            return numProductosComprados;
        }       
};

int main(){
    Producto p1("Papas", 10);
    Producto p2("Coca", 5);
    Producto p3("Chocolatina", 2);

    BilleteraElectronica b(100);
    b.agregarAlCarrito(p1);
    b.agregarAlCarrito(p2);
    b.agregarAlCarrito(p3);

    cout << "Saldo: " << b.consultarSaldo() << endl;
    
    b.realizarCompra();

    cout << "Numero de productos comprados: " << b.obtenerNumeroProductosComprados() << endl;
    cout << "Saldo Actualizado: " << b.consultarSaldo() << endl;

    return 0;
}