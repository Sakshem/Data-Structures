public class Main {
    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        // list.insertLast(10);
        list.insertAtPosition(50, 0);
        list.display();

        System.out.println("deleteLast: " + list.deleteFirst());
        list.display();

    //     SinglyLinkedList list = new SinglyLinkedList();
    //     list.insertLast(10);
    //     list.insertLast(20);
    //     list.insertLast(30);
    //     list.display();
    //     list.insertFirst(5);
    //     list.display();
    //     // System.out.println("after reverse:");
    //     // list.recursiveReverse(null, list.first);
    //     // list.display();
    //     System.out.println("deleting first element: " + list.deleteFirst());
    //     list.display();
    //
    //     System.out.println("deleting last element: " + list.deleteLast());
    //     list.display();
    //
    //     System.out.println("list contains loop? " + list.containsLoop());
    }
}
