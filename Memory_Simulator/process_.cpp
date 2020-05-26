#include "process_.h"

int Process_::getTime() const
{
    return time;
}

void Process_::setTime(int value)
{
    time = value;
}

int Process_::getSizeProc() const
{
    return sizeProc;
}

void Process_::setSizeProc(int value)
{
    sizeProc = value;
}

void Process_::imprime()
{
    cout <<"\nSize: "<<this->getSizeProc()<<endl;
    cout <<"\nTime: "<<this->getTime()<<endl;
}

Process_::Process_()
{

}
