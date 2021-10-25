#include "single-linklist.cpp"
#include <iostream>
using namespace std;

// 并集
LinkList Union(LinkList &la, LinkList &lb) {
    auto lc = LinkList(la);

    
    return lc;
}

// 交集
LinkList *Intersection(LinkList la, LinkList lb) {
    auto lc = new LinkList;
    lc->Copy(la);
 
    for (int i = 1; i <= lc->Len; i++) {
        for (int j = 1; ; j++) {
            if (lc->GetElem(i) == lb.GetElem(j)) {
                break;
            }
            if (j == lb.Len) {
                lc->Delete(i);
                i--;
                break;
            }
        }
    }
    return lc;
}

// 差集
LinkList Subtraction(LinkList la, LinkList lb) {
    auto lc = LinkList(la);

    // for (int i = 1; i <= lc->Len; i++) {
    //     Node _ = lc->GetElem(i);
    //     if (lb.Locate(_)) {
    //         lc->Delete(i, _);
    //         i--;
    //     }
    // }
    return lc;
}

int main() {
    LinkList l1 = LinkList();
    LinkList l2 = LinkList();

    for (int i = 1; i <= 4; i++) {
        auto newNode = new Node(i);
        l1.Insert(l1.Len, newNode);

    }
    for (int i = 2; i <= 7; i++) {
        if (i == 4) {
            continue;
        }
        auto newNode = new Node(i);
        l2.Insert(l2.Len, newNode);
    }
    cout << "l1: ";
    l1.Display();
    cout << "l2: ";
    l2.Display();


    auto l3 = Intersection(l1, l2);
    cout << "l1*l2: ";
    l3->Display();

    // LinkList l4 = Subtraction(l1, l2);
    // cout << "l1-l2: ";
    // l4.Display();

    // LinkList l5 = Subtraction(l2, l1);
    // cout << "l2-l1: ";
    // l5.Display();
}