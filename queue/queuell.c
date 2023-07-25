#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;
void enqueue(int value)
{
    struct node *n;
    if(front == NULL)
    {
        n = (struct node *)malloc(sizeof(struct node));
        if(n == NULL)
            puts("Queue is full!");

        n->data = value;
        n->next = NULL;
        front = n;
        rear = n;
    }
    else
    {
        n = (struct node *)malloc(sizeof(struct node));
        if(n == NULL)
            puts("Queue is full!");
        n->data = value;
        n->next = NULL;
        rear->next = n;
        rear = n;
    }
}
int dequeue()
{
    int x = -1;
    struct node *p;
    if(front == NULL)
        puts("Queue is empty!");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        p->next = NULL;
        free(p);
    }
    return x;
}
void display(struct node *p)
{
    puts("The elements in queue are:");
    while(p != rear->next)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display(front);

    printf("deleted element %d\n", dequeue());
    printf("deleted element %d\n", dequeue());

    display(front);
    return 0;
}
