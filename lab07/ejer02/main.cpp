#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// Clase base para Cuentas y Tarjetas
template <typename T>
class Account {
protected:
    string owner;
    T balance;
    constexpr static float defaultInterestRate = 0.005f; // Tasa de interés por defecto
    string accountType;

public:
    Account(string owner, T balance, float rate = defaultInterestRate, string type = "Cuenta")
        : owner(move(owner)), balance(balance), accountType(move(type)) {}

    // Getters
    string GetAccountType() const { return accountType; }
    T GetBalance() const { return balance; }

    // Sobrecarga de operador para comparar tipo de cuenta
    bool operator==(const string& type) const { return accountType == type; }

    // Método virtual para mostrar información de cuenta
    virtual void DisplayAccountInfo() const {
        cout << "Titular: " << owner << ", Tipo: " << accountType
             << ", Saldo: " << fixed << setprecision(2) << balance
             << ", Interes: " << defaultInterestRate * 100 << "%" << endl;
    }

    // Método virtual para calcular interés
    virtual T CalculateInterest() const {
        return balance * defaultInterestRate;
    }

    virtual void SetBalance(T newBalance) { balance = newBalance; }

    virtual ~Account() = default;
};

// Tipos específicos de cuentas
template <typename T>
class SavingsAccount : public Account<T> {
public:
    SavingsAccount(string owner, T balance)
        : Account<T>(move(owner), balance, 0.0045f, "Cuenta de Ahorro") {}
};

template <typename T>
class YouthAccount : public Account<T> {
public:
    YouthAccount(string owner, T balance)
        : Account<T>(move(owner), balance, 0.005f, "Cuenta Joven") {}
};

template <typename T>
class PlusAccount : public Account<T> {
public:
    PlusAccount(string owner, T balance)
        : Account<T>(move(owner), balance, 0.007f, "Cuenta Plus") {}
};

template <typename T>
class BusinessAccount : public Account<T> {
public:
    BusinessAccount(string owner, T balance)
        : Account<T>(move(owner), balance, 0.009f, "Cuenta Empresarial") {}
};

// Clase Tarjeta de Crédito que hereda de Account
template <typename T>
class CreditCard : public Account<T> {
    float creditRate;

public:
    CreditCard(string owner, T balance, float rate = 0.20f)
        : Account<T>(move(owner), balance, rate, "Tarjeta de Credito"), creditRate(rate) {}

    T CalculateInterest() const override {
        return this->balance * creditRate;
    }

    void DisplayAccountInfo() const override {
        Account<T>::DisplayAccountInfo();
        cout << "Interes en compras: " << creditRate * 100 << "%" << endl;
    }
};

// Clase Cliente
class Customer {
    string name;
    vector<shared_ptr<Account<float>>> accounts;

public:
    Customer(string name) : name(move(name)) {}

    void AddAccount(shared_ptr<Account<float>> account) {
        accounts.push_back(move(account));
    }

    void DisplayAllAccounts() const {
        cout << "Estado de cuenta global para: " << name << endl;
        for_each(accounts.begin(), accounts.end(), [](const auto& account) {
            account->DisplayAccountInfo();
        });
    }

    void DisplayAccountByType(const string& type) const {
        cout << "Estado de cuenta para cuentas tipo " << type << " de " << name << endl;
        for_each(accounts.begin(), accounts.end(), [&](const auto& account) {
            if (*account == type) account->DisplayAccountInfo();
        });
    }

    void SettleDebt(float amount) {
        cout << name << " está liquidando una deuda de " << amount << endl;
        for (auto& account : accounts) {
            if (*account == "Tarjeta de Credito" && account->GetBalance() < 0) {
                float debt = -account->GetBalance();
                if (amount >= debt) {
                    amount -= debt;
                    account->SetBalance(0);
                } else {
                    account->SetBalance(account->GetBalance() + amount);
                    amount = 0;
                }
                cout << "Deuda liquidada parcialmente. Resto a pagar: " << amount << endl;
                break;
            }
        }
    }

    void Transfer(float amount, const string& currency) {
        auto calculateFee = [](float amount, const string& currency) {
            return currency == "soles" ? amount * 0.005f : amount * 0.0021f;
        };

        float fee = calculateFee(amount, currency);
        cout << "Transferencia de " << amount << " " << currency
             << ". Comisión aplicada: " << fee << endl;
    }
};

// Main de prueba
int main() {
    // Crear clientes y cuentas
    Customer cliente1("CLIENTE1");

    cliente1.AddAccount(make_shared<SavingsAccount<float>>("CLIENTE1", 5000.0f));
    cliente1.AddAccount(make_shared<CreditCard<float>>("CLIENTE1", -2000.0f, 0.18f));
    cliente1.AddAccount(make_shared<BusinessAccount<float>>("CLIENTE1", 15000.0f));

    // Mostrar estado de cuenta global
    cliente1.DisplayAllAccounts();

    // Mostrar estado de cuenta por tipo
    cliente1.DisplayAccountByType("Tarjeta de Credito");

    // Liquidar deudas
    cliente1.SettleDebt(500.0f);

    // Realizar transferencia
    cliente1.Transfer(1000.0f, "soles");

    return 0;
}
