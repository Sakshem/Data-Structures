#include <iostream>
using namespace std;

class DEQueue 
{
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    DEQueue (int size);
    ~DEQueue ();
    void display ();
    void enqueueFront (int value);
    void enqueueRear (int value);
    int dequeueFront ();
    int dequeueRear ();
    bool isEmpty ();
    bool isFull ();
};

inline DEQueue :: DEQueue (int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = (int *) malloc (sizeof (int) * size);
    //Q = new int [size];
}
DEQueue :: ~DEQueue () 
{
    delete [] Q;
    //free (Q);
}
bool DEQueue :: isEmpty ()
{
    if (front == rear) { 
        //cout << "queue is empty!" << '\n';
        return true;
    }
    return false;
}
bool DEQueue :: isFull ()
{
    if (rear == size - 1) return true;

    return false;
}
void DEQueue :: enqueueFront (int value)
{
    if (front == -1) cout << "DEQueue Overflow!" << '\n';
    else {
        Q[front] = value;
        front--;
    }
}
void DEQueue :: enqueueRear (int value)
{
    if (rear == size - 1) cout << "DEQueue Overflow!" << '\n';
    else {
        rear++;
        Q[rear] = value;
    }
}
int DEQueue :: dequeueFront ()
{
    int x = -1;
    if (front == rear) cout << "DEQueue Underflow!" << '\n';
    else {
        x = Q[front];
        front++;
    }
    return x;
}
int DEQueue :: dequeueRear ()
{
    int x = -1;
    if (rear == -1) cout << "DEQueue Underflow!" << '\n';
    else {
        x = Q[rear];
        rear--;
    }
    return x;
}
void DEQueue :: display ()
{
    if (isEmpty ()) { cout << "DEQueue is empty!" << '\n'; return; }
    for (int i = front + 1; i <= rear; i++) {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << "<-" << flush;
        }
    }
    cout << '\n';
}
int main ()
{
    int A[] = {1, 3, 5, 7, 9};
    int length_A = sizeof (A) / sizeof (A[0]);
    DEQueue deq (length_A);
    for (int i = 0; i < length_A; i++) {
        deq.enqueueRear (A[i]);
    }
    deq.display ();
    deq.enqueueRear (11);
    cout << '\n';
    for (int i = 0; i < length_A; i++) {
        deq.dequeueFront ();
    }
    deq.display ();
    deq.~DEQueue ();
    return 0;
}
