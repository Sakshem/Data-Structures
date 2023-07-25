#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Stack
{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st)
{
    printf("Enter size:\n");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void display(struct Stack st)
{
    printf("Elements in the stack are:\n");
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    puts("");
}
void push(struct Stack *st, int x)
{
    if(st->top == st->size -1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack underflow\n");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}
int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top - index + 1 < 0)
        printf("Invalid Index\n");
    else
    {
        x = st.s[st.top - index + 1];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    return 0;
}
int StackTop(struct Stack st)
{
    if(!isEmpty)
        return st.s[st.top];
    return -1;
}
int main()
{
    struct Stack st;
    create(&st); 
    //push
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    //peek
    //printf("%d\n", peek(st, 2)); 
    //pop
    //printf("%d\n", pop(&st));    
    //printf("%d\n", pop(&st)); 
    //display
    display(st);
    return 0;
}
