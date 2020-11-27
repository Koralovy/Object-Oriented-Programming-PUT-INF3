#ifndef __Osoba_H__
#define __Osoba_H__
#include "Adres.h"
#include <iostream>
#include <string>
using namespace std;

class Osoba{
private:
    string *imie;
    string *nazwisko;
    string *data_urodzenia;
    Adres *adres;

public:
    Osoba();
    virtual ~Osoba();
    Osoba(const Osoba &cpy);
    Osoba(Osoba &&x);
    Osoba(string nazwisko);
    void ustaw_imie_i_nazwisko(string imie, string nazwisko);
    string odczytaj_imie_i_nazwisko();
    int ustaw_date_urodzenia(string data, bool skip);
    string odczytaj_date_urodzenia();
    int ustaw_miejsce_zamieszkania(string ulica, string nr_mieszkania, string kod_pocztowy, string miasto, string kraj, bool skip);
    string odczytaj_miejsce_zamieszkania();
    virtual string przedstaw() = 0;
};

#endif // __Osoba_H__