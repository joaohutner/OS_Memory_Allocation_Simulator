#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "process_.h"
#include "system.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonProximo_clicked();
    void on_buttonProximo_2_clicked();


private:
    Ui::MainWindow *ui;
    System aux_sys;
    void hideSizes(const int &value);
    void showSizes(const int &value);
    void createProcess(const int &value);
};
#endif // MAINWINDOW_H
