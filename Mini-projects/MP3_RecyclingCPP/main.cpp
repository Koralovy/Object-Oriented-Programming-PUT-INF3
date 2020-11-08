#include <iostream>
#include "Wezel.h"
#include <memory>
using namespace std;

int main()
{
    /*
    for (int i = 0; i < 10; i++) {
        unique_ptr<Wezel>(new Wezel());
        cout << "test" << endl;
    }
    */
   
   /*
    for (int i = 0; i < 10; i++) {
        shared_ptr<Wezel> w1 = make_shared<Wezel>();
        cout << "test" << endl;
    }
    */

   /*
    for (int i = 0; i < 10; i++) {
        shared_ptr<Wezel> w1 = make_shared<Wezel>();
        shared_ptr<Wezel> w2 = make_shared<Wezel>();
        w1 -> next = w2;
        w2 -> next = w1;
    }
    */

    for (int i = 0; i < 10; i++) {
        shared_ptr<Wezel> w1 = make_shared<Wezel>();
        shared_ptr<Wezel> w2 = make_shared<Wezel>();
        w1 -> nextweak = w2;
        w2 -> nextweak = w1;
    }

    //Zad 4: c++ nie posiada wbudowanego grabage collectora, instrukcja unique_ptr pozwala na automatyczna destrukcje obiektu w momencie przejscia poza zasieg/zainteresowanie programu.
    //Zad 6: tak, destrukcja obiektu nastepuje w momencie zakonczenia iteracji, nie od razu po deklaracji ze wzgledu na implementacje shared_ptr.
    //Zad 9: pamiec nie zostaje zwolniona, poniewaz wskaznik shared_ptr<Wezel> next; pomimo braku widocznosci pozostaje ciagle zadeklarowany co uniemozliwa destrukcje zgodnie z dokumentacja "the last remaining shared_ptr owning the object is destroyed;".
    return 0;
}