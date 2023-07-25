import java.util.*;
// Similar to ArrayDeque
public class ArrayQueue {     
    private int size;
    private int front;
    private int rear;
    private int[] queue;
    public ArrayQueue(int size) {
	this.size = size;
	queue = new int[size];
	this.front = 0;
	this.rear = 0;
    }

    // enqueue
    public void enqueue(int number) {
	if (rear == size) {
	    System.out.
		println("Queue is full, can't add more number");
	    return;
	}
	queue[rear++] = number;
    } 

    // dequeue
    public int dequeue() {
	if (front == size || front == rear) {
	    // since queue is empty making front and rear back 0
	    front = 0;
	    rear = 0;
	    System.out.
		println("Queue is empty, can't remove more element");
	    return -1;
	}
	int val = queue[front];
	queue[front++] = 0;
	return val;
    }

    // peek
    public int peek() {
	return queue[front];
    }

    // isEmpty
    public boolean isEmpty() {
	return front == 0 ? true : false;
    }

    // isFull
    public boolean isFull() {
	return front == rear;
    }

    @Override
    public String toString() {
	return Arrays.toString(queue);
    }
}
