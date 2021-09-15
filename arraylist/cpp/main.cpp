#include <iostream>
// #include "s.h"
#include "sequence-list.cpp"

int main() {
    List *L = new List(max_size);
    Element elems[10];
    for (int i = 0; i < 10; i++) {
        elems[i].Data = i*10;
        L->Insert(-1, elems[i]);
    }

    L->Display();

    Element elem1, elem2;
    elem1.Data = 25;
    cout << L->Locate(elem1) << endl;
    elem1.Data = 20;
    cout << L->Locate(elem1) << endl;

    L->Delete(5, elem2);
    cout << elem2.Data << endl;
    L->Display();
    L->Delete(5, elem2);
    L->Display();

    L->Clear();
    L->Display();

    delete L;
    L->Free();
}