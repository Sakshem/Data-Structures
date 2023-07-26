#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first;
void create(int A[], int size)
{
    struct node *n, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    n = first;
    last = first;
    for(int i = 1; i < size; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        n->data = A[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
}
void Insert(int pos, int x)
{
    struct node *p, *n;
    if(pos == 0)
    {
        n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = NULL;
        n->next = first;
        first = n;
    }
    else
    {
        p = first;
        for(int i = 0; i < pos - 1; i++)
        {
            p = p->next; 
        }
        n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = NULL;
        n->next = p->next;
        p->next = n;
    }    
}
void insertLast(int x)
{
    struct node *n, *last;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
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
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void deleteNodeAfter_x(struct node *p, int x)
{
    struct node *t = first;
    while(p)
    {
        if(p->data == x)
            break;
        p = p->next;
        t = p;
    }
    printf("t = %d\n", t->data);
    //deleting node after the given data
    t = t->next;
    p->next = t->next;
    t = NULL;
}
void deleteNodeBefore_x(struct node *p, int x)
{
    struct node *t = first;
    while(p)
    {
        if((p->next->data) == x)
            break;
        t = p;
        p = p->next;
    }
    //deleting node before the given element x
    printf("p = %d t = %d\n", p->data, t->data);
    t->next = p->next;
    p = NULL;
    free(p);
}
int main()
{
    int x;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    /*for(int i = 0; i < 5; i++) { 
        printf("enter any number: ");
        scanf("%d", &x);
        Insert(i, x);
    }
    Insert(4, 200);
    insertLast(112);*/
    deleteNodeAfter_x(first, 30);
    deleteNodeBefore_x(first, 30);
    display(first);
    return 0;
}
