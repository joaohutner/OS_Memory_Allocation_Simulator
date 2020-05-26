#ifndef PROCESS__H
#define PROCESS__H
#include<QDebug>
#include <iostream>

using namespace std;

class Process_
{
private:
    int time;
    int sizeProc;
public:
    Process_();
    int getTime() const;
    void setTime(int value);
    int getSizeProc() const;
    void setSizeProc(int value);
    void imprime();
};

#endif // PROCESS__H
