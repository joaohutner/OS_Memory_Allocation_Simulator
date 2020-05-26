#ifndef SYSTEM_H
#define SYSTEM_H

#include <QVector>
#include "process_.h"

class System
{
private:
    int size;
    int number;
    QVector<Process_> p;
public:
    System();
    int getSize() const;
    void setSize(int value);
    void addProcess(Process_ aux);
    int getNumber() const;
    void setNumber(int value);
    void imprimeAll();
};

#endif // SYSTEM_H
