#include<bits/stdc++.h>
using namespace std;
class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
        Tree(int val) {
            this->val = val;
            left = NULL, right = NULL;
        }
};
void iterativeDfs(Tree *p) { // same as iterative preorder
    if(!p) {
    cout << "root node is null!" << '\n';
    }
    stack<Tree*> st;
    if (p) st.emplace(p);
    while (!st.empty()) {
       p = st.top();
       st.pop();
       cout << p->val << '\n';
       if (p->right) st.emplace(p->right);
       if (p->left) st.emplace(p->left);
    }
}
void dfs(Tree *p) { // same as recursive preorder.
    if (!p) {
        return;
    }
    cout << p->val << '\n';
    dfs(p->left);
    dfs(p->right);
}
int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = new Tree(4);
    root->right->left->right = NULL;
    root->right->right = new Tree(5);
    root->right->right->left = NULL;
    root->right->left->left = new Tree(6);
    root->right->left->left->left = NULL;
    root->right->left->left->right = NULL;
    root->right->right->right = new Tree(7);
    dfs(root);
    
    // to check if it works when root is null.
    Tree *basicRoot = NULL;
    dfs(basicRoot);
    return 0;
}
