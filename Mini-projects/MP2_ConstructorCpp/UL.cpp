#include "UL.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;


Ul::Ul(int startowa_liczba_pszczol, string nazwa)   //konstruktor
 : Logger(true), Stopper(), liczba_pszczol(new int), szerokosc_geogr(nullptr), dlugosc_geogr(nullptr), wskaznik_produkcji(nullptr), nazwa_pasieki(new string), ogolna_produkcja(nullptr), wartosc_ula(nullptr){
    reset();
    log("Wywolanie konstruktora");
    *this -> liczba_pszczol = startowa_liczba_pszczol;
    *this -> nazwa_pasieki = nazwa;
}

Ul::~Ul(){  //destruktor
    log("Wywolanie destruktora");
    delete liczba_pszczol;
    if(szerokosc_geogr != nullptr)
        delete szerokosc_geogr;
    if(dlugosc_geogr != nullptr)
        delete dlugosc_geogr;
    if(wskaznik_produkcji != nullptr)
        delete wskaznik_produkcji;
    delete nazwa_pasieki;
    if(ogolna_produkcja != nullptr)
        delete ogolna_produkcja;
    if(wartosc_ula != nullptr)
        delete wartosc_ula;
    wartosci_roczne.clear();
}

Ul::Ul(const Ul &cpy) : Logger(true){   //kopiujacy
    log("Wywolanie konstruktora kopiujacego");
    liczba_pszczol = new int;
    *liczba_pszczol = *cpy.liczba_pszczol;
    if(cpy.szerokosc_geogr != nullptr){
        szerokosc_geogr = new string;
        *szerokosc_geogr = *cpy.szerokosc_geogr;
    }
    else
        szerokosc_geogr = nullptr;
    if(cpy.dlugosc_geogr != nullptr){
        dlugosc_geogr = new string;
        *dlugosc_geogr = *cpy.dlugosc_geogr;
    }
    else
        dlugosc_geogr = nullptr;
    if(cpy.wskaznik_produkcji != nullptr){
        wskaznik_produkcji = new double;
        *wskaznik_produkcji = *cpy.wskaznik_produkcji;
    }
    else
        wskaznik_produkcji = nullptr;
    nazwa_pasieki = new string;
    *nazwa_pasieki = *cpy.nazwa_pasieki;
    if(cpy.wskaznik_produkcji != nullptr){
        wskaznik_produkcji = new double;
        *wskaznik_produkcji = *cpy.wskaznik_produkcji;
    }
    else
        wskaznik_produkcji = nullptr;
    if(cpy.ogolna_produkcja != nullptr){
        ogolna_produkcja = new int;
        *ogolna_produkcja = *cpy.ogolna_produkcja;
    }
    else
        ogolna_produkcja = nullptr;
    if(cpy.wartosc_ula != nullptr){
        wartosc_ula = new double;
        *wartosc_ula = *cpy.wartosc_ula;
    }
    else
        wartosc_ula = nullptr;
    vector<int> wartosci_roczne(cpy.wartosci_roczne);
};

Ul::Ul(Ul &&x) : Logger(true){ //przenoszący
    log("Wywolanie konstruktora przenoszacego");
    liczba_pszczol = x.liczba_pszczol;
    szerokosc_geogr = x.szerokosc_geogr;
    dlugosc_geogr = x.dlugosc_geogr;
    wskaznik_produkcji = x.wskaznik_produkcji;
    nazwa_pasieki = x.nazwa_pasieki;
    ogolna_produkcja = x.ogolna_produkcja;
    wartosc_ula = x.wartosc_ula;
    wartosci_roczne = move(x.wartosci_roczne);

    x.liczba_pszczol = nullptr;
    x.szerokosc_geogr = nullptr;
    x.dlugosc_geogr = nullptr;
    x.wskaznik_produkcji = nullptr;
    x.nazwa_pasieki = nullptr;
    x.ogolna_produkcja = nullptr;
    x.wartosc_ula = nullptr;
    wartosci_roczne.clear();
}

