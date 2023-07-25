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
        cout << "Linked list is empty!" << '\n';
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
void removeDuplicates()
{
    struct node *t, *p;

}
int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    display(first);
    return 0;
}
