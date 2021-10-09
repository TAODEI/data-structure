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

// 交集
List Intersection(List la, List lb) {
    List lc = la;
    lc.Copy(la);

    for (int i = 1; i <= lc.GetLength(); i++) {
        Element _ = lc.GetElem(i);
        if (!lb.Locate(_)) {
            lc.Delete(i, _);
            i--;
        }
    }
    return lc;
}

// 差集
List Subtraction(List la, List lb) {
    List lc = la;
    lc.Copy(la);

    for (int i = 1; i <= lc.GetLength(); i++) {
        Element _ = lc.GetElem(i);
        if (lb.Locate(_)) {
            lc.Delete(i, _);
            i--;
        }
    }
    return lc;
}

int main() {
    List l1 = List(max_size);
    List l2 = List(max_size);
    Element elems[10];

    for (int i = 1; i <= 4; i++) {
        elems[i].Data = i;
        l1.Insert(-1, elems[i]);
    }
    for (int i = 2; i <= 7; i++) {
        if (i == 4) {
            continue;
        }
        elems[i].Data = i;
        l2.Insert(-1, elems[i]);
    }
    cout << "l1: ";
    l1.Display();
    cout << "l2: ";
    l2.Display();

    List l3 = Intersection(l1, l2);
    cout << "l1*l2: ";
    l3.Display();

    List l4 = Subtraction(l1, l2);
    cout << "l1-l2: ";
    l4.Display();

    List l5 = Subtraction(l2, l1);
    cout << "l2-l1: ";
    l5.Display();
}