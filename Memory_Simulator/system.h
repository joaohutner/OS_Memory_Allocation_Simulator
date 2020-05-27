#ifndef SYSTEM_H
#define SYSTEM_H
#include "process_.h"

class System
{
private:
    int size;
    int number;
    QVector<Process_> p;
    QVector<int> RAM;
public:
    System();
    int getSize() const;
    void setSize(int value);
    int getNumber() const;
    void setNumber(int value);
    void imprimeAll();

    void addProcess(Process_ aux);
    Process_ getProcess(int posi);
    void replaceProcess(int posicao,const Process_ &value);

    void addRAM(int aux);
    int getRAM(int posicao);
    void replaceRAM(int posicao, const int &value);
};

#endif // SYSTEM_H
