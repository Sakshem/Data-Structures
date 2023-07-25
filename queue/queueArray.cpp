#include<iostream>
using namespace std;
class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size) { this->size = size; front = -1; rear = -1; Q = new int[this->size]; }
        void enqueue(int value);
        int dequeue();
        void display();
};
void Queue :: enqueue(int value)
{
    if(rear == size - 1)
        cout << "Queue is Full\n";
    else {
        rear++;
        Q[rear] = value;
    }
}
int Queue :: dequeue()
{
    int x = -1;
    if(rear == front)
        cout << "Queue is empty!\n";
    else {
        front++;
        x = Q[front];
    }
    return x;
}
void Queue :: display()
{
    puts("The elements inside the queue are:");
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d ", Q[i]);
    }
    puts("");
}
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.display();

    printf("deleted element from queue: %d\n", q.dequeue());
    printf("deleted element from queue: %d\n", q.dequeue());
    
    q.display();
    return 0;
}
