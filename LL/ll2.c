#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first;
int main()
{
    first = NULL;
    int size;
    printf("Enter the number of elements in the list:\n");
    scanf("%d", &size);
    struct node *n, *last;
    printf("Enter the elements in the list:\n");
    n = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &n->data);
    n->next = NULL;
    first = n;
    last = n;
    for(int i = 1; i < size; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &n->data);
        n->next = NULL;
        last->next = n;
        last = n;
    }
    puts("");
    struct node *p;
    p = first;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    print(first);
    return 0;
}

