#ifndef __UL_H__
#define __UL_H__

#include "Logger.h"
#include "Stopper.h"
#include <string>
#include <vector>
using namespace std;

class Ul : Logger, public Stopper{
private:
    int *liczba_pszczol;
    string *szerokosc_geogr;
    string *dlugosc_geogr;
    double *wskaznik_produkcji;
    string *nazwa_pasieki;
    vector<int> wartosci_roczne;
    int *ogolna_produkcja;
    double *wartosc_ula;
    
public:
    Ul(int startowa_liczba_pszczol, string nazwa);
    ~Ul();
    Ul(const Ul &cpy);
    Ul(Ul &&x);
    Ul(int liczba_pszczol, string nazwa, double wartosc_ula);
    bool zmiana(int roznica);
    int podaj_liczbe_pszczol();
    bool wprowadz_polozenie(string x, string y);
    string podaj_polozenie();
    bool dodaj_wartosc_roczna(int wartosc);
    double odczytaj_wskaznik();
    bool zmien_nazwe(string nowa_nazwa);
    string podaj_nazwe();
    double odczytaj_wartosc();
};

#endif // __UL_H__