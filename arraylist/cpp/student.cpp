#include <iostream>
#include <stdio.h>

#include "sequence-list.cpp"

using namespace std;

class Student : public Element {
  public:
    string name, studentID;
    int grade;

    Student(string studentID, string name, int grade)
        : studentID(studentID), name(name), grade(grade) {
        Data = this;
    }
    Student() {}

    void Print() {
        printf("%10s%10s%5d\n", studentID.c_str(), name.c_str(), grade);
    }
};

void sortPass(Student stu[], int num, int len, int radix) {
    Student tmps[len];
    int count[10] = {0};
    int i, j;

    for (i = 0; i < len; i++) {
        j = (stu[i].grade / radix) % 10; // 统计每个桶中的记录数
        count[j]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] = count[i - 1] + count[i]; // 将tmp中的位置依次分配给每个桶
    }
    for (i = len - 1; i >= 0; i--) { // 将所有桶中记录依次收集到tmp中
        j = (stu[i].grade / radix) % 10;
        tmps[count[j] - 1] = stu[i];
        count[j]--;
    }
    for (i = 0; i < len; i++) { // 将临时数组的内容复制到data中
        stu[i] = tmps[i];
    }
}

void List::Sort() {
    int num = 2; // 100 单独排

    int len = GetLength();
    Student students[len];
    Student stu100[len];
    for (int i = 0; i < len; i++) {
        students[i] = *(Student *)GetElem(i + 1).Data;
        if (students[i].grade == 100) {
            stu100[i] = students[i];
        }
    }

    int radix = 1;
    for (int i = 0; i < num; i++) {
        sortPass(students, i, len, radix);
        radix *= 10;
    }

    Clear();
    int t = 0; // 记录 100 的个数
    for (int i = 0; i < len; i++) {
        if (stu100[i].grade == 100) {
            Insert(1, stu100[i]);
            t++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (i[students].grade != 100) {
            Insert(t + 1, students[i]); // 插入到 100 的后面
        }
    }
}

int main() {
    List list;
    int n;
    cout << "请输入学生数: ";
    cin >> n;

    printf("学号       姓名     分数\n");
    while (n--) {
        string studentID, name;
        int grade;

        cin >> studentID >> name >> grade;
        auto stu = new Student(studentID, name, grade);
        list.Insert(-1, stu);
    }

    list.Sort();

    for (int i = 1; i <= list.GetLength(); i++) {
        Element ele = list.GetElem(i);

        Student *stu = (Student *)ele.Data;
        stu->Print();
    }
}

/*
5
1234567887 l 59
2765434567 s 92
3765456765 t 44
1234565444 a 100
5765456786 c 15

*/