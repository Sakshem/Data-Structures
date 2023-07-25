import java.util.*;
public class Basic {
    public static void main(String[] args) {
       QueueWithStack queue = new QueueWithStack();
	queue.enqueue(10);
	queue.enqueue(20);

	System.out.println("removed: " + queue.dequeue());
	// CircularArrayQueue queue = new CircularArrayQueue(5);
	// // ArrayQueue queue = new ArrayQueue(5);
	// queue.enqueue(1);
	// queue.enqueue(2);


	// queue.enqueue(3);
	// queue.enqueue(4);
	// queue.enqueue(5);
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// // queue.enqueue(6);
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());

	// System.out.println(queue.toString());

	// queue.enqueue(10);
	// queue.enqueue(20);
	// queue.enqueue(30);
	// queue.enqueue(40);
 	// queue.enqueue(60);   

	// System.out.println(queue.toString());

	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println("removed: " + queue.dequeue());
	// System.out.println(queue.toString());

	// queue.enqueue(50);
	// System.out.println(queue.toString());

	// System.out.println("removed: " + queue.dequeue());
	// System.out.println(queue.toString());
	// queue.enqueue(10);
	// queue.enqueue(20);
	// queue.enqueue(30);
	// queue.enqueue(40);
 	// queue.enqueue(60);   
	// System.out.println(queue.toString());
	// Queue<Integer> queue = new ArrayDeque<>();
	// queue.add(10);
	// queue.add(20);
	// queue.add(30);
	// queue.add(40);
	// System.out.println(queue);
	// reverse(queue);
	// var front = queue.remove();
	// System.out.println("element removed: " + front);
	// System.out.println("queue now: " + queue);
    }

    public static void reverse(Queue<Integer> queue) {
	Stack<Integer> stack = new Stack<>();
	while (!queue.isEmpty()) {
	    var element = queue.remove();
	    stack.push(element);
	}
	while (!stack.isEmpty()) {
	    queue.add(stack.pop());
	}
	System.out.println("queue reversed: " + queue);
    }
}
