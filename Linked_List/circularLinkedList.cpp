//creating a circular linked list
//here we don't use first and last pointer since there is nothing like first and last
//there is no end in a circular linked list so we use
//head pointer that just points on the first node
#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node *next;
} *head = NULL;
int length (struct node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}
void insert (int value)
{
    struct node *n, *last;
    if (head == NULL)
    {
        head = (struct node *) malloc (sizeof(struct node));
        head->data = value;
        head->next = head;
        last = head;
    }
    else
    {
        n = (struct node *) malloc (sizeof(struct node));
        n->data = value;
        n->next = last->next;
        last->next = n;
        last = n;
    }
}
void insertAtPos (int pos, int value) //you can use this function for creating a circular linked list
{
    if (pos < 0 || pos > length(head))
        return;
    struct node *n, *p;
    if (pos == 0)
    {
        n = new node;
        n->data = value;
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head) 
                p = p->next;
            p->next = n;
            n->next = head;
            head = n;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        n = new node;
        n->data = value;
        n->next = p->next;
        p->next = n;
    }
}
void display (struct node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head); //we use do while here 
    //because in while loop if we write p != head then it would never go inside the loop
    //and no elements would be displayed
    //so to prevent that we used a do while loop so that
    //as soon as the element pointed by head node is printed we move to the next node
    cout << '\n';
    
}
void Rdisplay (struct node *p) //Recursive display for circular linked list
{
    static bool flag = false; //using a static variable to make sure only 1 copy is made after n + 1 calls
    //n being the length of the linked list
    if (p != head || flag == false)
    {
        flag = true;
        cout << p->data << " ";
        Rdisplay(p->next); // calling this function again for the next node
    }
    cout << '\n';
    flag = false;
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50); 
    display (head);
    insertAtPos (3, 100); 
    display (head);
    //Rdisplay (head);
    return 0;
}
