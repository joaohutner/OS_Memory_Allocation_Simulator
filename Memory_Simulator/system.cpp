#include "system.h"

int System::getSize() const
{
    return size;
}

void System::setSize(int value)
{
    size = value;
}

void System::addProcess(Process_ aux)
{
    this->p.append(aux);
}

int System::getNumber() const
{
    return number;
}

void System::setNumber(int value)
{
    number = value;
}

void System::imprimeAll()
{
    int tam = this->p.size();
    for(int i=0;i<tam;i++){
        cout <<"\nProcesso "<<i+1 << endl;
        this->p[i].imprime();
    }
}

System::System()
{
    
}
