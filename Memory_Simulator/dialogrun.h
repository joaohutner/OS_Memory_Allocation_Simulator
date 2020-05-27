#ifndef DIALOGRUN_H
#define DIALOGRUN_H

#include <QDialog>
#include <QPainter>
#include "system.h"

namespace Ui {
class DialogRun;
}

class DialogRun : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRun(QWidget *parent = nullptr);
    explicit DialogRun(System sys,QWidget *parent = nullptr);
    ~DialogRun();

    virtual void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DialogRun *ui;
};

#endif // DIALOGRUN_H
