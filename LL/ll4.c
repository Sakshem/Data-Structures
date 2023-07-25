#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first, *last;
void create(int length)
{
    first = NULL;
    struct node *n, *last;
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element:\n");
    scanf("%d", &n->data);
    n->next = NULL;
    first = n;
    last = n;
    for(int i = 1; i < length; i++)
    {
        n = (struct node *)malloc(sizeof(struct node)); 
        scanf("%d", &n->data);
        n->next = NULL;
        last->next = n;
        last = last->next; 
    }
}
void display(struct node *p)
{
    printf("Elements inside the list are:\n");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void Insert(struct node *p, int pos, int x)
{
    if(pos == 0)
    {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {
        for(int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if(p != NULL) {    
           struct node *t;
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->next = p->next;
           p->next = t;
        }
    }
}
void InsertLast(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
    { 
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void SortedInsert(struct node *p, int x)
{
    struct node *q = NULL; 
    while(p->data < x && p)
    {
        q = p;  
        p = p->next;
    }
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = p;
    q->next = t;
}
int main()
{
    int length, x;
    printf("Enter the length of the linked list!\n");
    scanf("%d", &length);
    create(length);
    //similarly you can manually write insert function to add elements in between nodes as well 
    /*printf("Enter elements:\n");
    for(int i = 0; i < length; i++) 
    {   scanf("%d", &x);
        Insert(first, i, x);
    }*/
    //InsertLast(8);
    //InsertLast(9); 
    //InsertLast(10);
    SortedInsert(first, 6);
    display(first);
    return 0;
}
