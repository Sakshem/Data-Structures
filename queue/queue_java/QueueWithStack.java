import java.util.*;
public class QueueWithStack {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public QueueWithStack() {
	stack1 = new Stack<>();
	stack2 = new Stack<>();
    }

    public void enqueue(int number) {
	stack1.push(number);
    }

    public int dequeue() {
	if (stack1.isEmpty()) {
	    throw new IllegalStateException();
	}
	if (stack2.isEmpty()) {
	    while (!stack1.isEmpty()) {
		stack2.push(stack1.pop());
	    }
	}
	return stack2.pop();
    }
}
