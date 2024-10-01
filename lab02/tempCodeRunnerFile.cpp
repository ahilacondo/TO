int main() {
    ListaDoblementeEnlazada<int> lista;  // Especificar el tipo de dato aquí
    int opcion, valor;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Agregar elemento al final\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el valor a agregar: ";
                cin >> valor;
                lista.agregarAlFinal(valor);
                cout << valor << " agregado a la lista.\n";
                break;
            case 2:
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                cout << valor << " eliminado de la lista (si estaba presente).\n";
                break;
            case 3:
                cout << "Elementos en la lista: ";
                lista.mostrar();
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}