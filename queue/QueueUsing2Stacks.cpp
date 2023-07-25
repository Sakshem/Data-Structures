#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    private:
    stack <int> e_stk;
    stack <int> d_stk;

    public:
    Queue () {};
    ~Queue () {};
    void enqueue (int x);
    int dequeue ();
};
void Queue :: enqueue (int value)
{
    e_stk.push (value);
}
int Queue :: dequeue ()
{
    int x = -1;
    if (d_stk.empty ()) {
        if (e_stk.empty ()) {
            cout << "Queue overflow!" << '\n';
            return x;
        }
        else {
            while (!e_stk.empty ()) {
                d_stk.push (e_stk.top ());
                e_stk.pop ();
            }
        }
    }
    x = d_stk.top ();
    d_stk.pop ();
    return x;
}
int main ()
{
    int A[] = {1, 3, 5, 7, 9};
    int length = sizeof (A) / sizeof (A[0]);
    Queue q;
    cout << "Enqueue: " << endl;
    for (int i = 0; i < length; i++) {
        q.enqueue (A[i]);
        cout << A[i] << ' ';
    }
    cout << '\n';
    cout << "Dequeue: " << endl;
    for (int i = 0; i < length - 1; i++) {
        cout << q.dequeue () << ' ';
    }
    cout << '\n';
    return 0;
}
