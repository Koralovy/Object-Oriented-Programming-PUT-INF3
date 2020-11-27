#include "Adres.h"

Adres::Adres()
 : ulica(nullptr), nr_mieszkania(nullptr), kod_pocztowy(nullptr), miasto(nullptr), kraj(nullptr) {
}

Adres::~Adres() {
    if(ulica != nullptr) {
        delete ulica;
        delete nr_mieszkania;
        delete kod_pocztowy;
        delete miasto;
        delete kraj;
    }    
}

Adres::Adres(const Adres &cpy) {
    if(ulica != nullptr) {
        ulica = new string;
        *ulica = *cpy.ulica;
        nr_mieszkania = new string;
        *nr_mieszkania = *cpy.nr_mieszkania;
        kod_pocztowy = new string;
        *kod_pocztowy = *cpy.kod_pocztowy;
        miasto = new string;
        *miasto = *cpy.miasto;
        kraj = new string;
        *kraj = *cpy.kraj;
    }
    else {
        ulica = nullptr;
        nr_mieszkania = nullptr;
        kod_pocztowy = nullptr;
        miasto = nullptr;
        kraj = nullptr;
    }
}

Adres::Adres(Adres &&x) {
    ulica = x.ulica;
    nr_mieszkania = x.nr_mieszkania;
    kod_pocztowy = x.kod_pocztowy;
    miasto = x.miasto;
    kraj = x.kraj;

    x.ulica = nullptr;
    x.nr_mieszkania = nullptr;
    x.kod_pocztowy = nullptr;
    x.miasto = nullptr;
    x.kraj = nullptr;
}

Adres::Adres(string kraj)
 : ulica(nullptr), nr_mieszkania(nullptr), kod_pocztowy(nullptr), miasto(nullptr), kraj(new string) {
     *this -> kraj = kraj;
 }