public class SinglyLinkedList {

    class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    public Node first;
    public Node last;

    public SinglyLinkedList() {
        first = last = null;
    }

    public void insertLast(int data) {
        Node n = new Node(data);
        if (first == null) {
            first = last = n;
        }
        else {
            last.next = n;
            last = n;
        }
    }
    
    public void insertFirst(int data) {
        Node n = new Node(data);
        if (first == null) {
            first = last = n;
        }
        else {
            n.next = first;
            first = n;
        }
    }

    public void insertArray(int[] arr) {
        if (arr.length <= 0) throw new RuntimeException("array is empty");
        Node n = new Node(arr[0]);
        first = last = n;
        for (int i = 1; i < arr.length; i++) {
            n = new Node(arr[i]);
            last.next = n;
            last = n;
        }
    }

    public void display() {
        if (first == null) {
            System.out.println("Linked list is empty!");
            return;
        }
        Node p = first;
        System.out.println("Elements in the linked list are: ");
        while (p != null) {
            System.out.println(p.data);
            p = p.next;
        }
    }

    public int deleteFirst() {
        if (first == null) {
            throw new RuntimeException("linked list is empty, cannot perform deleteFirst");
        }
        Node t = first;
        first = first.next;
        t.next = null;
        return t.data;
    }

    public int deleteLast() {
        if (first == null) {
            throw new RuntimeException("linked list is empty, cannot perform deleteFirst");
        }
        if (first == last) {
            first = last = null;
        }
        Node t = first;
        while (t.next != last) {
            t = t.next;
        }
        t.next = null;
        int val = last.data;
        last = t;
        return val;
    }

    public void reverse() {
        Node p, q, r;
        p = first;
        q = r = null;
        while (p != null) {
            r = q;
            q = p;
            p = p.next;
            q.next = r;
        }
        first = q;
    }

    public void recursiveReverse(Node q, Node p) {
        if (p != null) {
            recursiveReverse(p, p.next);
            p.next = q;
        }
        else {
            first = q;
        }
    }

    public boolean containsLoop() {
        Node p, q;
        p = q = first;
        do {
            p = p.next;
            q = q.next;
            q = (q != null) ? q.next : null;
        } while (p != null && q != null && p != q);

        return (p == q);
    }
}
