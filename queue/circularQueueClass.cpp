#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    private:
    int size;
    int front_pointer;
    int rear;
    int *Q;
    public:
    CircularQueue(int capacity) {
        size = capacity + 1;
        front_pointer = 0;
        rear = 0;
        Q = new int[size];
    }

    bool enqueue(int val) {
        if ((rear + 1) % size == front_pointer) {
            cout << "Queue is full!" << '\n';
            return false;
        }
        else {
            rear = (rear + 1) % size;
            Q[rear] = val;
        }
        return true;
    }

    bool dequeue() {
        int x = -1;
        if (rear == front_pointer) {
            cout << "Queue is empty!" << '\n';
            return false;
        }
        else {
            front_pointer = (front_pointer + 1) % size;
            x = Q[front_pointer];
        }
        return true;
    }

    int front() {
        return Q[(front_pointer + 1) % size];
    }

    int top() {
        return Q[rear]; 
    }

    bool isFull() {
        if ((rear + 1) % size == front_pointer) return true;
        return false;
    }

    bool isEmpty() {
        if (rear == front_pointer) {
            return true;
        } 
        return false;
    }
};
int main()
{
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.top(); 
    return 0;
}