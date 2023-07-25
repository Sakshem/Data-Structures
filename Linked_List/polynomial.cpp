#include <iostream>
using namespace std;
struct node
{
    int pow;
    int coeff;
    struct node *next;
};
void create (struct node **q)
{
    static int poly_count = 1;
    cout << "Enter for " << poly_count << " polynomial." << '\n';
    struct node *n, *head;
    int ans = 1;
    int counter = 0;
    while (true)
    {
        n = (struct node *) malloc (sizeof (struct node));
        int power, coefficient;
        cout << "Enter coefficient: " << '\n';
        cin >> coefficient;
        cout << "Enter power: " << '\n';
        cin >> power;

        n->pow = power;
        n->coeff = coefficient;
        n->next = NULL;
        if (*q == NULL) {
            *q = n;
            head = n;
        }
        if (counter > 0) {
            struct node *p;
            p = head;
            tail = p;
            if (p->next == NULL) {
                if (p->pow > n->pow) {
                    p->next = n;
                }
                else if (p->pow < n->pow) {
                    n->next = p;
                    *q = n;
                    head = n;
                }
            }
            else {
                while (p != NULL) {
                    if (p->pow > n->pow && p->next != NULL) {
                        p = p->next;
                    }
                    if (p->pow > n->pow && p->next == NULL) {
                        p->next = n;
                        break;
                    }
                    else if (p->pow < n->pow) {
                        n->next = head;
                        *q = n;
                        head = n;
                        break;
                    }
                }
            }
        }
        counter++;
        cout << "do you wish to continue? (press 0 for no and 1 for yes)" << '\n';
        cin >> ans;
        if (ans == 0) break;
    }
    poly_count++;
}
void display (struct node *p)
{
    while (p) {
        cout << p->coeff << "x^" << p->pow;
        if (p->next != NULL) cout << " + ";
        else cout << " ";
        p = p->next;
    }
    cout << '\n';
}
struct node *add_poly (struct node *a, struct node *b)
{
    struct node *result = NULL, *res;
    result = (struct node *) malloc (sizeof (struct node));
    res = result;
    int count = 0;
    bool check = true;
    while (a != NULL && b != NULL) {
        if (count > 0) {
        result->next = (struct node *) malloc (sizeof (struct node));
        result = result->next;
        result->next = NULL;
        check = false;
        }
        //case 1:
        if (a->pow > b->pow) {
            result->pow = a->pow;
            result->coeff = a->coeff;
            a = a->next;
        }
        //case 2:
        else if (a->pow < b->pow) {
            result->pow = b->pow;
            result->coeff = b->coeff;
            b = b->next;
        }
        //case 3:
        else if (a->pow == b->pow) {
            cout << "hello" << '\n';
            result->pow = a->pow;
            result->coeff = a->coeff + b->coeff;
            a = a->next;
            b = b->next;
        }
        count++;
    }
    while (a != NULL || b != NULL) {
        if (a) {
            if (check) {
                result->next = (struct node *) malloc (sizeof (struct node));
                result = result->next;
                check = false;
            }
            result->pow = a->pow;
            result->coeff = a->coeff;
            a = a->next;
        }
        if (b) {
            if (check) {
                result->next = (struct node *) malloc (sizeof (struct node));
                result = result->next;
                check = false;
            }
            result->pow = b->pow;
            result->coeff = b->coeff;
            b = b->next;
        }
    }
    result->next = NULL;
    return res;
}
struct node *poly_prod (struct node *a, struct node *b)
{
    struct node *reset = b;
    struct node *res, *temp;
    temp = (struct node *) malloc (sizeof (struct node));
    temp->next = NULL;
    res = temp;
    while (a != NULL) {
        while (b != NULL) {
            temp->coeff = a->coeff * b->coeff;
            temp->pow = a->pow + b->pow;
            if (a->next == NULL) break;
            temp->next = (struct node *) malloc (sizeof (struct node));
            temp = temp->next;
            b = b->next;
        }
        b = reset;
        a = a->next;
    }
    temp->next = NULL;
    return res;
}
int main ()
{
    struct node *a = NULL, *b = NULL;
    create (&a);
    create (&b);
    display (a);
    display (b);
    struct node *result = NULL;
    result = add_poly (a, b);
    cout << "addition: " << '\n';
    display (result);
    cout << '\n';
    struct node *prod_result = poly_prod (a, b);
    cout << "product: " << '\n';
    display (prod_result);
    return 0;
}