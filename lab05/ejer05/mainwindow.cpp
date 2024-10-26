#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
{
    ui->setupUi(this);

    // Conectar el botón "Agregar tarea" con el slot correspondiente
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    qDebug() << "Botón 'Agregar país' clickeado";

    // Crear una nueva instancia de la clase Task
    Task* task = new Task(this);

    // Conectar la señal "removed" con el slot para eliminar la tarea
    connect(task, &Task::removed, this, &MainWindow::removeTask);

    // Agregar la tarea al layout
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->tasksLayout->layout());
    if (layout) {
        layout->addWidget(task);
    }

    // Guardar la tarea en el QVector
    mTasks.append(task);
}

void MainWindow::removeTask(Task* task)
{
    qDebug() << "Eliminando tarea";

    // Remover la tarea del layout y eliminarla
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->tasksLayout->layout());
    if (layout) {
        layout->removeWidget(task);
    }
    mTasks.removeOne(task);  // Eliminar del QVector
    task->deleteLater();     // Eliminar el objeto de forma segura
}
