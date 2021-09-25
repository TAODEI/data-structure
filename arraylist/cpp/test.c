#include <stdio.h>

long int fact(n) int n;
{
    long f;
    if (n > 1)
        f = n * fact(n - 1);
    else
        f = 1;
    return (f);
}

typedef struct {
    int *elem;    //存储空间基址
    int length;   //当前长度
    int listsize; //当前分配的存储容量
} SqList;
main() {
    SqList a;
    a.elem[0] = 1;
    a.elem[1] = 3;
    a.elem[2] = 4;
    a.elem[3] = 5;
    a.elem[4] = 6;
    a.elem[5] = 7;
    a.length = 6;
    int k = 2, i = 2;
    for (int count = 0; count < k; count++) {
        //删除一个元素
        for (int j = a.length-1; j >= i; j--) {
            printf("%d %d\n",j, a.elem[j - 1]);
            a.elem[j - 1] = a.elem[j];
        }
        a.length--;
    }
    printf("\n");
    for (int i = 0; i < a.length; i++) {
        printf("%d ", a.elem[i]);
    }
}
