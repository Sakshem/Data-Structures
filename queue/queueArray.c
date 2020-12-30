#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q, int value)
{
    if(q->rear == q->size - 1)
    {
        puts("Queue is full!");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = value;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if(q->front == q->rear) {
        puts("Queue is empty!");
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct queue *q)
{
    if(q->front == q->rear) {
        puts("Queue is empty!");
        return 1;
    }
    return 0;
}
void display(struct queue p)
{
    puts("The elements inside queue are:");
    for(int i = p.front + 1; i <= p.rear; i++)
    {
        printf("%d ", p.Q[i]);
    }        
    puts("");
}
int main()
{
    struct queue q;
    create(&q, 3);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    printf("Deleted %d\n", dequeue(&q));
    printf("Deleted %d\n", dequeue(&q));
    printf("Deleted %d\n", dequeue(&q));
    printf("Deleted %d\n", dequeue(&q));

    display(q);
    return 0;
}
