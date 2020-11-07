#include "UL.h"
#include "Logger.h"
#include <iostream>
#include <utility>
using namespace std;

void foo(Ul ul) //14
{
    cout << "Wartosc z foo: " << ul.podaj_liczbe_pszczol() << endl;
}

void bar(const Ul &ul)
{
    //cout << "Wartosc z bar: " << ul.podaj_liczbe_pszczol() << endl;
}

void baz(Ul &ul)
{
    cout << "Wartosc z baz: " << ul.podaj_liczbe_pszczol() << endl;
}

void qux(Ul &&ul)
{
    cout << "Wartosc z baz: " << ul.podaj_liczbe_pszczol() << endl;
}

void z15(Ul &ul) //15
{
    cout << "Kopiopwanie UL1, ...    ";
    foo(ul);
}

void z16(Ul &&ul) //16
{
    cout << "Przenoszenie UL1, ...    ";
    foo(ul);
}

int main()
{
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

    cout << "Zad 14: ";
    foo(Ul1);

    cout << "Zad 15: ";
    z15(Ul1);

    cout << "Zad 16: ";
    z16(move(Ul1));
    
    cout << "Zad 17: ";
    foo({15, "przeniesiony", 100});

    //Zad 18: the object has type qualifiers that are not compatible with the member function "Ul::podaj_liczbe_pszczol" -- object type is: const Ul
    //Zad 20: 15+16 dziala, 17 zwraca cannot bind non-const lvalue reference of type 'Ul&' to an rvalue of type 'Ul'
    //Zad 22: 15+16 - cannot bind rvalue reference of type 'Ul&&' to lvalue of type 'Ul'; 17 dziala

    //Ul1.log("xyz");
    //Zad 26: Metody nie mozna wywolac, poniewaz funkcja jest niedostepna ze wzgledu na domyslne dziedziczenie prywatne, do ktorego moga sie odwolac tylko metody zawarte w klasie pochodnej
    //Zad 29: mialem swiadomosc charakterystyki konstruktorow i od razu uwzglednilem problemy. Kompilacja zakonczona pozytywnie.

    for(int i=0; 10>i; i++){
        Ul1.zmiana(20);
        Ul1.print_time();
    }

    //Zad 32: W przypadku dziedziczenia wielopoziomowego moze wystapic problem wielokrotnego definiowania tej samej metody. Java nie pozwala na takie rozwiazanie, zawiera za to system super-/subclass 
   
   cout << "Zakonczenie programu" << endl;
   return 0;
}