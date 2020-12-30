#include<bits/stdc++.h>
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
        while(p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
}
void reverse()
{
    struct node *p, *q, *r;
    p = first;
    q = NULL;
    r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void RecursiveReverse(struct node *q, struct node *p)
{
    if(p != NULL)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main() 
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50);
    //reverse();
    RecursiveReverse(NULL, first);
    display(first);
    return 0;
}
