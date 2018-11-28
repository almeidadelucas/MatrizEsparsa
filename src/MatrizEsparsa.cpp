#include "MatrizEsparsa.h"
#include "Linha.h"
#include <iostream>
#include <stdexcept>

MatrizEsparsa::MatrizEsparsa(Informacao* padrao)
{
    infoPadrao = padrao;
    this->matriz = new ArvoreAVL();;
}

MatrizEsparsa::~MatrizEsparsa()
{
}

bool MatrizEsparsa::temInfo(int l, int c)
{
    if(l < 0 || c < 0)
        throw invalid_argument("Posicao invalida!");
    Linha* linha = (Linha*)matriz->tem(new Linha(l));
    if(linha == NULL)
        return false;

    return linha->temInfoMat(c);
}

Informacao* MatrizEsparsa::getInfo(int l, int c)
{
    if(l < 0 || c < 0)
        throw invalid_argument("Posicao invalida!");

    Linha* linha = (Linha*)matriz->tem(new Linha(l));
    if(linha == NULL)
        return this->infoPadrao->clone();

    Informacao* retorno = linha->getInfoMat(c);
    if(retorno == NULL)
        return this->infoPadrao->clone();

    return linha->getInfoMat(c)->clone();
}

void MatrizEsparsa::inserirInfo(int l, int c, Informacao* i)
{
    if(l < 0 || c < 0)
        throw invalid_argument("Posicao invalida!");

    if(i->compareTo(this->infoPadrao) != 0)
    {
        Linha* linha = (Linha*)matriz->tem(new Linha(l));

        if(linha != NULL)
            matriz->excluirInfo(linha);
        else
            linha = new Linha(l);

        linha->inserirInfoMat(c, i);
        matriz->inserirInfo(linha);
    }
}

void MatrizEsparsa::excluirInfo(int l, int c)
{
    if(l < 0 || c < 0)
        throw invalid_argument("Posicao invalida!");

    Linha* linha = (Linha*)matriz->tem(new Linha(l));

    if(linha != NULL)
    {
        matriz->excluirInfo(linha);

        linha->excluirInfoMat(c);
        if(!linha->estaVazia())
            matriz->inserirInfo(linha);
    }
}

ostream& operator<<(ostream& os, const MatrizEsparsa& mat)
{
    os << *mat.matriz;
}
