#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
}*first;
void create(int);
void Display(struct node *);
void sum(struct node *);
int Rsum(struct node *);
void min_max(struct node *);
int Rmin(struct node *);
struct node * Lsearch(struct node *, int);
struct node * Rsearch(struct node *, int);
int main()
{
    int num;
    printf("Enter the size of the list:\n");
    scanf("%d", &num);
    //Creating a linked List 
    create(num);
    sum(first);
    printf("The sum recursively is %d\n", Rsum(first));
    min_max(first);
    printf("Min recursively is %d\n", Rmin(first));
    //Linear search
    struct node *temp;
    temp = Lsearch(first, 10);
    if(temp != NULL)
    {
        printf("Key is found %d\n", temp->data);
    } 
    else
       printf("key is not found!\n"); 
    //Displaying the list
    Display(first);
    return 0;
}
void create(int size)
{
    struct node *n, *last;
    n = (struct node *)malloc(sizeof(struct node)); 
    printf("Enter elements inside the list:\n"); 
    scanf("%d", &n->data);
    first = n;
    last = first;
    for(int i = 1; i < size; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &n->data);
        n->next = NULL;
        last->next = n;
        last = last->next;  
    }
}
void Display(struct node *p)
{
    printf("the elements inside the list are:\n");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("");
}
void sum(struct node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    printf("The sum of the elements inside the list is %d\n", sum);
}
int Rsum(struct node *p)
{
    if(p == 0)
        return 0;
    else
        return Rsum(p->next) + p->data;
}
void min_max(struct node *p)
{
    int min = INT_MAX, max = INT_MIN;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        if(p->data < min)
            min = p->data;
        p = p->next;
    }
    printf("Max = %d\nMin = %d\n", max, min);
}
int Rmin(struct node *p)
{
    int x;
    if(p == 0)
        return INT_MAX;
    else
    {
        x = Rmin(p->next);
        printf("%d\n", x);
        if(x < p->data)
        {
            printf("x = %d && p->data = %d\n", x, p->data);
        }
        else
        {
            printf("else p->data = %d\n", p->data);
            return p->data;
        }
    }
}
struct node* Lsearch(struct node *p, int key)
{
    struct node *q;
    while(p != NULL)
    {
        q = p;
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        p = p->next;
    }
    return NULL;
}
struct node *Rsearch(struct node *p, int key)
{
    if(p == NULL)
        return NULL;
    else {   
        if(key == p->data)
            return p;
        else
            return Rsearch(p->next, key);
    }
}
