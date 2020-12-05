#include "Osoba.h"
#include "Pracownik.h"
#include "Student.h"
#include "FabrykaOsob.h"
#include "FabrykaPracownikow.h"
#include "FabrykaStudentow.h"
#include <map>
#include <vector>

void ofoo(Osoba &os) {
    cout << os.przedstaw();
}
void obar(Osoba *os) {
    cout << os -> przedstaw();
}

void sfoo(Student &os) {
    cout << os.przedstaw();
}
void sbar(Student *os) {
    cout << os -> przedstaw();
}

void pfoo(Pracownik &os) {
    cout << os.przedstaw();
}
void pbar(Pracownik *os) {
    cout << os -> przedstaw();
}

int main()
{
    //Zrobione do 23 włącznie
    Student jan;
    jan.dodaj_ocene("Jananatyka", 5);
    jan.ustaw_imie_i_nazwisko("Jan", "Student");
    jan.ustaw_date_urodzenia("11-11-2011", true);
    jan.ustaw_miejsce_zamieszkania("Ulica", "0a", "11-111", "Miasto", "Kraj", true);
    cout << jan.przedstaw() << endl;
    
    Pracownik albert;
    albert.wprowadz_przedmiot("Jananatyka");
    albert.wprowadz_przedmiot("Przedmiot");
    albert.usun_przedmiot("Przedmiot");
    cout << "Prowadzenie przedmiotu przedmiot: " << albert.czy_prowadzi_przedmiot("Przedmiot") << endl;
    albert.ustaw_imie_i_nazwisko("Adam", "Pracownik");
    albert.ustaw_date_urodzenia("11-11-2011", true);
    albert.ustaw_miejsce_zamieszkania("Ulica", "0a", "11-111", "Miasto", "Kraj", true);
    cout << albert.przedstaw() << endl;
    /*
    cout << "ofoo: ";
    ofoo(adam);
    cout << "\nobar: ";
    obar(&adam);
    
    cout << "sfoo: ";
    ofoo(jan);
    cout << "\nsbar: ";
    obar(&jan);

    cout << "pfoo: ";
    ofoo(albert);
    cout << "\npbar: ";
    obar(&albert);
    */
    //Z12: Wszystkie wywolania dzialaja zgodnie z oczekiwaniami wywołują metodę przedstaw
    //Z14: Specyfikator virtual usuwa możliwość wielokrotnego występowania definicji klasy bazowej (Osoba) poprzez jej wirtualizacje. Wywołania poprawne

    //Z15: Rzutowania kompilują się poprawnie, daja one dostep takze do metod, ktore nie powinny byc wywołane.
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1);
    //Osoba *o3 = new Osoba;
    //Pracownik *p2 = static_cast<Pracownik *>(o3);

    //Z16: Wyrażenie w komentarzu nie jest poprawne - a value of type "Osoba *" cannot be used to initialize an entity of type "Pracownik *"
    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3);
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4);

    /*
    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5);
    if (p5 == nullptr) cout << "Blad rzutowania!" << endl;
    else p5 -> odczytaj_przedmioty();
    */
    //Z17: test dynamic_cast!=nullptr jest roznie interpretowane w roznych wersjach jezyka. Czasami może zwracać dodatkowe błędy i zagłębia się we wszystkie klasy.
    //Z18-19: funkcja Osoba::przedstaw staje sie wirutalna co uniemozliwia jej wywolanie
    //Z22: program dziala pozornie w pełni poprawnie, elementy deklarowane od z15 nie wywolują destruktora, ponieważ nie są zaalokowane slowem virtual.
    //Z23: usunięcie obiektu klasy pochodnej przestaje wywoływać niezdefiniowane zachowanie.
    FabrykaPracownikow* fp = new FabrykaPracownikow();
    FabrykaStudentow* fo = new FabrykaStudentow();
    Pracownik z = *fp->utworz();
    cout << "Bezimienny pracownik z fabryki" << z.przedstaw() << endl;

    vector<Student> klasa;
    vector<Pracownik> firma;

    while(1){
        string tmp;
        cout << "Menu o dzialaniu opisanym w instrukcji: " << endl;
        cin >> tmp;
        if (tmp=="pracownik") {
            string imie, nazwisko;
            firma.push_back(*fp->utworz());
            cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            firma.back().ustaw_imie_i_nazwisko(imie, nazwisko);

        }
        else if (tmp=="student") {
            string imie, nazwisko;
            klasa.push_back(*fo->utworz());
            cout << "Podaj imie: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;
            klasa.back().ustaw_imie_i_nazwisko(imie, nazwisko);
        }
        else if (tmp=="wyswietl") {
            cout << "Pracownicy: " << endl;
            for (Pracownik& x : firma) cout << x.przedstaw() << endl;
            cout << "Studenci: " << endl;
            for (Student& x : klasa) cout << x.przedstaw() << endl;
        }
        else if (tmp=="wyjscie") {
            cout << "Koniec petli" << endl;
            break;
        }
        else {
            cout << "Brak odpowiedniego wejscia, powtarzam" << endl;
        }

    }
    map<string, FabrykaOsob*> m;
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    //Polecenie po raz kolejny zapisane zostalo w kolejnosci nielogicznej, gdyz menu stworzylem juz w punkcie 28 na wlasny i podobny sposob.
    //Ponowne poprawianie tych instrukcji i agregowanie studenta i pracownika to jednego if jest bezcelowe, wiec zostalo pominiente zeby nie modyfikowac po raz kolejny dodatkowo kodu.
    return 0;
}