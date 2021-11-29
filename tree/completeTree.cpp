#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

char *s;
int i = 0;
TreeNode *create() {
    if (s[i] == '#' || i >= strlen(s)) {
        return nullptr;
    }
    auto root = new TreeNode(s[i]);
    i++;
    root->left = create();
    i++;
    root->right = create();
    // i++;
    return root;
}

bool isCompleteTreeByLevel(TreeNode *root) {
    queue<TreeNode *> que;
    if (root == nullptr) {
        return false;
    }
    bool flag = true;
    que.push(root);

    while (!que.empty()) {
        int len = que.size();
        for (int i = 0; i < len; i++) {
            auto ele = que.front();
            que.pop();
            if (ele->left != NULL) {
                if (!flag) {
                    return false;
                }
                que.push(ele->left);
            } else {
                flag = false;
            }
            if (ele->right != NULL) {
                if (!flag) {
                    return false;
                }
                que.push(ele->right);
            } else {
                flag = false;
            }
        }
    }
    return true;
}

int main() {
    char str[100] = "abdh###e##cf##g##";
    cin >> str;
    s = str;
    auto tree = create();

    if (isCompleteTreeByLevel(tree)) {
        cout << endl << "true" << endl;
    } else {
        cout << endl << "false" << endl;
    }
}