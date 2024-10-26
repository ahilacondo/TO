#include "task.h"
#include "ui_task.h"
#include <QDebug>

Task::Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task),
    editing(false)  // Inicialmente, no estamos en modo edición
{
    ui->setupUi(this);

    // Conectar el botón "Quitar" al slot de eliminación con una lambda
    connect(ui->removeButton, &QPushButton::clicked, [this] { emit removed(this); });

    // Conectar el botón "Editar" a una lambda para alternar el modo de edición
    connect(ui->editButton, &QPushButton::clicked, [this] {
        qDebug() << "Botón de editar presionado. Modo edición actual:" << editing;

        if (editing) {
            ui->lineEditPais->setEnabled(false);
            ui->lineEditCapital->setEnabled(false);
            ui->editButton->setText("Editar");
        } else {
            ui->lineEditPais->setEnabled(true);
            ui->lineEditCapital->setEnabled(true);
            ui->editButton->setText("Guardar");
        }
        editing = !editing;  // Alternar el estado de edición
    });

    // Deshabilitar los campos de texto inicialmente
    ui->lineEditPais->setText("Perú");  // Valor predeterminado
    ui->lineEditCapital->setText("Lima");  // Valor predeterminado
    ui->lineEditPais->setEnabled(false);
    ui->lineEditCapital->setEnabled(false);
}

Task::~Task()
{
    delete ui;
}
