#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 1000;

class Stack {
    char *stackarray;
    int top;
  public:

    Stack() {
        stackarray = new char[SIZE];
        top = -1;
    }

    char Pop() {
        if (!IsEmpty()) {
            char last = stackarray[top];
            top--;
            return last;
        } else {
            return '!';
        }
    }

    bool Push(char ele) {
        top++;
        stackarray[top] = ele;
        return true;
    }
    char Top() {
        return stackarray[top-1];
    }
    bool IsEmpty() {
        return top == -1;
    }
    private:
};

int main() {
    char s1[100], s2[100]; 
    cin >> s1 >> s2;
    Stack s;
    int j = 0;
    for (int i = 0; i <= strlen(s1); j++) {
        if (s1[i] == s2[j]) {
            i++;
        } else if (!s.IsEmpty() && s.Top() == s2[j]){
            s.Pop();
        } else {
            if (i == strlen(s1)) {
                break;
            }
            s.Push(s1[i]);
            i++;
            j--;
        }
    }

    if (j >= strlen(s2)-1) {
        cout << "ok" << endl;
    } else {
        cout << "wrong" << endl;
    }
}
// abcdef acedbf
// abcdef dcefab