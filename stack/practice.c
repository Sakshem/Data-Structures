#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
}*first, *last, *top = NULL;
void push(char value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL) 
        puts("Stack is empty!");

    else
    {
        n->data = value;
        n->next = top;
        top = n;
    }
}
int pop()
{
    struct node *p;
    int x = -1;
    if(top == NULL)
    {
        puts("stack is empty");
    }
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        free(p);
    }
    return x;
}
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;

    return 0;
}
char *convert(char *infix)
{
    int length = strlen(infix);
    char *postfix = (char *)malloc((length + 2) * sizeof(char));
    int i, j;
    i = j = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}
void display(struct node *st)
{
    struct node *p;
    p = top;
    while(p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    puts("");
}
int main()
{
    char *infix = "a+b*c-d/e";
    push(' ');
    char *postfix = convert(infix);
    printf("%s\n", postfix);
    return 0;
}
