#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
}*top = NULL;

void push(char x)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        puts("Stack is full!");
        //exit(0);
    }
    else {
        n->data = x;
        n->next = top;
        top = n;
    }
}
char pop()
{
    struct node *p;
    char x = -1;
    //struct node *p;
    if(top == NULL)
    {
        puts("Stack is empty!");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p); //in c we use free to deallocate memory
        //in c++ we use delete keyword to deallocate memory 
    }
    return x;
}
void Display()
{
    struct node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    puts("");  
}
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
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

    else if(x == ')')
        return 3;

    else if(x == '(')
        return 4;

    else
        return 0;
}
char *convert(char *infix)
{
    int length = strlen(infix);
    char *postfix = (char *)malloc((length + 2) * sizeof(char));
    int i, j;
    char y;
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
                if(pop() != '(' && pop() != ')') 
                   postfix[j++] = pop();
                else {
                    y = pop();  
                }
        }
    }
    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "a+b*(c+d)/e";
    //char *infix = "a + b * c - d / e";
    push(' ');
    char *Postfix = convert(infix);
    printf("%s ", Postfix); 
    return 0;
}
