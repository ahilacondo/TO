#include <QListWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //invisible
    ui->labelInfo->setVisible(false);
    ui->labelFlag->setVisible(false);

    // Llenar la lista de países y su información
    countryData.insert("Perú", qMakePair("Lima", "Español"));
    countryData.insert("Brasil", qMakePair("Brasilia", "Portugués"));
    countryData.insert("Argentina", qMakePair("Buenos Aires", "Español"));
    countryData.insert("Chile", qMakePair("Santiago", "Español"));
    countryData.insert("Colombia", qMakePair("Bogotá", "Español"));
    countryData.insert("Uruguay", qMakePair("Montevideo", "Español"));
    countryData.insert("Paraguay", qMakePair("Asunción", "Español"));
    countryData.insert("Ecuador", qMakePair("Quito", "Español"));
    countryData.insert("Bolivia", qMakePair("Sucre", "Español"));

    flagPaths.insert("Perú", ":img/peru.png");
    flagPaths.insert("Brasil", ":img/brasil.png");
    flagPaths.insert("Argentina", ":img/argentina.png");
    flagPaths.insert("Chile", ":img/chile.png");
    flagPaths.insert("Colombia", ":img/colombia.png");
    flagPaths.insert("Uruguay", ":img/uruguay.png");
    flagPaths.insert("Paraguay", ":img/paraguay.png");
    flagPaths.insert("Ecuador", ":img/ecuador.png");
    flagPaths.insert("Bolivia", ":img/bolivia.png");

    // Agregar los países a la lista
    for (const QString &country : countryData.keys()) {
        ui->listWidgetCountries->addItem(country);
    }

    // Conectar la señal del QListWidget al slot para manejar el clic
    connect(ui->listWidgetCountries, &QListWidget::itemClicked, this, &MainWindow::onCountryClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot para mostrar la información del país cuando se selecciona
void MainWindow::onCountryClicked(QListWidgetItem *item)
{
    QString countryName = item->text();
    QString capital = countryData.value(countryName).first;
    QString language = countryData.value(countryName).second;

    // Actualizar el QLabel con la información del país
    ui->labelInfo->setText("Capital: " + capital + "\nIdioma: " + language);
    ui->labelInfo->setVisible(true);

    //banderas
    QString flagPath = flagPaths.value(countryName);
    QPixmap flag(flagPath);
    if (!flag.isNull()) {
        ui->labelFlag->setPixmap(flag.scaled(100, 100, Qt::KeepAspectRatio));
        ui->labelFlag->setVisible(true);
    } else {
        ui->labelFlag->setVisible(false);
    }
}
