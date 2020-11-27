#ifndef __Adres_H__
#define __Adres_H__
#include <string>
using namespace std;

class Adres{
private:
    string *ulica;
    string *nr_mieszkania;
    string *kod_pocztowy;
    string *miasto;
    string *kraj;
    friend class Osoba;
public:
    Adres();
    virtual ~Adres();
    Adres(const Adres &cpy);
    Adres(Adres &&x);
    Adres(string kraj);
};

#endif // __Adres_H__