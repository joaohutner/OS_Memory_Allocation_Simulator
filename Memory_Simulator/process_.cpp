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

bool Process_::getDentroRam() const
{
    return dentroRam;
}

void Process_::setDentroRam(bool value)
{
    dentroRam = value;
}

Process_::Process_()
{
    this->dentroRam = 0;
}
