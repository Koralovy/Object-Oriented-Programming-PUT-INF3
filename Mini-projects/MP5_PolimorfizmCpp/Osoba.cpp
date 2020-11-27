#include "Osoba.h"

Osoba::Osoba()
 : imie(nullptr), nazwisko(nullptr), data_urodzenia(nullptr), adres(nullptr) {
}

Osoba::~Osoba() {
    if(imie != nullptr){
        delete imie;
    }
    if(nazwisko != nullptr){
        delete nazwisko;
    }
    if(data_urodzenia != nullptr){
        delete data_urodzenia;
    }
    if(adres != nullptr){
        delete adres;
    }
}

Osoba::Osoba(const Osoba &cpy) {
    if(imie != nullptr) {
        imie = new string;
        *imie = *cpy.imie;
    }
    else
        imie = nullptr;
    if(nazwisko != nullptr) {
        nazwisko = new string;
        *nazwisko = *cpy.nazwisko;
    }
    else
        nazwisko = nullptr;
    if(data_urodzenia != nullptr) {
        data_urodzenia = new string;
        *data_urodzenia = *cpy.data_urodzenia;
    }
    else
        data_urodzenia = nullptr;
    if(adres != nullptr) {
        adres = new Adres;
        adres = cpy.adres;
    }
    else
        adres = nullptr;

}

Osoba::Osoba(Osoba &&x) {
    imie = x.imie;
    nazwisko = x.nazwisko;
    data_urodzenia = x.data_urodzenia;
    adres = x.adres;

    x.imie = nullptr;
    x.nazwisko = nullptr;
    x.data_urodzenia = nullptr;
    x.adres = nullptr;
}

Osoba::Osoba(string nazwisko)
 : imie(nullptr), nazwisko(new string), data_urodzenia(nullptr), adres(nullptr) {
     *this -> nazwisko = nazwisko;
}

void Osoba::ustaw_imie_i_nazwisko(string imie, string nazwisko) {
    if (this -> imie == nullptr) {
        this -> imie = new string;
        this -> nazwisko = new string;
    }
    *this -> imie = imie;
    *this -> nazwisko = nazwisko;
}

string Osoba::odczytaj_imie_i_nazwisko() {
    if (this -> imie == nullptr)
        return "";
    return *this -> imie + " " + *this -> nazwisko;
}

int Osoba::ustaw_date_urodzenia(string data, bool skip) {
    string tmp;
    if (skip == false){
        cout << "Czy wskazana data jest poprawna? [Y/N] " << data << endl;
        cin >> tmp;
    }
    if (tmp == "Y" || skip == true) {
        if (this -> data_urodzenia == nullptr)
            this -> data_urodzenia = new string;
        *this -> data_urodzenia = data;
        return 0;
    }
    else if (tmp == "N") {
        cout << "Pominieto zmiane daty" << endl;
        return 0;
    }
    else {
        cerr << "Niepoprawna operacja ustaw_date_urodzenia" << endl;
        return 1;
    }
}

string Osoba::odczytaj_date_urodzenia() {
    if (this -> data_urodzenia == nullptr)
        return "";
    return *this -> data_urodzenia;
}
    
int Osoba::ustaw_miejsce_zamieszkania(string ulica, string nr_mieszkania, string kod_pocztowy, string miasto, string kraj, bool skip) {
    string tmp;
    if (skip == false){
        cout << "Czy wskazane dane sa poprawne? [Y/N] " << ulica << " " <<  nr_mieszkania <<  " ";
        cout << kod_pocztowy << " " << miasto << " " << kraj << endl;
        cin >> tmp;
    }
    if (tmp == "Y" || skip == true) {
        if(this -> adres == nullptr) {
            adres = new Adres;
            adres -> ulica = new string;
            adres -> nr_mieszkania = new string;
            adres -> kod_pocztowy = new string;
            adres -> miasto = new string;
            adres -> kraj = new string;
        }
        *this -> adres -> ulica = ulica;
        *this -> adres -> nr_mieszkania = nr_mieszkania;
        *this -> adres -> kod_pocztowy = kod_pocztowy;
        *this -> adres -> miasto = miasto;
        *this -> adres -> kraj = kraj;
        return 0;
    }
    else if (tmp == "N") {
        cout << "Pominieto zmiane miejsca zamieszkania" << endl;
        return 0;
    }
    else {
        cerr << "Niepoprawna operacja ustaw_miejsce_zamieszkania" << endl;
        return 1;
    }
}

string Osoba::odczytaj_miejsce_zamieszkania() {
    if(adres == nullptr)
        return "";
    return *this -> adres -> ulica + " " + *this -> adres -> nr_mieszkania + " " + *this -> adres -> kod_pocztowy + " " + *this -> adres -> miasto + " " + *this -> adres -> kraj;
}

string Osoba::przedstaw()  {
    return odczytaj_imie_i_nazwisko() + "\nUrodzony/urodzona: " + odczytaj_date_urodzenia() + "\nMiejsce zamieszkania: " + odczytaj_miejsce_zamieszkania() +"\n";
}
