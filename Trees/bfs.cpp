#include <bits/stdc++.h>
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
void iterativeBfs(Tree *p) {
  if (!p) {
    cout << "root node is null!" << '\n';
    return;
  }
  queue<Tree *> q;
  q.emplace(p);
  cout << p->val << '\n';
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (p->left) {
      cout << p->left->val << '\n';
      q.emplace(p->left);
    }
    if (p->right) {
      cout << p->right->val << '\n';
      q.emplace(p->right);
    }
  }
}
void iterativeBfs2(Tree *p) {
  // same as level order traversal in above code
  // but here, we travel all the nodes that are at the same level in 1 iteration
  // using a for loop
  if (!p) {
    cout << "Root node is null!" << '\n';
    return;
  }
  queue<Tree *> q;
  q.emplace(p);
  cout << p->val << '\n';
  while (!q.empty()) {
    int queue_size = q.size();
    for (int i = 0; i < queue_size; i++) {
      p = q.front();
      q.pop();
      if (p->left) {
        cout << p->left->val << '\n';
        q.emplace(p->left);
      }
      if (p->right) {
        cout << p->right->val << '\n';
        q.emplace(p->right);
      }
    }
  }
}
int main() {
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
  iterativeBfs(root);
  cout << '\n';
  iterativeBfs2(root);
  return 0;
}
