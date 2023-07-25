//https://www.geeksforgeeks.org/subtract-1-from-a-number-represented-as-linked-list/
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first = NULL, *last = NULL;

void insertLast(int value) {
    if (first == NULL) {
        first = (struct node *)malloc(sizeof(struct node));
        first->data = value;
        first->next = NULL;
        last = first;
    }
    else {
        struct node *n;
        n = (struct node *)malloc(sizeof(struct node));
        n->data = value;
        n->next = NULL;
        last->next = n;
        last = n;
    }
}
void subtractOne(struct node *p) {
    struct node *t = first;
    //simple condition: 123 -> 122
    //advanced condition: 120 -> 119
    //more advanced condition: 100 -> 99
    //example 2: 12000 -> 11999
    //example 3: 12032 -> 12031

    //simple condition
    if (last->data >= 1) {
        last->data -= 1;
        return;
    }

    //conditions
    if (last->data == 0) {
      	//making p point on the second last node
        while (p->next != last) {
            if (p->data != 0) {
                t = p;
            }
            p = p->next;
        }
        //advanced condition -> 120 -> 119
        if (p->data > 0) {
          	//that is if there are only two nodes
          	//Since t also points on first initially
            if (t == p) {
              	//if the elements are -> 10
              	if (t->data == 1) {
                	first = first->next;
                	first->data = 9;
                	return;
                }
              	//if the elements are -> 20 or 30...
              	else {
                	t->data -= 1;
					last->data = 9;
                  	return;
                }
            }
          	//else if number is something like this -> 10080
          	//That is second last element is greater than 0 and last element is 0
            p->data -= 1;
            last->data = 9;
            return;
        }
        //condition -> 1008000 -> 1007999
        if (first != t) {
            t->data -= 1;
            while (t != last) {
                t = t->next;
                t->data = 9;
            }
            return;
        }
        //condition -> 10000 -> 9999
        else if (first == t) {
            first = first->next;
            t = first;
            while (t) {
                t->data = 9;
                t = t->next;
            }
            return;
        }
    }
}
void display(struct node *p) {
    if (first == NULL) {
        cout << "Linked list is empty!" << '\n';
    }
    else {
        while (p) {
            cout << p->data << ' ';
            p = p->next;
        }
    }
    cout << '\n';
}
int main()
{
    insertLast(1);
    insertLast(0);
    insertLast(0);
    insertLast(0);
    cout << "Original number: " << '\n';
    display(first);
    cout << "Number after subtracting 1 from it: " << '\n';
    subtractOne(first);
    display(first);
    return 0;
}