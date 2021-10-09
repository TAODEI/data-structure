#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
    int Data;
    Node *Next;
    Node(int x) : Data(x), Next(NULL) {}
};

void ErrorMessage(string s) {
    cout << s << endl;
}

class LinkList {
  public:
    int Len;

    // Initialize your data structure here.
    LinkList() {
        head = new Node(0);
        Len = 0;
    }

    // Add a node of value val before the index-th node in the linked list. If
    // index equals to the length of linked list, the node will be appended to
    // the end of linked list. If index is greater than the length, the node
    // will not be inserted.
    void Insert(int index, Node *pnew) {
        if (Len == index) {
            
            Node *p = head;
            for (int j = 0; j < index && p != NULL; j++) {
                p = p->Next;
            }
            p->Next = pnew;
            Len++;
            return;
        }
        if (index < 1 || index > Len) {
            ErrorMessage("索引越界!");
            return;
        }
        Node *p = head;
        for (int j = 1; j < index && p != NULL; j++) {
            p = p->Next;
        }

        pnew->Next = p->Next;
        p->Next = pnew;
        Len++;
    }

    // Delete the index-th node in the linked list, if the index is valid.
    void Delete(int index) {
        if (index <= 0 || index > Len) {
            ErrorMessage("索引越界!");
            return;
        }

        Node *p = head, *q;
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

    void RemoveElements(int val) {
        Node *p = head;
        while (p->Next) {
            if (p->Next->Data == val) {
                p->Next = p->Next->Next;
            } else {
                p = p->Next;
            }
        }
    }

    void Free() {
        Node *q, *p = head;
        while (p->Next != NULL) {
            q = p->Next;
            p->Next = q->Next;
            free(q);
        }
        free(head);
    }

    int Locate(Node *p) {
        Node *q = head;
        int index = 0;
        while (q->Next != NULL) {
            q = q->Next;
            index++;
            if (q->Data == p->Data) {
                return index;
            }
        }
        return 0;
    }

    // Get the value of the index-th node in the linked list. If the index is
    // invalid, return -1.
    int GetElem(int index) {
        if (index <= 0 || index > Len) {
            ErrorMessage("索引越界!");
            return -1;
        }

        Node *p = head;
        for (int j = 0; j < index && p != NULL; j++) {
            p = p->Next;
        }
        return p->Data;
    }

    // get 前驱, return state code
    int GetPriorElem(Node cut_e, Node &pre_e) {
        if (head->Next == NULL) {
            return 1;
        }

        Node *p = head;
        while (p->Next != NULL) {
            if (cut_e.Data == p->Next->Data) {
                pre_e = *p;
                return 0;
            }
            p = p->Next;
        }
        return 1;
    }

    // get 后继, return state code
    int GetNextElem(Node cut_e, Node &next_e) {
        if (head->Next == NULL) {
            return 1;
        }

        Node *p = head;
        while (p->Next != NULL) {
            p = p->Next;
            if (cut_e.Data == p->Data) {
                next_e = *p->Next;
                return 0;
            }
            
        }
        return 1;
    }

    void Display() {
        for (Node *p = head->Next; p != NULL; p = p->Next) {
            printf("%c ", p->Data);
        }
        printf("\n");
    }

  private:
    Node *head;
};

int main() {
    LinkList list;

    // insert 26 alphabets
    for (int i = 0; i < 26; i++) {
        Node *tmp = new Node('a' + i);
        list.Insert(list.Len, tmp);
    }
    list.Display();

    Node *tmp = new Node('a' - 3);
    cout << list.Locate(tmp) << endl;

    cout << list.GetElem(4) << endl;
    printf("%d\n", 'a');

    list.Delete(3);
    list.Display();

    list.Delete(3);
    list.Display();
    list.Free();
}