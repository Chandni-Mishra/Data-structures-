#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *pre;
    struct node *next;
}node;
void createlinkedlist(node **head,node **tail,int n)
{
    for(int i = 0;i<n;i++)
    {
        node *ptr;
        int num;
        ptr = (node*)malloc(sizeof(node));
        printf("Enter number to insert and press enter:- ");
        scanf("%d",&num);
        ptr->data = num;
        ptr->pre = NULL;
        ptr->next = NULL;
        if(*head == NULL)
        {
            *head = *tail = ptr;
        }
        else{
            ptr->pre = *tail;
            (*tail)->next = ptr;
            *tail = ptr;
        }
    }
}
void display(node *head){
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
void displayreverse(node *tail){
    while(tail != NULL)
    {
        printf("%d ",tail->data);
        tail = tail->pre;
    }
    printf("\n");
}
void insertion_at_first(node **head,int num)
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->pre = NULL;
    ptr->data = num;
    ptr->next = *head;
    (*head)->pre = ptr;
    *head = ptr;
}
void insertion_at_last(node **tail,int num)
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->pre = *tail;
    ptr->data = num;
    ptr->next = NULL;
    (*tail)->next = ptr;
    *tail = ptr;
}
void insertion_at_middle(node **head,int num)
{
    //counting number of node first
    int count=0;
    node *temp = *head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = *head;
    for(int i = 0;i<count/2;i++)
    {
        if(i == (count/2)-1){
            node *ptr;
            ptr = (node*)malloc(sizeof(node));
            ptr->pre = temp;
            ptr->next = temp->next;
            temp->next->pre = ptr;
            temp->next = ptr;
            ptr->data = num;
            break;
        }
        temp=temp->next;
    }
}
void delete_at_first(node **head)
{
    node *temp;
    temp = *head;
    *head = (*head)->next;
    (*head)->pre = NULL;
    free(temp);
}

void delete_at_last(node **tail)
{
    node *temp;
    temp = *tail;
    *tail = (*tail)->pre;
    (*tail)->next = NULL;
    free(temp);
}

void delete_at_middle(node **head)
{
    node *temp;
    int count=0;
    temp = *head;
    //counting number of nodes
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = *head;
    for(int i = 0;i <= count/2;i++)
    {
        if(i == count/2)
        {
            temp->next->pre = temp->pre;
            temp->pre->next = temp->next;
            free(temp);
            break;
        }
        temp = temp->next;
    }
}
int main()
{
    int n,num;
    node *head = NULL;
    node *tail = NULL;
    printf("Enter number of node to create a static linked list:- ");
    scanf("%d",&n);
    
    //createing linked list
    createlinkedlist(&head,&tail,n);
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //inserting element at first
    printf("Enter an element to insert at first:- ");
    scanf("%d",&num);
    insertion_at_first(&head,num);
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //inserting element at last
    printf("Enter an element to insert at last:- ");
    scanf("%d",&num);
    insertion_at_last(&tail,num);
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //inserting element at middle
    printf("Enter an element to insert at middle:- ");
    scanf("%d",&num);
    insertion_at_middle(&head,num);
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //deleting element at first
    delete_at_first(&head);
    printf("Deleting first element\n");
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //deleting element at last
    delete_at_last(&tail);
    printf("Deleting last element\n");
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    printf("\n\n");
    
    //deleting element at middle
    delete_at_middle(&head);
    printf("Deleting middle element\n");
    printf("Elements are:- ");
    display(head);
    printf("Elements in reverse display are:- ");
    displayreverse(tail);
    
    return 0;
}
