#include<stdio.h>
#include<stdlib.h>
//creating a linked list
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *first;
    first = NULL;
    //creating a node
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));

    n->data = 10;
    n->next = NULL;

    first = n;
    //creating another node
    n = (struct node *)malloc(sizeof(struct node));
    n->data = 20;
    n->next = NULL;
    struct node *t;
    t = first;
    t->next = n;

    //creating a new node
    n = (struct node *)malloc(sizeof(struct node));
    n->data = 30;
    n->next = NULL;
    
    t = t->next;
    t->next = n;
    //creating a new node
    n = (struct node *)malloc(sizeof(struct node));
    n->data = 40;
    n->next = NULL;

    t = t->next;
    t->next = n;
    //creating a new node
    n = (struct node *)malloc(sizeof(struct node));
    n->data = 50;
    n->next = NULL;
    t = t->next;
    t->next = n;
    //printing elements in a linked list

    struct node *p;
    p = first;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    free(p);
    free(t);
    free(n);
    return 0;
}
