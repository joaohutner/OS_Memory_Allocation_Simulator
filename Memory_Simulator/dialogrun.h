#ifndef DIALOGRUN_H
#define DIALOGRUN_H

#include <QDialog>

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

private:
    Ui::DialogRun *ui;
};

#endif // DIALOGRUN_H
