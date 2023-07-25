#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //there are various functions in stack STL in c++
    //Creating a stack
    stack <int> st; //creating a object of class stack, name is st
    st.push (10); //pushing elements inside stack
    st.push (20);
    st.push (30);
    st.push (40);
    cout << '\n';
    auto display = [&] (stack <int> st) { //displays elements inside stack
        cout << "Elements inside stack are: " << '\n';
        while (!st.empty()) {
            cout << st.top() << ' ';
            st.pop(); //this actually doesn't pop elements out of the main object of the class stack
            //it pops copy of the elements that was passed through the arguments
            // to actually remove the elements while displaying we can simple put '&' before st inside the parameter
            //like this: auto display = [&] (stack <int> &st)
        }
        cout << '\n';
        return 0;
    };
    display (st); //calling the above display function to display elements inside stack
    cout << "size of the stack is: " << st.size() << '\n'; //returns the size of the stack
    cout << "Element at the top of the stack is: " << st.top() << '\n'; //returns the topmost element inside stack
    cout << "popping element out of the stack: " << '\n';
    st.pop(); //popped the topmost element inside the stack
    cout << '\n';
    display (st);
    cout << st.empty() << '\n'; //returns true if stack is actually empty otherwise false
    //stack::swap() function
    //this swap function is used to swap the contents of one stack to another stack
    //creating a new stack
    stack <int> st3;
    st3.push (1);
    st3.push (2);
    st3.push (3);
    st3.push (4);
    st3.push (5);
    cout << "Created a new stack st3!" << '\n';
    display (st3);
    //now swapping with stack st
    st3.swap (st);
    cout << "Contents of st3 was swapped with st!" << '\n';
    cout << "stack st:" << '\n';
    display (st);
    cout << "stack st3:" << '\n';
    display (st3);
    //stack::emplace()
    //emplace function is used to insert new element inside the stack
    stack <int> st4;
    st4.emplace (100);
    st4.emplace (200);
    st4.emplace (300);
    st4.emplace (400);
    cout << "Stack st4!" << '\n';
    display (st4);
    //difference between stack::push() and stack::emplace()
    //push function inserts a copy of the value passed in the parameter
    //emplace function constructs a new element as the value of the parameter and then adds to the top
    return 0;
}