#include "dialogrun.h"
#include "ui_dialogrun.h"
#include <QMessageBox>
System sys;

DialogRun::DialogRun(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRun)
{
    ui->setupUi(this);
}

DialogRun::DialogRun(System value, QWidget *parent)
    :QDialog(parent),
    ui(new Ui::DialogRun)
{
    sys = value;
    ui->setupUi(this);
    QString NofP = QString::number(sys.getNumber());
    ui->labelInputNofP->setText(NofP);
    QString SofM = QString::number(sys.getNumber());
    ui->labelInputSofM->setText(SofM);
    for(int i=0;i<sys.getSize();i++){
        sys.addRAM(0);
    }
}

DialogRun::~DialogRun()
{
    delete ui;
}

void DialogRun::on_pushButton_2_clicked()
{
    int qtd_processos = sys.getNumber();
    int size_memoria = sys.getSize();

    bool frag_externa = 0;

    for(int i = 0;i<qtd_processos;i++){
        ui->labelWarning1->setText("");
        ui->labelWarning1_2->setText("");
        if(sys.getProcess(i).getDentroRam() == 0){ //and sys.getProcess(i).getTime() > 0
            int size_processo = sys.getProcess(i).getSizeProc();
            if(size_processo > size_memoria){
                QString aux_size_warning;
                QString warning_3 = "Size of process";
                aux_size_warning.setNum(i+1);
                warning_3.append(aux_size_warning);
                warning_3.append(" is greater than main memory size!");
                QMessageBox::about(this,"Warning",warning_3);
            }
            int livre = 0;
            int livre_total = 0;
            int posi = -1;
            bool block_posi = 0;
            for(int k = 0;k<size_memoria;k++){
                if(sys.getRAM(k) == 0){
                    livre++;
                    livre_total++;
                    if(livre >= size_processo){
                        if(block_posi == 0){
                            posi = k;
                            //qDebug()<<"\nPosicao: "<<posi;
                            block_posi = 1;
                        }
                    }
                }
                else{
                    livre = 0;
                }
            }
            if(posi != -1){
                int posi_inicial = posi - size_processo + 1;
                Process_ aux_process = sys.getProcess(i);
                aux_process.setDentroRam(1);
                sys.replaceProcess(i,aux_process);
                for(int j = posi_inicial; j<=posi;j++){
                    sys.replaceRAM(j,i+1);
                }
            }
            else if(livre_total >= size_processo and posi == -1){
                frag_externa = 1;
                QString warning2 = "\nExternal fragmentation! Process ";
                QString aux_warning2;
                aux_warning2.setNum(i+1);
                warning2.append(aux_warning2);
                warning2.append("! Free total memory: ");
                aux_warning2.setNum(livre_total);
                warning2.append(aux_warning2);
                ui->labelWarning1_2->setText(warning2);
            }
            else {//if(posi == -1)
                QString warning1 = "\nNo free space in memory! Process ";
                QString aux_warning1;
                aux_warning1.setNum(i+1);
                warning1.append(aux_warning1);
                warning1.append("!");
                ui->labelWarning1->setText(warning1);
            }
        }
        else if(sys.getProcess(i).getDentroRam() == 1 and sys.getProcess(i).getTime() != 0){
            Process_ aux_process = sys.getProcess(i);
            int aux_tempo;
            aux_tempo = aux_process.getTime();
            aux_tempo = aux_tempo - 1;
            if(aux_tempo == 0){
                for(int k = 0;k<size_memoria;k++){
                    if(sys.getRAM(k) == i+1){
                        sys.replaceRAM(k,0);
                    }
                }
            }
            aux_process.setTime(aux_tempo);
            sys.replaceProcess(i,aux_process);
        }
    }
    update();
}

void DialogRun::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPen pen;

    //Pintando e preenchendo memoria principal
    pen.setColor(Qt::black); //Cor dos blocos
    pen.setWidth(2);

    painter.setPen(pen);

    painter.drawText(600,60,"Principal");
    QString sS = "Size: ";
    sS.append(QString::number(sys.getSize()));
    painter.drawText(600,70,sS);
    sS = "Size: ";
    for (int k=0;k<sys.getSize();k++){
        if(sys.getRAM(k) == 0){
            painter.setPen(Qt::black);
            painter.setBrush(Qt::NoBrush);
        }
        else{
            painter.setPen(Qt::darkGreen);
            painter.setBrush(Qt::SolidPattern);
        }
        painter.drawRect(QRect(600,85+(k*4),40,4));
    }

    painter.setBrush(Qt::NoBrush);
    QString sT = "Time: ";

    //Pintando e preenchendo os blocos de processo.
    pen.setColor(Qt::darkGreen); //Cor dos blocos
    pen.setWidth(2);

    painter.setPen(pen);

    int tam = sys.getNumber();
    int aux = 0;
    int i=0;
    int j=0;
    for (i=0;i<tam;i++){
        sS = "Size: ";
        sT = "Time: ";
        if(i==0){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 1"); //Pintando process number
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20,85+(j*4),40,4));
            }
        }
        if(i==1){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 2");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(80,85+(j*4),40,4));
            }
        }
        if(i==2){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 3");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==3){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 4");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==4){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 5");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==5){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 6");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==6){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 7");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==7){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 8");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
        if(i==8){
            aux = sys.getProcess(i).getSizeProc();
            painter.drawText(20+(i*60),60,"Process 9");
            sS.append(QString::number(sys.getProcess(i).getSizeProc())); //String auxiliar para pegar tamanho do processo
            painter.drawText(20+(i*60),70,sS);//Pintando process size
            sT.append(QString::number(sys.getProcess(i).getTime())); //String auxiliar para pegar tamanho do process
            painter.drawText(20+(i*60),80,sT);//Pintando process size
            for(j=0;j<aux;j++){
                painter.drawRect(QRect(20+(i*60),85+(j*4),40,4));
            }
        }
    }
}




