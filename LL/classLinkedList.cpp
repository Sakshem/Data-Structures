#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList () { first = NULL; }
        LinkedList (int A[], int n);
        ~LinkedList ();
        void Display ();
        void Insert (int index, int x);
        int Delete (int index);
        int Length ();
};
LinkedList :: LinkedList (int A[], int n)
{
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList :: ~LinkedList ()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList :: Display ()
{
    Node *p = first;
    if(first == NULL)
        cout << "linked list is empty!" << '\n';
    else {
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
}
int  LinkedList :: Length ()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void LinkedList :: Insert (int index, int x)
{
    Node *n, *p = first;
    if(index < 0 || index > Length ())
        return;
    n = new Node;
    n->data = x;
    n->next = NULL;

    if(index == 0)
    {
        n->next = first;
        first = n;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        n->next = p->next;
        p->next = n;
    }
}
int LinkedList :: Delete (int index)
{
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return x;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } 
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
             q = p;
             p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
   return x; 
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList l (A, 5);

    cout << l.Delete(3) << '\n';
    l.Insert (0, 5);
    l.Display ();
    return 0;
}
