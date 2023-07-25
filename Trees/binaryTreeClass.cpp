#include <iostream>
using namespace std;
class node
{
    public:
    node *lchild;
    int data;
    node *rchild;
};

class Queue 
{
    private:
    int front;
    int rear;
    int size;
    node **Q;

    public:
    Queue () { front = rear = -1; size = 10; Q = new node *[size]; }
    Queue (int size) { front = rear = -1; this->size = size; Q = new node *[size]; }
    void enqueue (node *address);
    node* dequeue ();
    bool isEmpty ();
};
void Queue :: enqueue (node *address)
{
    if (rear == size - 1) cout << "Queue is full!" << '\n';
    else {
        rear++;
        Q[rear] = address;
    }
}
node* Queue :: dequeue ()
{
    node* x = NULL;
    if (front == rear) cout << "Queue is empty!" << '\n';
    else {
        front++;
        x = Q[front];
    }
    return x;
}
inline bool Queue :: isEmpty ()
{
    if (rear == front) return true;
    return false;
}
class Tree
{
    public:
    node *root;
    Tree () { root = NULL; }
    void createTree ();
    void preorder (node *p);
    void postorder (node *p);
    void inorder (node *p);
    void levelorder (node *p);
    int height (node *root);
};
void Tree :: createTree ()
{
    node *p, *t;
    int x;
    Queue q (100); //size of queue is 100
    cout << "Enter the root value:" << '\n';
    cin >> x;
    root = new node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue (root);
    while (!q.isEmpty())
    {
        p = q.dequeue ();
        cout << "Enter left child of " << p->data << '\n';
        cin >> x;
        if (x != -1) {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue (t);
        }
        cout << "Enter right child of " << p->data << '\n';
        cin >> x;
        if (x != -1) {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue (t);
        }
    }
}
void Tree :: preorder (node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        preorder (p->lchild);
        preorder (p->rchild);
    }
}
void Tree :: inorder (node *p)
{
    if (p)
    {
        inorder (p->lchild);
        cout << p->data << ' ';
        inorder (p->rchild);
    }
}
void Tree :: postorder (node *p)
{
    if (p)
    {
        postorder (p->lchild);
        postorder (p->rchild);
        cout << p->data << ' ';
    }
}
void Tree :: levelorder (node *root)
{
    Queue q (100); //Queue of 100 size.
    cout << root->data << ' ';
    q.enqueue (root);
    while (!q.isEmpty ()) {
        root = q.dequeue ();
        if (root->lchild) 
        {
            cout << root->lchild->data << ' ';
            q.enqueue (root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << ' ';
            q.enqueue (root->rchild);
        }
    }
}
int Tree :: height (node *root)
{
    int x = 0, y = 0;
    if (root == NULL) return 0;
    x = height (root->lchild);
    y = height (root->rchild);
    if (x > y)
        return x + 1;
    else 
        return y + 1;
}
int main ()
{
    //NOTE : write -1 if you don't want any further child of a node
    Tree t;
    t.createTree ();
   
    cout << "Preorder traversal of tree: " << '\n';
    t.preorder (t.root);
    cout << '\n';
    
    cout << "Inorder traversal of tree: " << '\n';
    t.inorder (t.root);
    cout << '\n';

    cout << "Postorder traversal of tree: " << '\n';
    t.postorder (t.root);
    cout << '\n';

    return 0;
}
