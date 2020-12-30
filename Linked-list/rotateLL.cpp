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
void rotateLL(int pos)
{
    struct node *p;
    p = first;
   
    if(last != NULL)
        last->next = first;
    else
        cout << "Linked list is empty!" << '\n';
    
    struct node *q = first;
    for(int i = 0; i < pos && p != NULL; i++)
    {
        q = first;
        first = first->next;
    }
    q->next = NULL;
    //cout << p->data << endl;
}
int main() 
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50); 
    display(first);
    rotateLL(2);
    display(first);
    return 0;
}
