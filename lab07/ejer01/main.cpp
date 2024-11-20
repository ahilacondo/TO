#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base abstracta para las partes de la laptop
class Item {
public:
    virtual string GetName() { return ""; }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
    virtual ~Item() = default;  // Destructor virtual para manejar bien la herencia
};

// Clase base para el Procesador
class Processor : public Item {};
class Intel15 : public Processor {
public:
    string GetName() override { return "Intel i5"; }
    float GetPrice() override { return 3000.00; }
    void GetConfiguration() override {
        cout << "1.50 GHz, up to 2.0 GHz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4-8 GB" << endl;
    }
};

class Intel17 : public Processor {
public:
    string GetName() override { return "Intel i7"; }
    float GetPrice() override { return 4700.00; }
    void GetConfiguration() override {
        cout << "1.6 GHz, up to 1.99 GHz, 9th Gen, 4 cores, 8 threads, 16 MB cache, RAM 16 GB" << endl;
    }
};

// Clase base para el Disco
class Drive : public Item {};
class HDD : public Drive {
public:
    string GetName() override { return "Hard disk drive"; }
    float GetPrice() override { return 150.00; }
    void GetConfiguration() override {
        cout << "Capacity: 1 TB, Data transfer: 1050 Mbits/s" << endl;
    }
};

class SDD : public Drive {
public:
    string GetName() override { return "Solid state drive"; }
    float GetPrice() override { return 270.00; }
    void GetConfiguration() override {
        cout << "Capacity: 250 GB, Data transfer: 1800 Mbits/s" << endl;
    }
};

// Clase base para la Pantalla
class DisplayType : public Item {};
class Normal : public DisplayType {
public:
    string GetName() override { return "Non-touch screen"; }
    float GetPrice() override { return 195.00; }
    void GetConfiguration() override {
        cout << "15.6 inch FHD (1920 x 1080), flat, etc." << endl;
    }
};

class Plasma : public DisplayType {
public:
    string GetName() override { return "Plasma screen"; }
    float GetPrice() override { return 500.00; }
    void GetConfiguration() override {
        cout << "32 inch, 4K resolution, HDR10+" << endl;
    }
};

// Clase para la impresora
class Printer : public Item {
public:
    string GetName() override { return "Laser Printer"; }
    float GetPrice() override { return 800.00; }
    void GetConfiguration() override {
        cout << "Black & White, 20 ppm, WiFi, Duplex" << endl;
    }
};

// Clase para los colores
class Color : public Item {
    string colorName;
public:
    Color(string name) : colorName(move(name)) {}
    string GetName() override { return "Color"; }
    float GetPrice() override { return 50.00; }
    void GetConfiguration() override {
        cout << "Color: " << colorName << endl;
    }
};

// Clase para las marcas
class Brand : public Item {
    string brandName;
public:
    Brand(string name) : brandName(move(name)) {}
    string GetName() override { return "Brand"; }
    float GetPrice() override { return 100.00; }
    void GetConfiguration() override {
        cout << "Brand: " << brandName << endl;
    }
};

// Clase para la laptop
class Laptop {
public:
    void AddParts(Item* item) {
        mLaptopParts.push_back(item);
    }

    float GetCost() const {
        float cost = 0.0;
        for (const auto& item : mLaptopParts) {
            cost += item->GetPrice();
        }
        return cost;
    }

    void GetConfiguration() const {
        for (const auto& item : mLaptopParts) {
            cout << item->GetName() << ": ";
            item->GetConfiguration();
        }
    }

    ~Laptop() {
        for (auto item : mLaptopParts) {
            delete item;
        }
    }

private:
    vector<Item*> mLaptopParts;
};

// Clase para construir laptops con opciones específicas
class LaptopBuilder {
public:
    Laptop* opcion1() {
        Laptop* lap = new Laptop();
        lap->AddParts(new Intel15());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        lap->AddParts(new Color("Black"));
        lap->AddParts(new Brand("Lenovo"));
        return lap;
    }

    Laptop* opcion2() {
        Laptop* lap = new Laptop();
        lap->AddParts(new Intel17());
        lap->AddParts(new Plasma());
        lap->AddParts(new SDD());
        lap->AddParts(new Printer());
        lap->AddParts(new Color("Silver"));
        lap->AddParts(new Brand("Dell"));
        return lap;
    }
};

int main() {
    LaptopBuilder cotizar;

    cout << "Laptop Configuración 1:\n";
    Laptop* laptop1 = cotizar.opcion1();
    laptop1->GetConfiguration();
    cout << "Precio: " << laptop1->GetCost() << " soles\n\n";

    cout << "Laptop Configuración 2:\n";
    Laptop* laptop2 = cotizar.opcion2();
    laptop2->GetConfiguration();
    cout << "Precio: " << laptop2->GetCost() << " soles\n";

    delete laptop1;
    delete laptop2;

    return 0;
}
