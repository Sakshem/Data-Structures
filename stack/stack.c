#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};
void push(struct stack *st, int x) //to add a element in the stack
{
    if(st->top == st->size - 1)
    {
        printf("Stack Overflow!\n"); //stack is full
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st) //to remove the top most element in stack
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Stack Underflow!\n"); //stack is empty
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack st, int pos) //to find the element at a given position
{
    int x = -1;
    if(st.top - pos + 1 < 0)
        printf("Invalid position!\n");
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}
int stackTop(struct stack st) //to find what is the top most element in the stack
{
    if(st.top == -1)
        return -1;
    else
        return st.s[st.top];
}
int isEmpty(struct stack st) //to check if the stack is empty or not
{
    if(st.top == -1)
        return -1;
    else
        return 0;
}
int isFull(struct stack st) //to check if the stack is full or not
{
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}
void create(struct stack *st) //creating a stack 
{
    printf("Enter size of the stack:\n");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void display(struct stack st) //displaying the elements of the stack
{
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    puts("");
}
int main()
{
    struct stack st;
    create(&st);
    //pushing elements inside stack
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    //push(&st, 60); //stack overflow message if size is 5 
    display(st);

    printf ("%d\n", peek (st, 1)); 
    //poping elements out of the stack
    printf("the element removed is: %d\n", pop(&st));
    printf("The element removed is: %d\n", pop(&st));
    
    //peeking element at position 1
    printf("the element at %d is: %d\n", 1, peek(st, 1));
    display(st);
}
