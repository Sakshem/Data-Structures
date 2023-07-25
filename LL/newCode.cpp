/*#include <bits/stdc++.h>
using namespace std;
struct node
{	
	struct node *prev;
	int data;
	struct node *next;
} *first = NULL;
int length (struct node *p)
{
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}
void display (struct node *p)
{
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << '\n';
}
void insert (struct node *p, int index, int x)
{	
	struct node *t;
	if (index < 0 || index > length (p))
	return;
	if (index == 0) {
		t = (struct node *) malloc (sizeof(struct node));
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
		cout << first->data << '\n';
	}
	else {
		for (int i = 0; i < index; i++) {
			p = p->next;
		}
		t = (struct node *) malloc (sizeof(struct node));
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if (p->next) { p->next->prev = t; }
		p->next = t;
	}
}
int main ()
{
	insert (first, 0, 10);
	insert (first, 1, 20);
	insert (first, 2, 30);
	display (first);
	return 0;
}*/
#include <iostream>
using namespace std;
struct node 
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;
void display (struct node *p)
{
    while (p)
    {
        cout << p->data << '\n';
        p = p->next;
    }
}
int length (struct node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void insert (struct node *p, int index, int value)
{
    struct node *t;
    if (index < 0 || index > length (p)) { cout << "Returning from insert!" << '\n'; return; }
    else if (index == 0) {
        t = (struct node *) malloc (sizeof (struct node));
        t->data = value;
        t->prev = NULL;
        t->next = first;
        if (first != NULL) 
        first->prev = t;
        first = t;
    }
    else {
        for (int i = 0; i < index; i++)
        {
            if (p->next != NULL)
            p = p->next;
        }
        t = (struct node *) malloc (sizeof (struct node));
        t->data = value;
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL) p->next->prev = t;
        p->next = t;
    }
}
int deleteNode (struct node *p, int index)
{
    struct node *q;
    int x = -1;
    if (index < 1 || index > length (p)) return -1;
    if (index == 1) {
        first = first->next;
        if (first) first->prev = NULL;
        x = p->data;
        free (p);
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        x = p->data;
        free (p);
    }
    return x;
}
int main ()
{
    insert (first, 0, 10);
    insert (first, 1, 20);
    insert (first, 2, 30);
    display (first);
    cout << "element deleted " << deleteNode (first, 1) << '\n';
    cout << "Element deleted " << deleteNode (first, 2) << '\n';
    display (first);
    return 0;
}