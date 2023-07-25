#include <iostream>
using namespace std;
struct node // for creating a binary tree.
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

struct Stack
{
    int size;
    int top;
    struct node **s;
};

void createStack (struct Stack *st, int size)
{
    st->top = -1;
    st->size = size;
    st->s = (struct node **) malloc (sizeof (struct node *) * size);
}
bool stackIsEmpty (Stack st)
{
    if (st.top == -1) return true;
    return false;
}
void push (struct Stack *st, struct node *t)
{
    if (st->top == st->size - 1) {
        cout << "stack overflow!" << '\n';
    }
    else {
        st->top++;
        st->s[st->top] = t;
    }
}
struct node *pop (struct Stack *st)
{
    struct node *t = NULL;
    if (st->top == -1) {
        return t;
    }
    else {
        t = st->s[st->top];
        st->top--;
    }
    return t;
}
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

void iterativePreorder (struct node *t)
{
    struct Stack st;
    createStack (&st, 100);
    while (t != NULL || !stackIsEmpty (st)) {
        if (t != NULL) {
            cout << t->data << ' ';
            push (&st, t);
            t = t->lchild;
        }
        else {
            t = pop (&st);
            t = t->rchild;
        }
    }
}
int main ()
{
    createTree ();
    iterativePreorder (root);
    return 0;
}
