#include "Pracownik.h"

Pracownik::Pracownik() {
}

Pracownik::~Pracownik() {
    lista_przedmiotow.clear();
}

Pracownik::Pracownik(const Pracownik &cpy) {
    vector<string> lista_przedmiotow(cpy.lista_przedmiotow);
}

Pracownik::Pracownik(Pracownik &&x) {
    lista_przedmiotow = move(x.lista_przedmiotow);
    lista_przedmiotow.clear();
}

Pracownik::Pracownik(string przedmiot_podstawowy) {
    this -> lista_przedmiotow.push_back(przedmiot_podstawowy);
}

void Pracownik::wprowadz_przedmiot(string przedmiot) {
    this -> lista_przedmiotow.push_back(przedmiot);
}

void Pracownik::usun_przedmiot(string przedmiot) {
    this -> lista_przedmiotow.erase(remove(this -> lista_przedmiotow.begin(), this -> lista_przedmiotow.end(), przedmiot), this -> lista_przedmiotow.end());
}

bool Pracownik::czy_prowadzi_przedmiot(string przedmiot) {
    vector<string>::iterator it = find(this -> lista_przedmiotow.begin(), this -> lista_przedmiotow.end(), przedmiot);
    if (it != this -> lista_przedmiotow.end())
        return true;
    else
        return false;
}

string Pracownik::odczytaj_przedmioty() {
    string tmp = "";
    for (auto x: this -> lista_przedmiotow)
		tmp += x + ", ";
    tmp += "\n";
    return tmp;
}
string Pracownik::przedstaw() {
     return odczytaj_imie_i_nazwisko() + "\nUrodzony: " + odczytaj_date_urodzenia() + "\nMiejsce zamieszkania: " + odczytaj_miejsce_zamieszkania() +"\n" + "Przedmioty: " + odczytaj_przedmioty();
}