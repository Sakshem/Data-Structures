#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first = NULL, *last = NULL; 
void insertLast(int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    if(first == NULL)
    {
        first = last = n;
    }
    else
    {
        last->next = n;
        last = n;
    }
}
void display(struct node *p)
{
    if(first == NULL)
        cout << "linked list is empty!" << '\n';
    else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
}
bool isLoop(struct node *f)
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q?q->next : NULL;
    }while(p && q && p != q);
    if(p == q)
        return true;
    else
        return false;
}
int main() 
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50); 
    struct node *t1, *t2;
    t1 = first->next->next;
    t2 = last;
    t2->next = t1; 
    cout << isLoop(first) << endl; // it will return 0 or 1
    //if there is a loop in a linked list it will return 1
    //if there is no loop in a linked list it will return 0
    return 0;
}