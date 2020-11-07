#include <iostream>
using namespace std;

class Samochod{
private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kliometrow;
    string model;

public:
    Samochod::Samochod()
     : pojemnosc_baku(0), poziom_paliwa(0), liczba_kliometrow(0), model("") {}
    Samochod::Samochod(string model, float pojemnosc_baku)
     : pojemnosc_baku(pojemnosc_baku), poziom_paliwa(0), liczba_kliometrow(0), model(model) {}


};


int main()
{

    return 0;
}