Ul::Ul(int liczba_pszczol, string nazwa, double wartosc_ula)   //konwertujacy
 : Logger(true), liczba_pszczol(new int), szerokosc_geogr(nullptr), dlugosc_geogr(nullptr), wskaznik_produkcji(nullptr), nazwa_pasieki(new string), ogolna_produkcja(nullptr), wartosc_ula(new double){
    log("Wywolanie konstruktora konwertujacego");
    *this -> liczba_pszczol = liczba_pszczol;
    *this -> nazwa_pasieki = "konwert_"+nazwa;
    *this -> wartosc_ula = wartosc_ula;
}

bool Ul::zmiana(int roznica){
    start();
    log("Wywolanie metody zmiana");
    if(roznica >= -100 && roznica <= 100 && this -> liczba_pszczol + roznica >= 0){
        *this -> liczba_pszczol += roznica;
        return true;
    }
    cerr  << "Podano zbyt duza wartosc zmiany! (" << roznica << ")\n";
    stop();
    return false;
}

int Ul::podaj_liczbe_pszczol(){
    start();
    log("Wywolanie metody podaj_liczbe_pszczol");
    stop();
    return *this -> liczba_pszczol;
}

bool Ul::wprowadz_polozenie(string x, string y){
    start();
    log("Wywolanie metody wprowadz_polozenie");
    float vx = stof(x.substr(0, x.size()-1));
    float vy = stof(y.substr(0, y.size()-1));
    if(szerokosc_geogr == nullptr)
        szerokosc_geogr = new string;
    if(dlugosc_geogr == nullptr)
        dlugosc_geogr = new string;    
    if((x.back() == 'N' || x.back() == 'S') && (y.back() == 'E' || y.back() == 'W') && vx >= 0 && vx <= 90 && vy >= 0 && vy <= 180){
        *this -> szerokosc_geogr = x;
        *this -> dlugosc_geogr = y;
        stop();
        return true;
    }
    cerr << "Podano nieprawidlowe polozenie\n";
    stop();
    return false;
}

string Ul::podaj_polozenie(){
    start();
    log("Wywolanie metody podaj_polozenie");
    if (szerokosc_geogr != nullptr && dlugosc_geogr != nullptr){
        stop();
        return *this -> szerokosc_geogr + ' ' + *this -> dlugosc_geogr;
    }
    stop();
    return "Polozenie nieznane";
}

bool Ul::dodaj_wartosc_roczna(int wartosc){
    start();
    log("Wywolanie metody dodaj_wartosc_roczna");
    if(ogolna_produkcja == nullptr){
        ogolna_produkcja = new int;
        *this -> ogolna_produkcja = 0;
    }
    *this -> ogolna_produkcja += wartosc;
    this -> wartosci_roczne.push_back(wartosc);
    stop();
    return true;
}

double Ul::odczytaj_wskaznik(){
    start();
    log("Wywolanie metody odczytaj_wskaznik");
    if(ogolna_produkcja == nullptr){
        ogolna_produkcja = new int;
        *this -> ogolna_produkcja = 0;
    }
    if(wskaznik_produkcji == nullptr){
        wskaznik_produkcji = new double;
        *this -> wskaznik_produkcji = 0;
    }
    if (this -> wartosci_roczne.size() > 0){
        *this -> wskaznik_produkcji = *this -> ogolna_produkcja / this -> wartosci_roczne.size();
        return *this -> wskaznik_produkcji;
    }
    stop();
    return false;
}

bool Ul::zmien_nazwe(string nowa_nazwa){
    start();
    log("Wywolanie metody zmien_nazwe");
    if(nowa_nazwa[0] >= 'A' && nowa_nazwa[0] <= 'Z'){
        *this -> nazwa_pasieki = nowa_nazwa;
        return true;
    }
    cerr << "Nieprawidlowa nazwa" << endl;
    stop();
    return false;
}

string Ul::podaj_nazwe(){
    start();
    log("Wywolanie metody podaj_nazwe");
    stop();
    return *this -> nazwa_pasieki;
}

double Ul::odczytaj_wartosc(){
    start();
    log("Wywolanie metody odczytaj_wartosc");
    if(wartosc_ula == nullptr){
        wartosc_ula = new double;
        *this -> wartosc_ula = 0;
    }
    *this -> wartosc_ula = 0.1 * *this -> liczba_pszczol * this -> odczytaj_wskaznik();
    stop();
    return *this -> wartosc_ula;
}