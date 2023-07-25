#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first, *last, *top = NULL;

void push(int x)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        puts("Stack is full!");
        exit(0);
    }
    else {
        n->data = x;
        n->next = top;
        top = n;
    }
}
int pop()
{
    int x = -1;
    struct node *p;
    if(top == NULL)
    {
        puts("Stack is empty!");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p); //in c we use free to deallocate memory
        //in c++ we use delete keyword to deallocate memory 
    }
    return x;
}
void Display()
{
    struct node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("");  
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    
    Display();
    printf("%d\n", pop());    
    return 0;
}
