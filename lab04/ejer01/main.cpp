#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // generar un vector de num enteros aleatorios
    std::vector<int> numeros(10); // vector de 10 num
    std::generate(numeros.begin(), numeros.end(), []() {
        return QRandomGenerator::global()->bounded(100); // generar num entre 0 y 99
    });

    // imprimir los num generados
    qDebug() << "Números generados:";
    for (int num : numeros) {
        qDebug() << num;
    }

    // std::count_if para contar los num impares y menores de 20
    int conteo = std::count_if(numeros.begin(), numeros.end(), [](int n) {
        return (n < 20) && (n % 2 != 0); // condicion de impares y menores de 20
    });

    // mostrar el resultado
    qDebug() << "Cantidad de numeros impares y menores de 20:" << conteo;

    return a.exec();
}

