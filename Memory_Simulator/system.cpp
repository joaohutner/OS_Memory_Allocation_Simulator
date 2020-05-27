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

Process_ System::getProcess(int posi)
{
    return this->p[posi];
}

void System::replaceProcess(int posicao, const Process_ &value)
{
    this->p.replace(posicao,value);
}

void System::addRAM(int aux)
{
    this->RAM.append(aux);
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

int System::getRAM(int posicao)
{
    return this->RAM[posicao];
}

void System::replaceRAM(int posicao, const int &value)
{
    this->RAM.replace(posicao,value);
}

System::System()
{
    
}
