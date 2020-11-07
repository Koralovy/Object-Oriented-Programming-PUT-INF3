#include "Stopper.h"
#include <iostream>
using namespace std;

void Stopper::start(){
    cerr << "Rozpoczecie pomiaru" << endl;
    t = clock();
}

void Stopper::stop(){
    cerr << "Zakonczenie pomiaru" << endl;
    t = clock() - t;
}

void Stopper::reset(){
    cerr << "Zatrzymanie stopera" << endl;
    t = 0;
}

void Stopper::print_time(){
    cout << "Wynik pomiaru (s): " << ((float)t)/CLOCKS_PER_SEC << endl;
}