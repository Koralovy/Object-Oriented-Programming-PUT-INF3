#include "Student.h"

Student::Student() {
}

Student::~Student() {
    lista_ocen.clear();
}

Student::Student(const Student &cpy) {
    unordered_map<string,int> lista_ocen(cpy.lista_ocen);
}

Student::Student(Student &&x) {
    lista_ocen = move(x.lista_ocen);
    lista_ocen.clear();
}

Student::Student(string przedmiot_startowy) {
    this -> lista_ocen.emplace(przedmiot_startowy, 0);
}

void Student::dodaj_ocene(string przedmiot, int ocena) {
    unordered_map<string,int>::iterator it;
    it = this -> lista_ocen.find(przedmiot);
    if (it != lista_ocen.end())
        lista_ocen.erase(it);
    this -> lista_ocen.emplace(przedmiot, ocena);
}

int Student::odczytaj_ocene(string przedmiot) {
    unordered_map<string,int>::iterator it;
    it = this -> lista_ocen.find(przedmiot);
    if (it != lista_ocen.end())
        return it -> second;
    return -1;
}

string Student::odczytaj_liste_ocen() {
    string tmp = "";
    for (auto const x: this -> lista_ocen)
		tmp += x.first + ": " + to_string(x.second)  + "\n";
    return tmp;
}

string Student::przedstaw() {
     return odczytaj_imie_i_nazwisko() + "\nUrodzony: " + odczytaj_date_urodzenia() + "\nMiejsce zamieszkania: " + odczytaj_miejsce_zamieszkania() +"\n" + "Oceny:\n" + odczytaj_liste_ocen();
}