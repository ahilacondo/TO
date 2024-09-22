#include <iostream>
#include <string>
#include <vector>

using namespace std;

void imprimirOpciones(); //funcion de opciones
bool buscarProducto(); //funcion de busqueda de producto

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

int buscarProducto(vector<Producto> productos, string nombre){
    for(int i = 0; i < productos.size(); i++){
        if(productos[i].getNombre() == nombre){
            return i;
        }
    }
    return -1;
}

void imprimirOpciones(){
    cout << "Seleccione una opcion: " << endl;
    cout << "1. Agregar Fondos" << endl;
    cout << "2. Retirar Fondos" << endl;
    cout << "3. Agregar Producto al Carrito" << endl;
    cout << "4. Remover Producto del Carrito" << endl;
    cout << "5. Realizar Compra" << endl;
    cout << "6. Consultar Saldo" << endl;
    cout << "7. Salir" << endl;
    cout << ">>>>>>>> ";
}

int main(){
    //Menu
    int opcion = 0;
    int i = 0;
    string nombre;
    BilleteraElectronica b(0);

    //Producto ya definidos
    vector <Producto> productos = {
        Producto("Papas", 10),
        Producto("Coca", 5),
        Producto("Chocolatina", 2),
        Producto("Galletas", 3),
        Producto("Chicles", 1)
    };

    cout << "BIENVENIDO AL SISTEMA" << endl;
    while (opcion != 7){
        imprimirOpciones();
        cin >> opcion;

        switch(opcion){
            case 1:
                float fondos;
                cout << "Ingrese la cantidad de fondos a agregar: ";
                cin >> fondos;
                b.agregarFondos(fondos);
                break;
            case 2:
                float retiro;
                cout << "Ingrese la cantidad de fondos a retirar: ";
                cin >> retiro;
                if(b.retirarFondos(retiro)){
                    cout << "Retiro exitoso" << endl;
                }else{
                    cout << "Fondos insuficientes" << endl;
                }
                break;
            case 3:
                float precio;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                i = buscarProducto(productos, nombre);
                if ( i != -1){
                    b.agregarAlCarrito(productos[i]);
                }else{
                    cout << "Producto no encontrado" << endl;
                }                 
                break;
            case 4:
                cout << "Ingrese el nombre del producto a remover: ";
                cin >> nombre;
                i = buscarProducto(productos, nombre);
                if ( i != -1){
                    b.removerDelCarrito(productos[i]);
                }else{
                    cout << "Producto no encontrado" << endl;
                }
                break;
            case 5:
                if(b.realizarCompra()){
                    cout << "Compra realizada con exito" << endl;
                }else{
                    cout << "Fondos insuficientes" << endl;
                }
                break;
            case 6:
                cout << "Saldo: " << b.consultarSaldo() << endl;
                break;
            case 7:
                cout << "Gracias por usar el sistema" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
    }

    return 0;
}
