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
void levelorder (struct node *p)
{
    struct Queue q;
    create(&q, 100);
    cout << p->data << ' ';
    enqueue (&q, p);
    while (!isEmpty (q)) {
        p = dequeue (&q);
        if (p->lchild) {
            cout << p->lchild->data << ' ';
            enqueue (&q, p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data << ' ';
            enqueue (&q, p->rchild);
        }
    }
}
int main ()
{
    createTree ();
    levelorder (root);
    return 0;
}
