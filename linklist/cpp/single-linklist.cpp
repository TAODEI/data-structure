#include <stdio.h>
#include <stdlib.h>

class Node {
  public:
    int Score;
    Node *Next;
};

// struct Node {
//     int Score;
//     Node *Next;
// };

class LinkList {
  public:
    Node *Head;
    int Len;

    void CreateLinkList();
    void Insert(Node *pnew, int index);
    void Delete(int index);
    void Display();
    void Free();
};

int main() {
    LinkList list;
    Node *Head, *pnew;
    list.CreateLinkList();

    printf("after create: ");
    list.Display();

    pnew = new Node;
    pnew->Score = 88;

    list.Insert(pnew, 3);
    printf("after insert: ");
    list.Display();
    list.Delete(3);
    printf("after delete: ");
    list.Display();
    list.Free();
}

void LinkList::CreateLinkList() {
    Head = new Node;
    Head->Score = 0;
    Head->Next = NULL;
    Node *pnew, *tail;
    int Score;

    Head->Next = NULL;
    tail = Head;
    printf("input the Score of students:\n");
    while (1) {
        scanf("%d", &Score);
        if (Score < 0) {
            break;
        }
        pnew = new Node;
        pnew->Score = Score;
        pnew->Next = NULL;
        tail->Next = pnew;
        tail = pnew;
    }
}

void LinkList::Insert(Node *pnew, int index) {
    Node *p = Head;
    int j;
    for (j = 0; j < index && p != NULL; j++) {
        p = p->Next;
    }
    if (p == NULL) {
        printf("the %d node not found!\n", index);
        return;
    }
    pnew->Next = p->Next;
    p->Next = pnew;
}

void LinkList::Delete(int index) {
    Node *p = Head, *q;
    if (index == 0) {
        return;
    }
    for (int j = 1; j < index && p->Next != NULL; j++)
        p = p->Next;
    if (p->Next == NULL) {
        printf("the %d node not found!\n", index);
        return;
    }
    q = p->Next;
    p->Next = q->Next;
    free(q);
}

void LinkList::Display() {
    Node *p;
    for (p = Head->Next; p != NULL; p = p->Next) {
        printf("%d ", p->Score);
    }
    printf("\n");
}

void LinkList::Free() {
    Node *q, *p = Head;
    while (p->Next != NULL) {
        q = p->Next;
        p->Next = q->Next;
        free(q);
    }
    free(Head);
}