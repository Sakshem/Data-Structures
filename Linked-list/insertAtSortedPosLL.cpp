#include<iostream> 
#include<climits>
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
        cout << "Elements inside linked list are: " << '\n';
        while(p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
}
void insertAtSort(int key) //using three pointers (1 for making a new node)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = key;
    n->next = NULL;
    struct node *p, *t = NULL;
 
    if(first == NULL)
        first = n;

    else {
        p = first;
        while(p != NULL)
        {
            if(p->data >= key)
                break;
            t = p;
            p = p->next;
        }
        if(p == first)
        {
            n->next = first;
            first = n;
        }
        else {
            n->next = p; 
            t->next = n;
        }
    }

}
bool isSorted()
{
    struct node *p = first;
    int x = INT_MIN;
    while(p != NULL)
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}
void insertAtSorted(int x) //using only two pointers
{
    //using a single traversal pointer
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    struct node *p = first;
    if(first == NULL)
    {
        first = n;
    }
    else if(p->data > x)
    {
        n->next = p;
        first = n;
    }
    else {
        while(p->next != NULL)
        {
            if(p->next->data >= x)
                break;
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
}
int main()
{
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    display(first);
    //since elements are sorted and if we want to insert a element in a sorted linked list
    insertAtSort(25); 
    display(first);
    if(isSorted())
        cout << "linked list is sorted" << '\n';
    else
        cout << "Linked list is not sorted" << '\n';
    return 0;
}
