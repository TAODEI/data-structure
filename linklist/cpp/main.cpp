#include "single-linklist.cpp"
#include <iostream>
using namespace std;

void Union(LinkList &la, LinkList &lb) {
    int len = la.Len;
    while (!lb.isEmpty()) {
        Node e(0);
        lb.Delete(1, e);
        if (!la.Locate(e)) {
            len++;
            la.Insert(len, e);
        }
    }
}

LinkList Union2(LinkList &la, LinkList &lb) {
    int len = la.Len;
    LinkList lc = la;

    while (!lb.isEmpty()) {
        Node e;
        lb.Delete(1, e);
        if (!la.Locate(e)) {
            len++;
            lc.Insert(len, e);
        }
    }
    return lc;
}

// 交集
LinkList Intersection(LinkList la, LinkList lb) {
    LinkList lc = la;
    lc.Copy(la);

    for (int i = 1; i <= lc.Len; i++) {
        Node _ = lc.GetElem(i);
        if (!lb.Locate(_)) {
            lc.Delete(i, _);
            i--;
        }
    }
    return lc;
}

// 差集
LinkList Subtraction(LinkList la, LinkList lb) {
    LinkList lc = la;
    lc.Copy(la);

    for (int i = 1; i <= lc.Len; i++) {
        Node _ = lc.GetElem(i);
        if (lb.Locate(_)) {
            lc.Delete(i, _);
            i--;
        }
    }
    return lc;
}

int main() {
    LinkList l1 = LinkList(max_size);
    LinkList l2 = LinkList(max_size);
    Node elems[10];

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

    LinkList l3 = Intersection(l1, l2);
    cout << "l1*l2: ";
    l3.Display();

    LinkList l4 = Subtraction(l1, l2);
    cout << "l1-l2: ";
    l4.Display();

    LinkList l5 = Subtraction(l2, l1);
    cout << "l2-l1: ";
    l5.Display();
}