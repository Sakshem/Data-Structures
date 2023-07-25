#include <iostream>
using namespace std;
struct node // for creating a binary tree.
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

struct Queue //queue using array. (circular queue)
{
    int size;
    int front;
    int rear;
    struct node **Q; //pointer of type node
};

void create (struct Queue *q, int size) 
{
    q->size = size;
    q->rear = q->front = 0;
    q->Q = (struct node **) malloc (sizeof (struct node *) * size);
}
void enqueue (struct Queue *q, struct node *address) //address of a node of the BT
{
    if ((q->rear + 1) % q->size == q->front) {
        cout << "Queue is full!" << '\n';
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = address;
    }
}
struct node* dequeue (struct Queue *q)
{
    struct node* x = NULL;
    if (q->rear == q->front) {
        cout << "Queue is empty!" << '\n';
    }
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
bool isEmpty (struct Queue q)
{
    if (q.front == q.rear) return true;
    return false;
}
void createTree ()
{
    struct node *p, *t;
    int x;
    struct Queue q;
    create (&q, 100); //size of queue is 100.
    cout << "Enter root value" << '\n';
    cin >> x;
    root = (struct node *) malloc (sizeof (struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue (&q, root);
    while (!isEmpty (q)) {
        p = dequeue (&q);
        cout << "Enter left child of " << p->data << '\n';
        cin >> x;
        if (x != -1) {
            t = (struct node *) malloc (sizeof (struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue (&q, t);
        }
        cout << "Enter right child of " << p->data << '\n';
        cin >> x;
        if (x != -1)
        {
            t = (struct node *) malloc (sizeof (struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue (&q, t);
        }
    }
}
void preorder (struct node *p)
{
    if (p) {
        cout << p->data << ' ';
        preorder (p->lchild);
        preorder (p->rchild);
    }
}
void inorder (struct node *p)
{
    if (p) {
        inorder (p->lchild);
        cout << p->data << ' ';
        inorder (p->rchild);
    }
}
void postorder (struct node *p)
{
    if (p) {
        postorder (p->lchild);
        postorder (p->rchild);
        cout << p->data << ' ';
    }
}
int count (struct node *p)
{
    int x, y;
    if (p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
int height (struct node *p) //Height including the root
{
    int x, y;
    if (p) { 
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y) {
            return x + 1;
        }
        else {
            return y + 1;
        }
    }
    return 0;
}
int sum (struct node *p)
{
    int x, y;
    if (p) {
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
int count_nodes_with_degree_2 (struct node *p)
{
    int x, y;
    if (p) {
        count_nodes_with_degree_2(p->lchild);
        count_nodes_with_degree_2(p->rchild);
        if (p->lchild && p->rchild) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}
int leaf_count (struct node *p)
{
    int x, y;
    if (p) {
        leaf_count(p->lchild);
        leaf_count(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}
int count_nodes_with_degree_1(struct node *p)
{
    int x, y;
    if (p) {
        count_nodes_with_degree_1(p->lchild);
        count_nodes_with_degree_1(p->rchild);
        if ((!p->lchild && p->rchild) || (p->lchild && !p->rchild)) {
            //there is a alternative way to check the above condition.
            //that is by doing xor between left child and right child
            //if (p->lchild != NULL ^ p->rchild != NULL)
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}
int main ()
{
    //NOTE: Enter -1 when asked enter value of the left child or right child
    //if you don't want any further child of that node.
    createTree ();
    //all the three traversals in binary trees
    cout << "Preorder traversal for the binary tree: " << '\n';
    preorder (root);
    cout << '\n';

    cout << "Postorder traversal for the binary tree: " << '\n';
    postorder (root);
    cout << '\n';

    cout << "Inorder traversal for the binary tree: " << '\n';
    inorder (root);
    cout << '\n';

    cout << "Height of the binary tree is: " << '\n';
    cout << height(root) << '\n';

    cout << "Total nodes in the binary tree are: " << '\n';
    cout << count(root) << '\n';

    cout << "Sum of all elements in the binary tree is: " << '\n';
    cout << sum(root) << '\n';
    return 0;
}
