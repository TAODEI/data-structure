#include "circular-queue.cpp"

int main() {
    int n;
    cin >> n;
    CircularQueue queue = CircularQueue(n + 10);
    queue.EnQueue(0);
    queue.EnQueue(1);
    queue.EnQueue(1);

    // line 1
    for (int j = 1; j < n; j++) {
        cout << " ";
    }
    cout << 1 << endl;
    if (n == 1) {
        return 0;
    }
    // line 2 to n-1 
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            cout << " ";
        }
        queue.EnQueue(0);
        int head = 1;
        for (int j = 0; j < i + 2 && head; j++) {

            head = queue.Front();
            queue.DeQueue();
            int newHead = queue.Front();
            if (newHead) {
                cout << newHead << " ";
            } else {
                cout << endl;
            }
            queue.EnQueue(head + newHead);
        }
        queue.EnQueue(0);
    }

    // line n
    while (!queue.isEmpty()) {
        int ele = queue.Front();

        queue.DeQueue();
        if (ele) {
            cout << ele << " ";
        }
    }
    cout << endl;
}