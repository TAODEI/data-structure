#include <malloc.h>
#include <stdio.h>

typedef struct SqList {
    // 数据
    int *elem;
    int length;
} SqList;

// 创建空表
void InitSqList(SqList *L) {
    L->elem = (int *)malloc(sizeof(int) * 10);
    L->length = 0;
}

// 在第i个元素之间插入新的元素e,L的长度增加1
void ListInsert(SqList *L, int i, int e) {

    for (int j = L->length; j > i; j--) {
        // 把第i个之后的元素都往后面移动,第i个元素不动
        L->elem[j] = L->elem[j - 1];
    }

    L->elem[i] = e;
    L->length++;
}

void Union(SqList *La, SqList *Lb) {
    int *e;

    int j = La->length - 1;
    *e = Lb->elem[0];
    ListInsert(La, j, *e);
}

int main() {
    SqList La;
    SqList Lb;
    InitSqList(&La);
    InitSqList(&Lb);

    ListInsert(&La, 0, 1);
    ListInsert(&Lb, 0, 1);

    // printf("-\n"); // 此行代码注释掉就会报段错误

    Union(&La, &Lb);
    printf("ok!\n");
}