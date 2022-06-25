#ifndef STABLO_CPP
#define STABLO_CPP
#include "stablo.h"
#include <iostream>
using namespace std;



template<typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Dodajlist(Tip vrijednost)
{
    Cvor* novi = new Cvor;
    novi->ld = nullptr;
    novi->dd = nullptr;
    novi->vrijednost = vrijednost;
    return novi;
}
template<typename Tip>
void Stablo<Tip>::addPrivate (Tip vrijednost, Cvor* pokazivac)
{
    if(korijen==nullptr) korijen = Dodajlist(vrijednost);
    else
    {
        if(vrijednost>pokazivac->vrijednost)
        {
            if (pokazivac->dd==nullptr) pokazivac->dd = Dodajlist(vrijednost);
            else addPrivate(vrijednost, pokazivac->dd);
        }
        else if(vrijednost<pokazivac->vrijednost)
        {
            if (pokazivac->ld==nullptr) pokazivac->ld = Dodajlist(vrijednost);
            else addPrivate(vrijednost, pokazivac->ld);
        }
    }
}

template<typename Tip>
void Stablo<Tip>::IspisiPrivate (Cvor* pokazivac)
{
    if (korijen==nullptr) cout<<"Stablo je prazno"<<endl;
    else
    {
        if (pokazivac->ld!=nullptr) IspisiPrivate(pokazivac->ld);
        cout<<pokazivac->vrijednost<<" ";
        if (pokazivac->dd!=nullptr) IspisiPrivate(pokazivac->dd);
    }
}
template<typename Tip>
Tip Stablo<Tip>::NajmanjiElementPrivate(Cvor* pokazivac)
{
    if(pokazivac!=nullptr)
    {
        if (pokazivac->ld!=nullptr) return NajmanjiElementPrivate(pokazivac->ld);
        return pokazivac->vrijednost;
    }
}
template<typename Tip>
void Stablo<Tip>::BrisiPrivate(Tip vrijednost, Cvor* pokazivac)
{
    if (korijen->vrijednost == vrijednost) BrisiKorijen();
    else if (vrijednost>pokazivac->dd->vrijednost and pokazivac->dd!=nullptr)
    {
        if (vrijednost==pokazivac->dd->vrijednost) Brisi2(pokazivac,pokazivac->dd,false);
        else BrisiPrivate(vrijednost, pokazivac->dd);
    }
    else if (vrijednost<pokazivac->ld->vrijednost and pokazivac->ld!=nullptr)
    {
        if (vrijednost==pokazivac->ld->vrijednost) Brisi2(pokazivac,pokazivac->ld,true);
        else BrisiPrivate(vrijednost, pokazivac->ld);
    }
    else cout<<"Kljuca nema u stablu"<<endl;
}

template<typename Tip>
void Stablo<Tip>::BrisiKorijen()
{
    Cvor* stari = korijen;
    if (stari->ld == nullptr and stari->dd == nullptr)
    {
        korijen = nullptr;
        delete stari;
    }
    else if (korijen->ld== nullptr and korijen->dd!=nullptr) /// samo lijevo dijete
    {
        korijen = korijen->ld;
        stari->dd = nullptr;
    }
    else if (korijen->ld != nullptr and korijen->dd==nullptr) /// samo desno dijete
    {
        korijen = korijen->dd;
        stari->dd = nullptr;
    }
    else
    {
        Tip najmanjiDesno = NajmanjiElementPrivate(korijen->dd);
        BrisiPrivate(najmanjiDesno, korijen->dd);
        korijen->vrijednost = najmanjiDesno;
    }

}

template<typename Tip>
void Stablo<Tip>::Brisi2 (Cvor* roditelj, Cvor* dijete, bool lijevo)
{
    Cvor* stari;
    if (dijete->ld ==nullptr and dijete->dd==nullptr)
    {
        if(lijevo) roditelj->ld = nullptr;
        else roditelj->dd = nullptr;
        dijete = nullptr;
        delete dijete;
    }
    else if (dijete->ld ==nullptr and dijete->dd!=nullptr) /// ima desno dijete
    {
        if(lijevo) roditelj->ld = dijete->dd;
        else roditelj->dd = dijete->dd;
        dijete->dd = nullptr;
        delete dijete;
    }
    else if (dijete->ld !=nullptr and dijete->dd==nullptr) /// ima lijevo dijete
    {
        if(lijevo) roditelj->ld = dijete->ld;
        else roditelj->dd = dijete->ld;
        dijete->ld = nullptr;
        delete dijete;
    }
    else
    {
        Tip najmanjiDesno = NajmanjiElementPrivate(dijete->dd);
        BrisiPrivate(najmanjiDesno, dijete->dd);
        dijete->vrijednost = najmanjiDesno;
    }


}






#endif // STABLO_CPP
