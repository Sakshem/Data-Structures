class Node {
    public int data;
    public Node next;

    public Node() {
	this.next = null;
    }
    public Node(int data) {
	this.data = data;
	this.next = null;
    }
}

class linkedList {
    public Node first;
    public Node last;

    public linkedList() {
	first = null;
	last = null;
    }
    public void insert(int data) {
	Node n = new Node(data);
	if (first == null) {
	    first = last = n;
	}
	else {
	    last.next = n;
	    last = n;
	}
    }

    public void insertArray(int[] a) {
	Node n = new Node();
	if (a.length > 0) {
	    n.data = a[0];
	    n.next = null;
	    first = last = n;
	}
	for (int i = 1; i < a.length; i++) {
	    n = new Node(a[i]);
	    last.next = n;
	    last = n;
	}
    }

    public void display() {
	Node p = first;
	while (p != null) {
	    System.out.print(p.data + " ");
	    p = p.next;
	}
	System.out.println();
    }
}

public class sortZeroOneTwoLL {

    public static void main(String[] args) {
	linkedList list = new linkedList();
	list.insertArray(new int[]{1,2,2,1,2,0,2,2});
	System.out.print("list: ");
	list.display();
	sortLinkedList(list.first);
    }

    public static void sortLinkedList(Node head) {
	Node p = head;
	int zeroCount = 0, oneCount = 0, twoCount = 0;
	while (p != null) {
	    switch(p.data) {
		case 0:
		    zeroCount++;
		    break;
		case 1:
		    oneCount++;
		    break;
		case 2:
		    twoCount++;
		    break;
	    }
	    p = p.next;
	}

	p = head;
	while (p != null && zeroCount > 0) {
	    zeroCount--;
	    p.data = 0;
	    p = p.next;
	}

	while (p != null && oneCount > 0) {
	    oneCount--;
	    p.data = 1;
	    p = p.next;
	}

	while (p != null && twoCount > 0) {
	    twoCount--;
	    p.data = 2;
	    p = p.next;
	}

	p = head;
	System.out.println("After sorting: ");
	while (p != null) {
	    System.out.print(p.data + " ");
	    p = p.next;
	}
	System.out.println();
    }
}
