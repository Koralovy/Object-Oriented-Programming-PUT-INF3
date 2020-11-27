#ifndef __Student_H__
#define __Student_H__
#include "Osoba.h"
#include <unordered_map>
#include <string>
using namespace std;

class Student: public Osoba{
private:
    unordered_map<string,int> lista_ocen;

public:
    Student();
    ~Student();
    Student(const Student &cpy);
    Student(Student &&x);
    Student(string przedmiot_startowy);
    void dodaj_ocene(string przedmiot, int ocena);
    int odczytaj_ocene(string przedmiot);
    string odczytaj_liste_ocen();
    virtual string przedstaw();
};

#endif // __Student_H__