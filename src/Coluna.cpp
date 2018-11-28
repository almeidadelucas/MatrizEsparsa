#include "Coluna.h"
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

Coluna::Coluna(int c, Informacao* info)
{
    this->coluna = c;
    this->infoMat = info;
}

Coluna::~Coluna()
{
}

int Coluna::getColuna()
{
    return this->coluna;
}

Informacao* Coluna::getInfoMat()
{
    return this->infoMat;
}

int Coluna::compareTo(Informacao* info)
{
    if(info == NULL)
        throw invalid_argument("A informacao nao pode ser nula");

    Coluna* c = (Coluna*)info;

    if(this->coluna == c->getColuna())
        return 0;
    else
        if(this->coluna < c->getColuna())
            return -1;
    return 1;
}

void Coluna::setInfoMat(Informacao* info)
{
    if(info == NULL)
        throw invalid_argument("A informacao nao pode ser nula!");

    this->infoMat = info;
}

string Coluna::toString()
{
    stringstream ss;
    ss << "(" << this->coluna << "->";
    ss << this->infoMat->toString() << ") ";
    return ss.str();
}

Informacao* Coluna::clone()
{
}
