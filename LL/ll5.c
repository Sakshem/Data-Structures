#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*first, *last;
void display(struct node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("");
}
void create(int length)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter elements:\n");
    scanf("%d", &n->data);
    n->next = NULL;
    first = n;
    last = first;

    for(int i = 1; i < length; i++)
    {
        n = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &n->data);
        n->next = NULL;
        last->next = n;
        last = n;
    }
}
void Insert(struct node *p, int pos, int x)
{
    if(pos == 0)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
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
void InsertLast(struct node *p, int x)
{
    if(first == NULL && last == NULL)
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = NULL;
        first = t;
    }
    else
    {
        struct node *t;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = NULL; 
        last->next = t;
        last = t;
    }
}
void InsertSort(struct node *p, int x)
{
    while(p)
    {
        if(p->data < x)
        p = p->next;
    }
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = p->next;
    p->next = t;
}
int main()
{
    int length;
    printf("Enter length of the list:\n");
    scanf("%d", &length);
    create(length);
    //Insert(first, 4, 12); 
    //InsertLast(first, 13);
    InsertSort(first, 5); 
    display(first);
    return 0;
}
