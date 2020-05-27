#ifndef PROCESS__H
#define PROCESS__H
#include <QDebug>
#include <iostream>
#include <QVector>

using namespace std;

class Process_
{
private:
    int time;
    int sizeProc;
    int dentroRam;
public:
    Process_();
    int getTime() const;
    void setTime(int value);
    int getSizeProc() const;
    void setSizeProc(int value);
    void imprime();
    bool getDentroRam() const;
    void setDentroRam(bool value);
};

#endif // PROCESS__H
