//Circular queue using arrays
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
    q->front = 0;
    q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q, int value)
{
    if((q->rear + 1) % q->size == q->front)
        puts("Queue is full!");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = value;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        puts("Queue is empty!");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    if(q.rear == q.front)
        puts("Queue is empty!");
    else {
    int i = (q.front + 1) % q.size;
    puts("Elements inside queue are:");
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    puts("");
    }
}
/*void display2(struct queue q)
{
    puts("Elements inside circular queue are:");
    int i = q.front;
    printf("q.rear + 1 = %d\n", q.rear + 1);
    while(i != q.rear)
    {
        i = (i + 1) % q.size;
        printf("%d ", q.Q[i]);
    }
    puts("");
}*/
int main()
{
    struct queue q;
    create(&q, 5); //five is the maximum size of the queue

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);

    printf("deleted element %d\n", dequeue(&q));
    printf("deleted element %d\n", dequeue(&q));
    printf("deleted element %d\n", dequeue(&q));
    printf("deleted element %d\n", dequeue(&q));
    //enqueue(&q, 50);
    display(q);
    return 0;
}
