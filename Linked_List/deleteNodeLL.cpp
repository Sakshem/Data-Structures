#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first = NULL, *last = NULL;
void insert (int value)
{
    struct node *n; //for creating a new node
    n = new node;
    n->data = value;
    n->next = NULL;
    if (first == NULL) {
        first = last = n;
    }
    else
    {
        last->next = n;
        last = n;
    }
}
void display (struct node *p)
{
    if (first == NULL)
        cout << "Linked list is empty!" << '\n';
    else
    {
        cout << "Element inside the linked list are:" << '\n';
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
}
int deleteFirst ()
{
    int x = -1;
    struct node *t; // we need an extra pointer for deletion
    t = first;
    first = first->next; // we move the first or head pointer to the next node
    x = t->data;
    delete t; // make sure you deallocate the memory of the deleted node
    return x;
}
int deleteNodeAtPos (int pos) //this function can also delete node at first position
{    
    int x = -1;
    struct node *p, *q;
    p = first;
    if (pos == 1)
    {
        first = first->next;
        x = p->data;
        p->next = NULL;
        delete p; 
        return x;
    }
    for (int i = 1; i < pos && p; i++)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "Linked list became empty!" << "\nInvalid position" << '\n';
        return -1;
    }
    q->next = p->next;
    x = p->data;
    p->next = NULL;
    delete p;
    return x;
}
int main()
{
    insert (10);
    insert (20);
    insert (30);
    insert (40);
    insert (50);
    display (first);
    //cout << "Element deleted at first is: " << deleteFirst() << '\n';
    cout << "Element deleted at pos " << 1 << ": " << deleteNodeAtPos (1) << '\n';
    display (first);
    return 0;
}