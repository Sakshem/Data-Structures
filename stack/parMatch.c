#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    char data;
    struct node *next;
}*Top = NULL;

void push(char value)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("Stack is full\n");
        exit(0);
    }
    else
    {
        n->data = value;
        n->next = Top;
        Top = n;
    }
}
char pop()
{
    struct node *t;
    char x = -1;
    if(Top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        t = Top;
        Top = Top->next;
        x = t->data;
        free(t);
    }
    return x;
}
bool isBalanced(char *exp)
{
    int x;
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(Top == NULL)
                return false;

            else if(exp[i] - '(' == 1) {
                x = pop();
                if(x != '(')
                    return false;
            }
            else if(exp[i] - '[' == 2) {
                x = pop();
                if(x != '[')
                    return false;
            }
            else if(exp[i] - '{' == 2) {
                x = pop();
                if(x != '{')
                    return false;
            }
        } 
    }
    if(Top == NULL)
        return true;

    else return false;
}
int main()
{
    char *exp = "{([a + b] * [c - d])/e}";
    printf("%d", isBalanced(exp));
    puts("");
    return 0;
}
