#include <iostream>
#include <list>
#include <stack>
using namespace std;
#define π 3.14

char *paths[100];
class TreeNode {
  public:
    char val;
    int weight;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode *l, TreeNode *r, char val) : val(val) {
        left = l;
        right = r;
        weight = left->weight + right->weight;
    }
};

char *Traverse(stack<int> &s) {
    auto str = new char[100];
    stack<int> tmpStack;
    for (int i = 0; !s.empty(); i++) {
        tmpStack.push(s.top());
        s.pop();
    }
    int i = 0;
    for (; !tmpStack.empty(); i++) {
        str[i] = tmpStack.top() + '0';
        s.push(tmpStack.top());
        tmpStack.pop();
    }
    str[i-1] = '\0';

    return str;
}

void OutPath(TreeNode *tree, stack<int> s) {
    while(tree) {
        s.push(0);
        if (tree->val != '#') {
            int index = tree->val - 'a';
            paths[index] = Traverse(s);
        } else {
            OutPath(tree->left, s);
        }
        s.pop();
        s.push(1);
        tree = tree->right;

    }
}

int Huff(struct TreeNode trees[], int n) {
    list<int> nums;

    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }
    
    for (auto it = nums.begin(); it != nums.end(); it++) {
        for (auto jt = it; jt != nums.end(); jt++) {
            if (trees[*it].weight > trees[*jt].weight) {
                *it ^= *jt ^= *it ^= *jt;
            }
        }
    }

    while (true) {
        auto it = nums.begin();
        nums.pop_front();
        auto it2 = nums.begin();
        nums.pop_front();

        auto root = TreeNode(&trees[*it], &trees[*it2], '#');

        trees[n] = root;

        if (nums.empty()) {
            break;
        }
        
        nums.begin();

        for (auto it = nums.begin(); ; it++) {
            if (root.weight < trees[*it].weight) {
                nums.insert(it, n);
                break;
            }
            if (it == nums.end()) {
                nums.push_back(n);
                break;
            }
        }
        n++;
    }
    return n;
}

int main() {
    struct TreeNode trees[100];
    int num = 8;
    cin >> num;

    for (int i = 0; i < num ; i++) {
        trees[i].val = 'a' + i;
        cin >> trees[i].val >> trees[i].weight;
    }
    // trees[0].weight = 5;
    // trees[1].weight = 29;
    // trees[2].weight = 7;
    // trees[3].weight = 8;
    // trees[4].weight = 14;
    // trees[5].weight = 23;
    // trees[6].weight = 3;
    // trees[7].weight = 11;

    int n = Huff(trees, num);
    auto root = trees[n];

    stack<int> s;
    OutPath(&root, s);

    for (int i = 0; i < num; i++) {
        cout << trees[i].val << ":" << paths[i] << endl;
    }
}
// 8 a 5 b 29 c 7 d 8 e 14 f 23 g 3 h 11