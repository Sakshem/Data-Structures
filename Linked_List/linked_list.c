#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;
void create(int A[],int n)
{   
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++)
    {
       t = (struct node*)malloc(sizeof(struct node));
       t->data = A[i];
       t->next = NULL;
       last->next = t;
       last = t;
    }
}
void display(struct node *p)
{   
   int count = 0; 
    while(p != NULL)
    {   
        printf("%d\n", p->data);
        count++;
        p = p->next;
    }
    printf("total number of nodes in this linked list is:%d", count);
}
void Rdisplay(struct node *p)
{
    if(p != NULL)
    {
        printf("\n");
        printf("%d\n", p->data);
        Rdisplay(p->next);
    }
}
void rdisplay(struct node *p)
{
   printf("elements in reverse order are:");
   if(p != NULL)
   {
       rdisplay(p->next);
       printf("%d\n", p->data);
   }
}
int count(struct node *p)
{
   int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int Rcount(struct node *p)
{
    if(p == 0)
     return 0;
    
    else 
      return Rcount(p->next)+1;
}
int sum(struct node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int Rsum(struct node *p)
{
    if(p != NULL)
            return Rsum(p->next) + p->data;
    else 
            return 0;

}
int max(struct node *p)
{
    int m = -32768;
    while(p)
    {
        if (p->data > m)
               m = p->data;
        p = p->next;
    }
    return m;
}
int Rmax(struct node *p)
{
    int x; 
    //int m = -32768;
    if(p == 0)
            return -32768;
    else{
        x = Rmax(p->next);
        if(x > p->data)
                return x;
        else 
                return p->data;
    }
}
int rmax(struct node *p)
{
    int x;
    if(p == NULL)
            return -32768;
    x = rmax(p->next);
    return x > p->data ? x : p->data;
}
struct node * Lsearch(struct node *p, int key)
{
    struct node * q = NULL;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p; 
            return p;
        }
        q = p;    
        p = p->next;
    }
    return NULL;
    
} 
struct node * Rsearch(struct node *p, int key)
{
   if (p == NULL)
           return NULL;
   else if(key == p->data)
           return p;
   return Rsearch(p->next, key);
}
int main()
{
    int arr[] = { 3,5,7,10,15 };
    create(arr,5);
   struct node *temp;
   temp =  Lsearch(first, 10);
   temp = Lsearch(first, 7);
   if(temp != NULL)
   {
      printf("Key is found %d\n", temp->data);
   }
   else 
           printf("Key is not found");
   display(first);
    //int length =  count(first);
    //printf("length = %d", length);
    //printf("\nlength using recursion is :%d", Rcount(first));
    //printf("\nThe sum of the elements are: %d", sum(first));
    //printf("\nThe sum using recursion is:%d\n", Rsum(first));
    //display(first);
    //Rdisplay(first);
    //rdisplay(first);
    //printf("Max is %d\n", max(first));
    printf("MAX using recursion is %d\n", Rmax(first)); 
    //printf("Max using alternative recursion: %d\n",rmax(first));
    return 0;
}
