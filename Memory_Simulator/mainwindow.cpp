#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "dialogrun.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hideSizes(9);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonProximo_clicked()
{
    QString nProcess = ui->inputNumberProcess->text();
    int np = nProcess.toInt();

    QString Size= ui->inputSystemSize->text();
    int ss = Size.toInt();

    this->aux_sys.setNumber(np);
    this->aux_sys.setSize(ss);

    showSizes(np);
}

void MainWindow::on_buttonProximo_2_clicked()
{
    hide();
    createProcess(this->aux_sys.getNumber());
    DialogRun dialogRun(this->aux_sys);
    dialogRun.exec();
}

void MainWindow::hideSizes(const int &value)
{
    ui->buttonProximo_2->setHidden(1);
    for (int i=1;i<=value;i++){
        if(i==1){
            ui->labelProcess_1->setHidden(1);
            ui->labelSize_1->setHidden(1);
            ui->labelTime_1->setHidden(1);
            ui->inputSize_1->setHidden(1);
            ui->inputTime_1->setHidden(1);
        }
        if(i==2){
            ui->labelProcess_2->setHidden(1);
            ui->labelSize_2->setHidden(1);
            ui->labelTime_2->setHidden(1);
            ui->inputSize_2->setHidden(1);
            ui->inputTime_2->setHidden(1);
        }
        if(i==3){
            ui->labelProcess_3->setHidden(1);
            ui->labelSize_3->setHidden(1);
            ui->labelTime_3->setHidden(1);
            ui->inputSize_3->setHidden(1);
            ui->inputTime_3->setHidden(1);
        }
        if(i==4){
            ui->labelProcess_4->setHidden(1);
            ui->labelSize_4->setHidden(1);
            ui->labelTime_4->setHidden(1);
            ui->inputSize_4->setHidden(1);
            ui->inputTime_4->setHidden(1);
        }
        if(i==5){
            ui->labelProcess_5->setHidden(1);
            ui->labelSize_5->setHidden(1);
            ui->labelTime_5->setHidden(1);
            ui->inputSize_5->setHidden(1);
            ui->inputTime_5->setHidden(1);
        }
        if(i==6){
            ui->labelProcess_6->setHidden(1);
            ui->labelSize_6->setHidden(1);
            ui->labelTime_6->setHidden(1);
            ui->inputSize_6->setHidden(1);
            ui->inputTime_6->setHidden(1);
        }
        if(i==7){
            ui->labelProcess_7->setHidden(1);
            ui->labelSize_7->setHidden(1);
            ui->labelTime_7->setHidden(1);
            ui->inputSize_7->setHidden(1);
            ui->inputTime_7->setHidden(1);
        }
        if(i==8){
            ui->labelProcess_8->setHidden(1);
            ui->labelSize_8->setHidden(1);
            ui->labelTime_8->setHidden(1);
            ui->inputSize_8->setHidden(1);
            ui->inputTime_8->setHidden(1);
        }
        if(i==9){
            ui->labelProcess_9->setHidden(1);
            ui->labelSize_9->setHidden(1);
            ui->labelTime_9->setHidden(1);
            ui->inputSize_9->setHidden(1);
            ui->inputTime_9->setHidden(1);
        }
    }
}
void MainWindow::showSizes(const int &value)
{
    ui->labelNumberOfProcess->setHidden(1);
    ui->labelSystemMemorySize->setHidden(1);
    ui->inputSystemSize->setHidden(1);
    ui->inputNumberProcess->setHidden(1);
    ui->buttonProximo->setHidden(1);
    ui->buttonProximo_2->setHidden(0);

    for (int i=1;i<=value;i++){
        if(i==1){
            ui->labelProcess_1->setHidden(0);
            ui->labelSize_1->setHidden(0);
            ui->labelTime_1->setHidden(0);
            ui->inputSize_1->setHidden(0);
            ui->inputTime_1->setHidden(0);
        }
        if(i==2){
            ui->labelProcess_2->setHidden(0);
            ui->labelSize_2->setHidden(0);
            ui->labelTime_2->setHidden(0);
            ui->inputSize_2->setHidden(0);
            ui->inputTime_2->setHidden(0);
        }
        if(i==3){
            ui->labelProcess_3->setHidden(0);
            ui->labelSize_3->setHidden(0);
            ui->labelTime_3->setHidden(0);
            ui->inputSize_3->setHidden(0);
            ui->inputTime_3->setHidden(0);
        }
        if(i==4){
            ui->labelProcess_4->setHidden(0);
            ui->labelSize_4->setHidden(0);
            ui->labelTime_4->setHidden(0);
            ui->inputSize_4->setHidden(0);
            ui->inputTime_4->setHidden(0);
        }
        if(i==5){
            ui->labelProcess_5->setHidden(0);
            ui->labelSize_5->setHidden(0);
            ui->labelTime_5->setHidden(0);
            ui->inputSize_5->setHidden(0);
            ui->inputTime_5->setHidden(0);
        }
        if(i==6){
            ui->labelProcess_6->setHidden(0);
            ui->labelSize_6->setHidden(0);
            ui->labelTime_6->setHidden(0);
            ui->inputSize_6->setHidden(0);
            ui->inputTime_6->setHidden(0);
        }
        if(i==7){
            ui->labelProcess_7->setHidden(0);
            ui->labelSize_7->setHidden(0);
            ui->labelTime_7->setHidden(0);
            ui->inputSize_7->setHidden(0);
            ui->inputTime_7->setHidden(0);
        }
        if(i==8){
            ui->labelProcess_8->setHidden(0);
            ui->labelSize_8->setHidden(0);
            ui->labelTime_8->setHidden(0);
            ui->inputSize_8->setHidden(0);
            ui->inputTime_8->setHidden(0);
        }
        if(i==9){
            ui->labelProcess_9->setHidden(0);
            ui->labelSize_9->setHidden(0);
            ui->labelTime_9->setHidden(0);
            ui->inputSize_9->setHidden(0);
            ui->inputTime_9->setHidden(0);
        }
    }
}
void MainWindow::createProcess(const int &value)
{
    Process_ aux_proc;
    QString aux_QS;
    int aux_int;
    for (int i=1;i<=value;i++){
        if(i==1){
            aux_QS = ui->inputSize_1->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_1->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==2){
            aux_QS = ui->inputSize_2->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_2->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==3){
            aux_QS = ui->inputSize_3->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_3->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==4){
            aux_QS = ui->inputSize_4->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_4->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==5){
            aux_QS = ui->inputSize_5->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_5->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==6){
            aux_QS = ui->inputSize_6->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_6->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==7){
            aux_QS = ui->inputSize_7->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_7->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==8){
            aux_QS = ui->inputSize_8->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_8->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
        if(i==9){
            aux_QS = ui->inputSize_9->text();
            aux_int = aux_QS.toInt();
            aux_proc.setSizeProc(aux_int);

            aux_QS = ui->inputTime_9->text();
            aux_int = aux_QS.toInt();
            aux_proc.setTime(aux_int);

            this->aux_sys.addProcess(aux_proc);
        }
    }
}

