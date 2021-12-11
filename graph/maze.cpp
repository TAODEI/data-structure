#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct DQNode {
    int x, y;
    DQNode *pre;
    DQNode() {}
    DQNode(int x, int y) : x(x), y(y), pre(nullptr) {}
    DQNode(int x, int y, DQNode *pre) : x(x), y(y), pre(pre) {}
};

bool Pass(int (*maze)[10], DQNode node, int m, int n, bool (*visited)[10]) {
    return 0 <= node.x && node.x < n && 0 <= node.y && node.y < m && maze[node.y][node.x] == 0 && visited[node.y][node.x] == false;
}

DQNode NextPos(DQNode cur, int v) {
    switch (v) {
    case 0:
        return DQNode(cur.x+1, cur.y);
    case 1:
        return DQNode(cur.x+1, cur.y+1);
    case 2:
        return DQNode(cur.x+1, cur.y-1);
    case 3:
        return DQNode(cur.x-1, cur.y);
    case 4:
        return DQNode(cur.x-1, cur.y+1);
    case 5:
        return DQNode(cur.x-1, cur.y-1);
    case 6:
        return DQNode(cur.x, cur.y-1);
    case 7:
        return DQNode(cur.x, cur.y+1);
    default:
        cout << "err!" << endl;
        return DQNode(0, 0);
    }
}

bool ShortPath(int (*maze)[10], int m, int n, stack<int> &S) {
    queue<DQNode> Q;

    bool visited[10][10];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    if (maze[0][0]) {
        return false;
    }

    Q.push(DQNode (0, 0));
    visited[0][0] = true;
    bool found = false;

    while (!found && !Q.empty()) {
        DQNode curPos = Q.front();
        for (int v = 0; v < 8; v++) {
            auto npos = NextPos(curPos, v);

            if (Pass(maze, npos, m, n, visited)) {
                npos.pre = new DQNode(curPos.x, curPos.y, curPos.pre);
                Q.push(npos);

                visited[npos.y][npos.x] = true;
            }

            if (npos.x == n-1 && npos.y == m-1) {
                found = true;
                break;
            }
        }
        Q.pop();
    }

    if (found) {
        auto p = &Q.back();

        while (p) {
            S.push(p->x);
            S.push(p->y);
            p = p -> pre;
        }
        return true;
    } else {
        cout << "not found" << endl;
        return false;
    }
}


int main() {
    stack<int> S;
    int m = 6, n = 8;
    // cin >> m >> n;
    int maze[10][10] = {{0, 1, 0, 1, 0, 0, 0, 1},  {1, 0, 0, 1, 1, 0, 1, 0},  {0, 1, 1, 0, 0, 1, 1, 1},  {1, 0, 0, 1, 1, 0, 0, 1},  {1, 0, 0, 0, 1, 1, 0, 1},  {0, 1, 1, 1, 0, 0, 0, 0}};

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         // cin >> maze[i][j];
    //     }
    // }
    ShortPath(maze, m, n, S);
    auto y = S.top();
    S.pop();
    auto x = S.top();
    S.pop();
    cout << endl << "path: <" << x << "," << y << ">";

    while (!S.empty()) {
        auto y = S.top();
        S.pop();
        auto x = S.top();
        S.pop();
        cout << " -> <" << x << "," << y << ">";
    }
    cout << endl;
}

// 0 1 0 1 0 0 0 1  1 0 0 1 1 0 1 0  0 1 1 0 0 1 1 1  1 0 0 1 1 0 0 1  1 0 0 0 1 1 0 1  0 1 1 1 0 0 0 0
//  0 1 0 1 0 0 0 1
//  1 0 0 1 1 0 1 0
//  0 1 1 0 0 1 1 1
//  1 0 0 1 1 0 0 1
//  1 0 0 0 1 1 0 1
//  0 1 1 1 0 0 0 0
// 00 11 21 32 42 53 64 75