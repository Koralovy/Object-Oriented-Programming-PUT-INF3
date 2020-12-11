#include <iostream>
#include <exception>
#include <vector>
#include <string>
using namespace std;

class StackException : public exception {
public:
    StackException() {}
    virtual const char* what() const noexcept override {
        return "Bledna operacja na stosie!\n";
    }
};

class StackFullException : public StackException {
    int element = 0;
    int maxStackSize = 0;
    string message;
public:
    StackFullException(){}
    StackFullException(string p, int e, int s) {
        this -> message = p;
        this -> element = e;
        this -> maxStackSize = s;
    }
    virtual const char* what() const noexcept override {
        string tmp = "Rozmiar stosu przekroczony!\n Dopuszczalny rozmiar: " + to_string(this -> maxStackSize) + ", nadmiarowy element: " + to_string(this -> element) + "\n"; 
        cout << tmp << endl;
        return tmp.c_str();
    }
};

class StackEmptyException : public StackException {
    string message;
public:
    StackEmptyException(){}
    StackEmptyException(string p) {
        this -> message = p;
    }
    virtual const char* what() const noexcept override {
        return "Pusty stos!\n";
    }
};

class Stack{
private:
    int maxStackSize;
    vector<int> dfs;
    int top;
public:
    Stack();
    Stack(int max) {
        this -> maxStackSize = max;
    };
    void push(int newItem) {
        if (dfs.size() == this -> maxStackSize)
            throw StackFullException("", this -> top, newItem);
        dfs.push_back(newItem);
        this -> top = newItem;
    };
    int pop() {
        if (dfs.size() == 0)
            throw StackEmptyException("");
        dfs.pop_back();
        if (dfs.size() == 0){
            throw StackException();
        }
        this -> top = dfs.back();
        return this -> top;
        
    }
    int rt() {
        if (dfs.size() == 0) 
            throw StackException();
        return this -> top;
    }
};


//Z3: noexcept precyzuje, ze what() nie obsluguje wystapienia throw. C++ inaczej traktuje override. @Override sprawia, ze metoda staje sie automatycznie wirtualna, c++ nie dopuszcza takiej mozliwosci.
//Z4: wyjatki musimy sami zdefiniowac, co zrobilem juz wczesniej

void foo(Stack &s) {
    try {
        int i = s.rt();
        
        while (true){
            cout << i << endl;
            s.push(i);
            i++;
        }
    } 
    catch (StackException e) {
        cout << e.what();
    }
}

void bar(Stack &s) {
    try {
        int i = s.rt();
        while (true){
            cout << i << endl;
            s.push(i);
            i++;
        }
    } 
    catch (StackException e) {
        cout << e.what();
    }
}

int main()
{
    Stack s(3);
    s.push(1);
    //foo(s);
    //bar(s);

    string q;
    int q1;
    cout << "Witaj na stosie!\n";
    while(true){
        cin >> q;
        try{
            if (q == "push") {
                cout << "Podaj liczbe: ";
                cin >> q1;
                s.push(q1);
            }
            else if (q == "pop") {
                s.pop();
            }
            else if (q == "rt") {
                cout << s.rt() << endl;
            }
        }
        catch(StackFullException &e){
            cout << e.what();
        }
        catch(StackEmptyException &e){
            cout << e.what();
        }
        catch(StackException &e){
            cout << e.what();
        }
    }
    //Z5: program dziala zgodnie z oczekiwaniami, wrzuca elementy do rozmiaru, przy rozmiar+1 lapie wyjatek'
    //Z6: blad przy ostatnim elemencie nie powoduje cofniecia poprawnie wprowadzonych zmian, wiec przy wywolaniu bar(s) stos juz na wejsciu jest zapelniony
    return 0;
}