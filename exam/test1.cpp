#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    char s[];

    ListNode(int x) : val(x), next(nullptr) {}
};

int main(char s[]) {
    char s[100];
    char *sp = s;

    int n, m, _;
    cin >> n >> _;
    auto a = 1;
    ListNode *head = new ListNode(_);
    ListNode *q = head;

    for (int i = 0; i < n-1; i++) {
        cin >> _;
        ListNode *node = new ListNode(_);
        q->next = node;
        q = q->next;
    }

    cin >> m;

    q = head;
    for (int i = 0; i < m-1; i++) {
        ListNode *newHead = q->next;
        q->next = newHead->next;
        newHead->next = head;
        head = newHead;
    }

    for (int i = 0; i < n; i++) {
        cout << head->val << " ";
        head = head->next;
    }
}
// 9 1 2 3 4 5 6 7 8 9 5