//adding a node after a node in a DOUBLEY LINKLIST
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next, *prev;
} * first, *n, *temp,*ttemp, *p, *m;
void createnode(int arr[], int size)
{
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = first->prev = NULL;
    temp = first;
    for (int i = 1; i < size; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        n->data = arr[i];
        n->next = NULL;
        n->prev = temp;
        temp->next = n;
        temp = temp->next;
    }
}
void display()
{
    temp = first;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}
void addbefore(int x,int val)
{
    temp = ttemp = first ;
    while(temp->data != x)
    {
        ttemp = temp;
        temp =temp->next;
    }
    m = (struct node *)malloc(sizeof(struct node));
    m->data = val;
    m->prev = ttemp;
    ttemp->next = m;
    m->next = temp;
    temp->prev = m;


}
void addafter(int x, int val)
{
    
    temp = first;
    printf("temp = %d\n", temp->data);
    printf("first = %d\n", first->data); 
    while (temp->data != x)
    {
        temp = temp->next;
    }
    printf("after while: %d\n", temp->data);
    m = (struct node *)malloc(sizeof(struct node));
    m->data = val;
    m->prev = temp;
    m->next= NULL; 
    if(temp->next != NULL) {
    p = temp->next;
    temp->next = m;
    m->next = p;
    p->prev = m;
    }
    else
        temp->next = m;
}
int main()
{
    cout << "enter the size of linklist = ";
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    createnode(arr, n);
    display();
    addafter(5, 10);
    display(); 
    /*   int i,m;
    cout<<"\nenter the node u want to add =  ";
    cin>>m;
    cout<<"\n after which node = ";
    cin>>i;
    addafter(i,m);
    display();

    cout<<"\nenter the node u want to add =  ";
    cin>>m;
    cout<<"\n before which node = ";
    cin>>i;
    addbefore(i,m);
    display();
*/
    return 0;
}
