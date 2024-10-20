#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMap>
#include <QString>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCountryClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QMap<QString, QPair<QString, QString>> countryData;  // USAMOS UN MAP
    QMap<QString, QString> flagPaths;
};

#endif // MAINWINDOW_H
