#include <vector>
#include <iostream>
using namespace std;
#include <stack>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    ret.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);

    ret.insert(ret.end(), left.begin(), left.end()); // 向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据

    vector<int> right = preorderTraversal(root->right);
    
    ret.insert(ret.end(), right.begin(), right.end());
    return ret;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    stack<TreeNode*> mystack;
    TreeNode * p = root;
    mystack.push(p);

    while(!mystack.empty()){
        p = mystack.top(); 
        mystack.pop();
        ret.push_back(p->val);


        if(p->right) mystack.push(p->right) ;
        if(p->left) mystack.push(p->left);            
    }     
    return ret;       
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    vector<int> left = inorderTraversal(root->left);

    ret.insert(ret.end(), left.begin(), left.end());

    ret.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    
    ret.insert(ret.end(), right.begin(), right.end());
    return ret;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    stack<TreeNode*> mystack;
    TreeNode * p = root;
    mystack.push(p);

    while(!mystack.empty()){
        p = mystack.top(); 
        mystack.pop();

        if(p->right) mystack.push(p->right);

        ret.push_back(p->val);
        if(p->left) mystack.push(p->left);            
    }     
    return ret;       
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root == NULL) {
        return ret;
    }

    stack<TreeNode*> mystack;
    TreeNode * p = root;
    mystack.push(p);

    while(!mystack.empty()){
        p = mystack.top();
        mystack.pop();

        if(p->right) mystack.push(p->right);

        if(p->left) mystack.push(p->left);
        ret.push_back(p->val);
    }
    // ret.reserve();
    return ret;  
}