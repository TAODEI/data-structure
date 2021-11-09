#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 1000;

class Stack {
    public:
    char *stackarray;
    int tos;

    Stack() {
        stackarray = new char[SIZE];
        tos = -1;
    }

    Stack(const Stack &s) {
        stackarray = new char[SIZE];

        for (int i = 0; i < strlen(s.stackarray); i++) {
            stackarray[i] = s.stackarray[i];
        }
        tos = s.tos;
    }


    char Pop() {
        if (!IsEmpty()) {
            char last = stackarray[tos];
            tos--;
            return last;
        } else {
            return '!';
        }

    }

    bool Push(char ele) {
        if (!isFull()) {
            tos++;
            stackarray[tos] = ele;
            return true;
        } else {
            return false;
        }
    }

    bool IsEmpty() {
        return tos == -1;
    }
    private:

    bool isFull() {
        return tos == SIZE-1;
    }
};
