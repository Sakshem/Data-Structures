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
void insert (int value)
{
    struct node *last, *n;
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
    //Rdisplay (head);
    return 0;
}
