#include <iostream>
#include <stdexcept>
#include "MinhaInformacao.h"
#include "MatrizEsparsa.h"


using namespace std;

int main()
{
    try
    {
        MinhaInformacao* padrao = new MinhaInformacao(1);
        MatrizEsparsa mat(padrao);

        MinhaInformacao* mi = new MinhaInformacao(5);
        MinhaInformacao* mi2 = new MinhaInformacao(6);
        MinhaInformacao* mi3 = new MinhaInformacao(2);
        MinhaInformacao* mi4 = new MinhaInformacao(100);
        MinhaInformacao* mi5 = new MinhaInformacao(19);

        mat.inserirInfo(2,2,mi);
        mat.inserirInfo(3,3,mi2);
        mat.inserirInfo(5,7,mi3);
        mat.inserirInfo(8,2,mi4);
        mat.inserirInfo(8,5,mi5);

        cout << mat;
    }
    catch(std::invalid_argument e)
    {
        cerr << "\n" << e.what() << "\n";
    }

    return 0;
}
