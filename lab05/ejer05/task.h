#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void removed(Task* task);  // Señal para eliminar la tarea

private:
    Ui::Task *ui;
    bool editing;
};

#endif // TASK_H
