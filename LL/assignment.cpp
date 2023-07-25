#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*first = NULL, *last = NULL;

void insert (int value)
{
    struct node *n;
    n = (struct node *) malloc (sizeof (struct node));
    n->data = value;
    n->next = NULL;
    if (first == NULL) {
        first = n;
        last = n;
    }
    else {
        last->next = n;
        last = n;
    }
}

void display (struct node *p)
{
    if (first == NULL) { cout << "Linked list is empty!" << '\n'; }
    else {
        cout << "ELements of linkedlist are: " << '\n';
        while (p != NULL)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }
}

void insertAfter (struct node *p, int key, int value) 
{
    while (p) {
        if (p->data == key) {
            break;
        }
        p = p->next;
    }
    if (p == NULL) { cout << "No element found!" << '\n'; }
    else {
        struct node *n;
        n = (struct node *) malloc (sizeof (struct node));
        n->data = value;
        n->next = NULL;
        n->next = p->next;
        p->next = n;
    }
}
void insertBefore (struct node *p, int key, int value) 
{
    struct node *t;
    if (first == NULL) {
        struct node *n;
        n = (struct node *) malloc (sizeof (struct node));
        n->data = value;
        n->next = NULL;
        first = last = n;
    }
    else if (first->data == key) {
        struct node *n;
        n = (struct node *) malloc (sizeof (struct node));
        n->data = value;
        n->next = first;
        first = n;
        return;
    }
    while (p) 
    {
        if (p->data == key) {
            break;
        }
        t = p;
        p = p->next;
    }
    if (p == NULL) cout << "No such element found!" << '\n';
    else {
        struct node *n;
        n = (struct node *) malloc (sizeof (struct node));
        n->data = value;
        n->next = p;
        t->next = n;
    }
}
void deleteAfter (struct node *p, int key) 
{
    while (p) {
        if (p->data == key) break;
        p = p->next;
    }
    if (p == NULL) cout << "No such element found!" << '\n';
    else {
        struct node *t;
        t = p->next;
        p->next = t->next;
        t->next = NULL;
        free (t);
    }
}
void deleteBefore (struct node *p, int key) 
{
    struct node *t;
    if (first->next->data == key) {
        first = first->next;
        return;
    }
    while (p) {
        if (p->next->data == key) break;
        t = p;
        p = p->next;
    }
    if (p == NULL) cout << "No such element found!" << '\n';
    else {
        t->next = p->next;
        p->next = NULL;
        free (p);
    }
}
int main ()
{
    insert (10);
    insert (20);
    insert (30);
    insert (40);
    //insertAfter (first, 20, 100);
    //insertBefore (first, 10, 100);
    //deleteAfter (first, 30);
    //deleteBefore (first, 20);
    display (first);
    return 0;
}