#include <iostream>

using namespace std;

const int max_size = 100;

class Element {
  public:
    // bool operator==(const Element &value) const;
    int Data;

    bool Equal(Element e) {
        if (Data == e.Data) {
            return true;
        } else {
            return false;
        }
    }
};
// bool operator==(const Element &v1, const Element &v2);

void ErrorMessage(string s);

class List {
  public:
    List(int maxsize) {
        len = 0;
        size = maxsize;
        elem = new Element[size];
    }
    ~List() {
        // delete[] elem;
        // Free();
    }
    int Locate(Element e);
    void Insert(int index, Element e);
    void Delete(int index, Element &e);
    void Free();  // 释放
    void Clear(); // 置空 ?
    bool isEmpty();
    int GetLength();
    Element GetElem(int index);
    int GetPriorElem(Element cut_e, Element &pre_e); // 获取前驱 返回状态码
    int GetNextElem(Element cut_e, Element &next_e); // 获取后继 返回状态码
    void Display();

  private:
    Element *elem; // 数组
    int len;
    int size;
    void checkFull();
};

void List::checkFull() {
    if (len == size) {
        size *= 2;
        Element *newElem = new Element[size];
        for (int i = 0; i < len; i++) {
            newElem[i] = elem[i];
        }
        delete[] elem;
        elem = newElem;
    }
}

int List::Locate(Element e) {
    if (isEmpty()) {
        return 0;
    }

    Element *p = elem;
    for (int i = 1; i <= len; i++, p++) {
        if (e.Equal(*p)) {
            return i;
        }
    }
    return 0;
}

void List::Insert(int index, Element e) {
    checkFull();

    if (index == -1) { // 末尾插入
        elem[len] = e;
        len++;
        return;
    }
    if (index < 1 || index > len + 1) {
        ErrorMessage("索引越界!");
        return;
    }

    len++;
    for (int i = len - 1; i >= index; i--) {
        elem[i] = elem[i - 1];
    }
    elem[index - 1] = e;
}

void List::Delete(int index, Element &e) {
    if (index < 1 || index > len + 1) {
        ErrorMessage("索引越界!");
        return;
    }

    e = elem[index - 1];
    for (int i = index - 1; i < len - 1; i++) {
        elem[i] = elem[i + 1];
    }
    len--;
}

// 释放
void List::Free() {
    delete[] elem;
    delete this;
}

// 置空
void List::Clear() {
    delete[] elem;
    elem = new Element[size];
    len = 0;
}

bool List::isEmpty() {
    if (len == 0) { // 空
        return true;
    } else {
        return false;
    }
}

int List::GetLength() {
    return len;
}

Element List::GetElem(int index) {
    if (index < 1 || index > len + 1) {
        ErrorMessage("索引越界!");
        Element tmp;
        return tmp;
    }
    return elem[index - 1];
}

// 获取前驱 返回状态码
int List::GetPriorElem(Element cut_e, Element &pre_e) {
    if (isEmpty()) {
        return 1;
    }
    if (elem[0].Equal(cut_e)) {
        return 2; // 无前驱
    }
    for (int i = 1; i < len; i++) {
        if (cut_e.Equal(elem[i])) {
            pre_e = elem[i - 1];
            return 0; // 成功
        }
    }
    return 1; // 未找到
}

// 获取后继 返回状态码
int List::GetNextElem(Element cut_e, Element &next_e) {
    if (isEmpty()) {
        return 1;
    }
    if (elem[len - 1].Equal(cut_e)) {
        return 2; // 无后继
    }
    for (int i = 0; i < len - 1; i++) {
        if (cut_e.Equal(elem[i])) {
            next_e = elem[i + 1];
            return 0; // 成功
        }
    }
    return 1; // 未找到
}

void List::Display() {
    // for(Element &e : elem) {}
    for (int i = 0; i < len; i++) {
        cout << elem[i].Data << " ";
    }
    cout << endl;
}

void ErrorMessage(string s) {
    cout << s << endl;
}
