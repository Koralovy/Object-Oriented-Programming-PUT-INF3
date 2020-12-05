#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maximum(T const& a, T const& b){
    return a > b ? a : b;
}

template <typename T>
class X {
private:
    T x;
public:
    X(){}
    X(T _x) {
        this -> x = _x;
    }
    T getX() const {
        return x;
    }
    friend ostream& operator << (ostream& os, X const & x) {
        os << x.x;
        return os;
    }
};

template <typename T>
bool operator > (X<T> const &a , X<T> const &b) {
    return a.getX() > b.getX();
}

template <>
bool operator > (X<string> const &a, X<string> const&b) {
    return a.getX().size() > b.getX().size();
}

template <typename T, typename C = X<T> >
class Y {
    T zmienna;
    C klasaX;
};

template <typename T>
class A {
    typename T::id i;
public:
    void f() {i.g();}
};

class B {
public:
    class id {
    public:
        void g() {}
    };
};

auto maxLambda = [](auto a, auto b) {return a > b ? a : b;};
bool b = maxLambda(3, 3.14);
auto c = maxLambda(3, 3.14);

int main()
{
    cout << "Zadanie 1:\n";
    cout << maximum(6, 7) << endl;
    cout << maximum(6.3, 7.3) << endl;
    //blad - dwa rozne typu argumentu, funkcja przyjmuje tylko jeden. cout << maximum(6.5, 7) << endl;
    cout << maximum<double>(4, 5) << endl;
    cout << maximum<double>(4.1, 5.7) << endl;
    cout << maximum<int>(4.6, 3) << endl;
    cout << maximum<double>(4.6, 3) << endl;
    cout << maximum<bool>(4.6, 3) << endl;
    //blad - dwa rozne typu argumentu, funkcja przyjmuje tylko jeden. cout << maximum<string>(4.6, 3) << endl;
    cout << maximum<string>("aaa", "bb") << endl;
    cout << maximum(X<int>(4), X<int>(3)) << endl;
    cout << maximum(X<string>("aaa"), X<string>("bb")) << endl;
    
    Y<int> y;
    Y<int, double> y2;

    A<B> ab;
    ab.f();

    cout << b << " " << c << endl;

    

    return 0;
}