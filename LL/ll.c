#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data; //part of the node that contains or stores data
    struct node *next;  //pointer to next node
};
int main()
{
    struct node *first; //pointer to a node
    first = NULL;
    //creating a node
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) //just a safety precaution to check if you ran out of memory
        return 1; 
    n->data = 1;
    n->next = NULL;
    first = n; //linking the pointer to the node
    
    //creating another node with same variable n
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    n->data = 2;
    n->next = NULL;
    //now to link the this node to previous we will create a temp pointer 
    struct node *t;
    t = first;
    t->next = n;
    
    //now creating another node 
    n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    n->data = 3;
    n->next = NULL;
    
    //now linking this node to previous node
    t = t->next;
    t->next = n;
    
    //creating another node
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    n->data = 4;
    n->next = NULL;
    t = t->next; //linking this node to previous node
    t->next = n;
    
    //creating last node 
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    n->data = 5;
    n->next = NULL;

    //linking this to previous
    t = t->next;
    t->next = n;
    
    //printing this linked_list
    struct node *p; //used for traversing while printing
    p = first;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    free(p);
    free(n); 
    puts("");
    return 0;
} 
