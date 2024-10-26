#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void addTask();   // Slot para agregar una nueva tarea
    void removeTask(Task* task);  // Slot para eliminar una tarea

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;  // Vector para almacenar las tareas dinámicamente
};
#endif // MAINWINDOW_H
