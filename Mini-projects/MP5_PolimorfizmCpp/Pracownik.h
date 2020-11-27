#ifndef __Pracownik_H__
#define __Pracownik_H__
#include "Osoba.h"
#include <algorithm>
#include <vector>
using namespace std;

class Pracownik: public Osoba{
private:
    vector<string> lista_przedmiotow;

public:
    Pracownik();
    ~Pracownik();
    Pracownik(const Pracownik &cpy);
    Pracownik(Pracownik &&x);
    Pracownik(string przedmiot_podstawowy);
    void wprowadz_przedmiot(string przedmiot);
    void usun_przedmiot(string przedmiot);
    bool czy_prowadzi_przedmiot(string przedmiot);
    string odczytaj_przedmioty();
    virtual string przedstaw();
};

#endif // __Pracownik_H__