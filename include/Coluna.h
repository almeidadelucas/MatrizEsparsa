#ifndef COLUNA_H
#define COLUNA_H
#include "Informacao.h"
#include <string>
#include <iostream>
#include <stdexcept>

class Coluna : public Informacao
{
    public:
        Coluna(int, Informacao*);
        virtual ~Coluna();
        int getColuna();
        int compareTo(Informacao*);
        void setInfoMat(Informacao*);
        Informacao* getInfoMat();
        std::string toString();
        Informacao* clone();
    private:
        int coluna;
        Informacao* infoMat;
};

#endif // COLUNA_H
