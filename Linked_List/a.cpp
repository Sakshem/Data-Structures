#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void insertLast(int val) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if (first == NULL) {
        first = last = n;
    } else {
        last->next = n;
        last = n;
    }
}
void display(struct node *p) {
    cout << "Elements inside linked list are: " << '\n';
    while (p) {
        cout << p->data << '\n';
        p = p->next;
    }
}
void reverseLL(struct node *p) {
    struct node *q, *r;
    q = r = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void rearrange(struct node *list) {
    struct node *p, *q;
    int temp;
    if ((!list) || (!list->next)) {
        return;
    }
    p = list;
    q = list->next;
    while (q) {
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = p->next;
        q = p?p->next : 0;
    }

}
int main()
{
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    insertLast(5);
    insertLast(6);
    insertLast(7);
    display(first);
    rearrange(first);
    display(first);
    return 0;
}