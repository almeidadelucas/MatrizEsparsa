#include "MinhaInformacao.h"
#include <informacao.h>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

MinhaInformacao::MinhaInformacao(int cod)
{
    this->codigo = cod;
}

MinhaInformacao::~MinhaInformacao()
{

}

int MinhaInformacao::getCodigo()
{
    return this->codigo;
}

int MinhaInformacao::compareTo(Informacao* info)
{
    if(info == NULL)
        throw invalid_argument("A informa��o n�o pode ser nula");

    MinhaInformacao* mi = (MinhaInformacao*)info;

    if(this->codigo == mi->getCodigo())
        return 0;
    else
        if(this->codigo < mi->getCodigo())
            return -1;
    return 1;
}

string MinhaInformacao::toString()
{
    stringstream ss;
    ss << this->codigo;
    return ss.str();
}

Informacao* MinhaInformacao::clone()
{
    return new MinhaInformacao(this->getCodigo());
}

