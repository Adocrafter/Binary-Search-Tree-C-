#ifndef STABLO_H
#define STABLO_H
using namespace std;
template<typename Tip>
class Stablo
{
private:
    struct Cvor
    {
        Cvor* ld;
        Cvor* dd;
        Tip vrijednost;
    };
    Cvor* korijen;
    Cvor* Dodajlist(Tip vrijednost);
    void addPrivate(Tip vrijednost, Cvor* pokazivac);
    void IspisiPrivate (Cvor* pokazivac);
    Tip NajmanjiElementPrivate(Cvor* pokazivac);
    void BrisiPrivate(Tip vrijednost, Cvor* pokazivac);
    void BrisiKorijen();
    void Brisi2 (Cvor* roditelj, Cvor* dijete, bool lijevo);

public:
    Stablo() {korijen=nullptr;}
    void add (Tip vrijednost){addPrivate(vrijednost,korijen);}
    void Ispisi(){IspisiPrivate(korijen);}
    Tip NajmanjiElement(){NajmanjiElementPrivate(korijen);}
    void Brisi(Tip vrijednost){BrisiPrivate(vrijednost, korijen);}


};






#include "stablo.cpp"
#endif // STABLO_H
