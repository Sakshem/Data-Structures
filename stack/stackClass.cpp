#include <bits/stdc++.h>
using namespace std;

class myStack //don't name this class as "stack" as it will give you an error since there is already a class stack present.
{
    private:
    int *s;
    int size;
    int top;
    public:
    myStack (int size) { 
        this->size = size;
        top = -1;
        s = new int[size];
    }
    void push (int value);
    int pop ();
    int peek (int index);
    int isEmpty ();
    int isFull ();
    void display ();
};
void myStack :: push (int value)
{
    if (top == size - 1) cout << "stack overflow!" << '\n';
    else {
        top++;
        s[top] = value;
    }
}
int myStack :: pop ()
{
    int x = -1;
    if (top == -1) cout << "stack underflow!" << '\n';
    else {
        x = s[top];
        top--;
    }
    return x;
}
void myStack :: display ()
{
    if (top == -1) cout << "No elements inside stack!" << '\n';
    else
    {
        cout << "Elements inside stack are:" << '\n';
        for (int i = top; i >= 0; i--) {
            cout << s[i] << ' ';
        }
        cout << '\n';
    }
}
int myStack :: peek (int index)
{
    int x = -1;
    if (top - index + 1 < 0)
    cout << "Invalid index!" << '\n';
    else 
    x = s[top - index + 1];

    return x;
}
int myStack :: isEmpty ()
{
    return (top == -1) ? 1 : 0;
}
int myStack :: isFull ()
{
    return (top == size - 1) ? 1 : 0;
}
int main ()
{
    myStack st (5);
    st.push (10);
    st.push (20);
    st.push (30);
    st.push (40);
    st.push (50);
    cout << "element is: " << st.peek (2) << '\n';
    cout << "Element removed: " << st.pop () << '\n';
    if (!st.isEmpty()) cout << "stack is not empty!" << '\n';
    else cout << "stack is empty!" << '\n';
    st.display ();
    return 0;
}
