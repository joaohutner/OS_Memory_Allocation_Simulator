#include "dialogrun.h"
#include "ui_dialogrun.h"


DialogRun::DialogRun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRun)
{
    ui->setupUi(this);
}

DialogRun::DialogRun(System sys, QWidget *parent)
    :QDialog(parent),
    ui(new Ui::DialogRun)
{
    ui->setupUi(this);
    QString aux = QString::number(sys.getNumber());
    ui->labelInputNofP->setText(aux);
    sys.imprimeAll();
}

DialogRun::~DialogRun()
{
    delete ui;
}
