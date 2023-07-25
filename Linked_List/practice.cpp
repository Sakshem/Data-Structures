#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void insertLast(int data) {
    struct node *n = new node;
    // struct node *n = new struct node;
    // struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (first == NULL) {
        first = last = n;
    } else {
        last->next = n;
        last = n;
    }
}
void deleteData(int data) {
    struct node *p = first, *tail = first;
    if (first->data == data) {
        first = first->next;
        return;
    }
    while (p) {
        if (p->data == data) {
            tail->next = p->next;
            p->next = NULL;
            break;
        }
        tail = p;
        p = p->next;
    }
}
void reverse() {
    struct node *p, *q, *r;
    p = q = r = NULL;
    p = first;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void printLL(struct node *p) {
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << '\n';
}
int main() {
    insertLast(10);
    insertLast(20);
    insertLast(30);
    printLL(first);
    deleteData(15);
    printLL(first);

    return 0;
}