import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        // Here the cities are visited lexicographically.
        // addInOrder method compares the new city to the current city on placesToVisit linked list
        // and then add it accordingly to the list. 
        LinkedList<String> placesToVisit = new LinkedList<String>();
        addInOrder(placesToVisit, "Sydney");
        addInOrder(placesToVisit, "Melbourne");
        addInOrder(placesToVisit, "Brisbane");
        addInOrder(placesToVisit, "Perth");
        addInOrder(placesToVisit, "Canberra");
        addInOrder(placesToVisit, "Adelaide");
        addInOrder(placesToVisit, "Darwin");

        printList(placesToVisit); // It prints the data of each nodes in the linked list.

        addInOrder(placesToVisit, "Alice Springs");
        addInOrder(placesToVisit, "Darwin");

        printList(placesToVisit);
        visit(placesToVisit);

        /* placesToVisit.add(1, "Alice Springs");
        printList(placesToVisit);
        placesToVisit.remove(4); // This removes the node on position 4.
        printList(placesToVisit);*/
        /*--------------------------------------*/
    }
    private static void printList (LinkedList<String> linkedList) {
        Iterator<String> i = linkedList.iterator();
        System.out.println("Elements in the linkedList are:");
        while (i.hasNext()) { // hasNext() checks is there another entry or node.
            System.out.println("Now visiting " + i.next());
            // i.next() returns the value of a particular node before moving to the next node
        }
        System.out.println("=============================");
    }
    private static boolean addInOrder (LinkedList<String> linkedList, String newCity) {
        ListIterator<String> stringListIterator = linkedList.listIterator();
        while (stringListIterator.hasNext()) {
            int comparison = stringListIterator.next().compareTo(newCity);
            if (comparison == 0) {
                // equal, do not add.
                System.out.println(newCity + " is already included as a destination");
                return false;
            }
            else if (comparison > 0) {
                // newCity should appear before this one.
                stringListIterator.previous();
                stringListIterator.add(newCity);
                return true;
            }
            else if (comparison < 0) {
                // move on to the next city. (Do nothing since it has already moved to the next node using .next() method on line 46)
            }
        }
        stringListIterator.add(newCity);
        return true;
    }
    private static void visit (LinkedList cities) {
        Scanner scanner = new Scanner(System.in);
        boolean quit = false;
        boolean goingForward = true;
        ListIterator<String> listIterator = cities.listIterator();
        if (cities.isEmpty()) {
            System.out.println("No cities in the itinerary!");
            return;
        }
        else {
            System.out.println("Now visiting " + listIterator.next());
            printMenu(); // calls the method printMenu() to print actions that we can visit next city or move back to previous city.
        }
        while (!quit) {
            int action = scanner.nextInt();
            scanner.nextLine();
            switch (action) {
                case 0 -> {
                    System.out.println("Vacation over!");
                    quit = true;
                }
                case 1 -> {
                    if (!goingForward) {
                        if (listIterator.hasNext()) {
                            listIterator.next();
                        }
                        goingForward = true;
                    }
                    if (listIterator.hasNext()) {
                        System.out.println("Now visiting " + listIterator.next());
                    }
                    else {
                        System.out.println("Reached the end of the list!");
                        goingForward = false;
                    }
                }
                case 2 -> {
                    if (goingForward) {
                        if (listIterator.hasPrevious()) {
                            listIterator.previous();
                        }
                        goingForward = false;
                    }
                    if (listIterator.hasPrevious()) {
                        System.out.println("Now visiting " + listIterator.previous());
                    }
                    else {
                        System.out.println("We are at the start of the list!");
                        goingForward = true;
                    }
                }
                case 3 -> {
                    printMenu();
                }
            }
        }
    }
    private static void printMenu () {
        System.out.println("Available actions:\npress ");
        System.out.println("0 - to quit\n" +
                           "1 - go to next city\n" +
                           "2 - go to the previous city\n" +
                           "3 - to print menu.");
    }
}
