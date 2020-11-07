#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Samochod{
private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kliometrow;
    string model;

public:
    Samochod()
     : pojemnosc_baku(0), poziom_paliwa(0), liczba_kliometrow(0), model("") {}
    Samochod(float pojemnosc_baku, string model)
     : pojemnosc_baku(pojemnosc_baku), poziom_paliwa(0), liczba_kliometrow(0), model(model) {}

    float wypisz_pojemnosc_baku() const{
        return pojemnosc_baku;
    }
    
    float wypisz_poziom_paliwa() const{
        return poziom_paliwa;
    }

    unsigned int wypisz_liczba_kliometrow() const{
        return liczba_kliometrow;
    }

    void zatankuj(float ile){
        this -> poziom_paliwa += ile;
    }

    void rewizja(string ver){
        this -> model += " v" + ver;
    }

    string wypisz_model() const{
        return model;
    }

    void dodaj_przebieg(unsigned int km){
		this -> liczba_kliometrow += km;
	}

    operator bool () const{
        if(model.size() != 0 && pojemnosc_baku > 0)
            return true;
        return false;
    }

    bool operator !() const{
        if(model.size() != 0 && pojemnosc_baku > 0)
            return false;
        return true;
    }

    //Zad 8: slowo kluczowe friend zostaje wykorzystane celem udzielenia dostepu publicznego do modyfikacji operatora ostream
    friend ostream & operator << (ostream &os, const Samochod &samochod){
        os << samochod.model << " " << samochod.poziom_paliwa << "\n";
        return os;
    }
    
    //Zad 9: w czasie kompilacji wiadoma informacja jest, ze w elemencie nie bedzie wymagany zapis, wiec kod maszynowy moze zostac jeszcze bardziej zoptymalizowany
    bool operator < (const Samochod &samochod) const{
        return this -> model <samochod.model;
    }

    struct cmp {
        bool operator() (const Samochod &a, const Samochod &b) const{
            return a.wypisz_pojemnosc_baku() < b.wypisz_pojemnosc_baku();
        }
    };

    Samochod& operator ++(){
		this -> dodaj_przebieg(1);
		return *this;
	}

	Samochod operator ++(int){
		Samochod tmp = *this;
		this -> dodaj_przebieg(1);
		return tmp;
	}

    //operator rewizji wersji samochodu w nazwie
    Samochod operator ,(string ver){
        this -> rewizja(ver);
		return *this;
    }

    //operator tankowania
    Samochod operator |=(float a){
        this -> zatankuj(a);
		return *this;
    }

};

int main()
{
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
    if(s1)
        cout << "test s1 - przyklad poprawny" << endl;
    if(!s1)
        cout << "test s1 - przyklad poprawny" << endl;
    if(s2)
        cout << "test s2 - przyklad z pojemnosc_baku = 0" << endl;
    if(!s2)
        cout << "test !s2 - przyklad z pojemnosc_baku = 0" << endl;
    if(s3)
        cout << "test s3 - przyklad z pustym stringiem" << endl;
    if(!s3)
        cout << "test !s3 - przyklad z pustym stringiem" << endl;
    cout << endl;

    cout << "Vector: " << endl;
    vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it;
    }
    cout << endl;
    
    cout << "Set: " << endl;
    set<Samochod, Samochod::cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it;
    }
    cout << endl;
    
    cout << "Tankowanie:" << endl << "stan przed: ";
    cout << s1.wypisz_poziom_paliwa();
    s1|=3;
    cout << ", stan po: " << s1.wypisz_poziom_paliwa() << endl << endl;
    

    cout << "Rewizja s1, nowy model to: ";
    s1,"3";
    cout << s1.wypisz_model() << endl;

    cout << endl << "Koniec programu";
    return 0;
}