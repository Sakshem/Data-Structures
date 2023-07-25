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
    //n = (struct node *)malloc(sizeof(struct node));
    n = new node;
    n->data = value;
    n->next = NULL;
    if(first == NULL)
        first = last = n;
    else
    {
        last->next = n;
        last = n;
    }
}
void display(struct node *p)
{
    if(first == NULL)
        puts("Linked list is empty");
    else {
        puts("Elements inside linked list are:");
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    puts("");
    }    
}
void insertAtPos(int pos, int value)
{
    struct node *n;
    n->data = value;
    n->next = NULL;
    if(pos == 0)
    {
        n->next = first;
        first = n;
    }
    else
    {
        struct node *t;
        t = first;
        for(int i = 0; i < pos - 1; i++)
            t = t->next;
        n->next = t->next;
        t->next = n;
    }
}
int deleteLast(struct node *p)
{
    int x = -1;
    if(first == NULL)
    {
        puts("Linked list is empty");
    }
    else if(first == last)
    {
        x = last->data;
        first = last = NULL;
    }
    else {
        while(p->next != last)
        {
            p = p->next;
        }
        x = last->data;
        p->next = NULL;
        last = p;
    }
    return x;
}
int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    display(first);
    cout << "Element deleted is: " << deleteLast(first) << '\n';
    cout << "Element deleted is: " << deleteLast(first) << '\n';
    cout << "Element deleted is: " << deleteLast(first) << '\n';
    cout << "Element deleted is: " << deleteLast(first) << '\n';
    cout << "Element deleted is: " << deleteLast(first) << '\n';

    display(first);
    return 0;
}
