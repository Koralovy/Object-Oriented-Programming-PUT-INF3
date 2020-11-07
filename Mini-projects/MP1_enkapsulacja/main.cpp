#include <iostream>
#include <string>
#include <vector>
using namespace std;

//145380 Mod 4 + 1 = 0 + 1 = 1  -> 1.  Ul
class Ul{
public:
    Ul(int startowa_liczba_pszczol, string nazwa){
        this -> liczba_pszczol = startowa_liczba_pszczol;
        this -> nazwa_pasieki = nazwa;
        this -> wskaznik_produkcji = 0;
        this -> ogolna_produkcja = 0;
    }

    bool zmiana(int roznica){
        if(roznica >= -100 && roznica <= 100 && this -> liczba_pszczol + roznica >= 0){
            this -> liczba_pszczol += roznica;
            return true;
        }
        cerr  << "Podano zbyt duza wartosc zmiany! (" << roznica << ")\n";
        return false;
    }

    int podaj_liczbe_pszczol(){
        return this -> liczba_pszczol;
    }

    bool wprowadz_polozenie(string x, string y){
        float vx = stof(x.substr(0, x.size()-1));
        float vy = stof(y.substr(0, y.size()-1));
        if((x.back() == 'N' || x.back() == 'S') && (y.back() == 'E' || y.back() == 'W') && vx >= 0 && vx <= 90 && vy >= 0 && vy <= 180){
            this -> szerokosc_geogr = x;
            this -> dlugosc_geogr = y;
            return true;
        }
        cerr << "Podano nieprawidlowe polozenie\n";
        return false;
    }

    string podaj_polozenie(){
        return this -> szerokosc_geogr + ' ' + this -> dlugosc_geogr;
    }

    bool dodaj_wartosc_roczna(int wartosc){
        this -> ogolna_produkcja += wartosc;
        this -> wartosci_roczne.push_back(wartosc);
        return true;
    }

    double odczytaj_wskaznik(){
        if (this -> wartosci_roczne.size() > 0){
            this -> wskaznik_produkcji = this -> ogolna_produkcja / this -> wartosci_roczne.size();
            return this -> wskaznik_produkcji;
        }
        return 0;
    }

    bool podaj_nazwe(string nowa_nazwa){
        if(nowa_nazwa[0] >= 'A' && nowa_nazwa[0] <= 'Z'){
            this -> nazwa_pasieki = nowa_nazwa;
            return true;
        }
        cerr << "Nieprawidlowa nazwa";
        return false;
    }

    string podaj_nazwe(){
        return this -> nazwa_pasieki;
    }

    double odczytaj_wartosc(){
        this -> wartosc_ula = 0.1 * this -> liczba_pszczol * this -> odczytaj_wskaznik();
        return this -> wartosc_ula;
    }


private:
    int liczba_pszczol;
    string szerokosc_geogr, dlugosc_geogr;
    double wskaznik_produkcji;
    string nazwa_pasieki;
    vector <int> wartosci_roczne;
    int ogolna_produkcja;
    double wartosc_ula;
};

int main(){
    Ul Ul1(89, "Ul1");
    cout << "Pszczol w ulu: " << Ul1.podaj_liczbe_pszczol() << endl;
    Ul1.zmiana(-20);
    cout << "Pszczol w ulu: " << Ul1.podaj_liczbe_pszczol() << endl;
    Ul1.zmiana(-200);
    cout << "Pszczol w ulu: " << Ul1.podaj_liczbe_pszczol() << endl;
    Ul1.dodaj_wartosc_roczna(130);
    Ul1.dodaj_wartosc_roczna(88);
    cout << "Wartosc ula: " << Ul1.odczytaj_wartosc() << endl;
    cout << "Sredni wskaznik roczny: " << Ul1.odczytaj_wskaznik() << endl;
    cout << "Ul nazywa sie: " << Ul1.podaj_nazwe() << endl;
    Ul1.wprowadz_polozenie("32.512N", "179.123E");
    cout << "Ul znajduje się w lokalizacji: " << Ul1.podaj_polozenie() << endl;   
    return 0;
}