#include "sequence-list.cpp"
#include <iostream>
using namespace std;

void Union(List &la, List &lb) {
    int len = la.GetLength();
    while (!lb.isEmpty()) {
        Element e;
        lb.Delete(1, e);
        if (!la.Locate(e)) {
            len++;
            la.Insert(len, e);
        }
    }
}

List Union2(List &la, List &lb) {
    int len = la.GetLength();
    List lc = la;

    while (!lb.isEmpty()) {
        Element e;
        lb.Delete(1, e);
        if (!la.Locate(e)) {
            len++;
            lc.Insert(len, e);
        }
    }
    return lc;
}

int main() {
    List la = List(max_size);
    List lb = List(max_size);
    Element elems[10];

    for (int i = 0; i < 10; i++) {
        elems[i].Data = i * 10;
        la.Insert(-1, elems[i]);
    }
    for (int i = 0; i < 10; i++) {
        elems[i].Data += i;
        lb.Insert(-1, elems[i]);
    }
    cout << "la: ";
    la.Display();
    cout << "lb: ";
    lb.Display();
    
    Union(la, lb);
    cout << "la: ";
    la.Display();

    List lc = Union2(la, lb);
    cout << "lc: ";
    lc.Display();

    // Element elem1, elem2;
    // elem1.Data = 25;
    // cout << la.Locate(elem1) << endl;
    // elem1.Data = 20;
    // cout << la.Locate(elem1) << endl;

    // la.Delete(5, elem2);
    // cout << elem2.Data << endl;
    // la.Display();
    // la.Delete(5, elem2);
    // la.Display();

    // la.Clear();
    // la.Display();

    // la.Free();
}