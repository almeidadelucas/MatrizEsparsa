#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Informacao.h"

class MatrizEsparsa
{
    public:
        MatrizEsparsa(Informacao* infoPadrao);
        virtual ~MatrizEsparsa();
        bool temInfo(int, int);
        Informacao* getInfo(int, int);
        void inserirInfo(int, int, Informacao*);
        void excluirInfo(int, int);
        friend ostream& operator<<(ostream&, const MatrizEsparsa&);
    private:
        ArvoreAVL* matriz;
        Informacao* infoPadrao;
};

#endif // MATRIZESPARSA_H
