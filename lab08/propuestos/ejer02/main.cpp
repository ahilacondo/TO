#include <iostream>
#include "WinFactory.h"
#include "MacFactory.h"
#include "Application.h"

int main() {
    std::cout << "Cliente: Windows" << std::endl;
    WinFactory winFactory;
    Application winApp(winFactory);
    winApp.CrearInterfaz();

    std::cout << "\nCliente: Mac" << std::endl;
    MacFactory macFactory;
    Application macApp(macFactory);
    macApp.CrearInterfaz();

    return 0;
}
