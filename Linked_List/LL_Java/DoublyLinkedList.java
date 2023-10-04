public class DoublyLinkedList {
    class Node {
        Node prev;
        int data;
        Node next;
        public Node(int data) {
            this.data = data;
            prev = next = null;
        }
    }
    public Node first;
    public Node last;
    public DoublyLinkedList() {
        first = last = null;
    }

    public void insertLast(int data) {
        Node n = new Node(data);
        if (first == null) {
            first = last = n;
        }
        else {
            last.next = n;
            n.prev = last;
            last = n;
        }
    }

    public void insertAtPosition(int data, int index) {
        int len = length();
        if (index < 0 || index > len) {
            System.out.println("index is invalid");
            return;
        }
        Node p = first;
        Node n = new Node(data);
        if (first == null) {
            first = last = n;
            return;
        }
        if (index == 0) {
            n.next = first;
            first.prev = n;
            first = n;
        }
        else if (index == len) {
            last.next = n;
            n.prev = last;
            last = n;
        }
        else {
            for (int i = 0; i < index && p != null; i++) {
                p = p.next;
            }
            // System.out.println("p.data:" + p.data);
            //
            // System.out.println("p.prev.data:" + p.prev.data);
            n.next = p;
            n.prev = p.prev;
            p.prev.next = n;
            p.prev = n;
            // System.out.println("n.data" + n.data);
            //
            // System.out.println("n.prev.data" + n.prev.data);
            //
            // System.out.println("n.next.data" + n.next.data);
            //
            // System.out.println("first.next.data" + first.next.data);
        }
    }
    
    public int deleteFirst() {
        if (first == null) {
            throw new RuntimeException("List is empty, cannot perform deleteFirst");
        }
        if (first.next == null) {
            int val = first.data;
            first = last = null;
            return val;
        }
        Node t = first;
        first = first.next;
        t.next = null;
        t.prev = null;
        first.prev = null;
        return t.data;
    }

    public int deleteLast() {
        if (first == null) {
            throw new RuntimeException("List is empty, cannot perform deleteFirst");
        }
        if (first == last) {
            int val = first.data;
            first = last = null;
            return val;
        }
        Node t = last;
        last = last.prev;
        last.next = null;
        t.prev = t.next = null;
        return t.data;
    }

    public void reverse() {
        Node temp = null;
        Node current = first;
        while (current != null) {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        }

        if (temp != null) {
            first = temp.prev;
        }
    }    

    public void display() {
        if (first == null) {
            System.out.println("list is empty!");
            return;
        }
        Node p = first;
        System.out.println("Elements in the doubly linked list are: ");
        while (p != null) {
            System.out.println(p.data);
            p = p.next;
        }
    }

    public int length() {
        Node p = first;
        int length = 0;
        while (p != null) {
            length++;
            p = p.next;
        }
        return length;
    }
}
