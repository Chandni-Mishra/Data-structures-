#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void create(node **head,int n)
{
    for (int i = 0; i < n; i++)
    {
        node *ptr,*temp;
        ptr = (node*)malloc(sizeof(node));
        printf("Enter data:- ");
        scanf("%d",&(ptr->data));
        ptr->next = NULL;
        if(*head == NULL)
        {
            *head = temp = ptr;
        }
        else
        {
            temp->next = ptr;
            temp = ptr;
        }
        
    }
    
}
void delete_alternatenode(node **head)
{
    node *temp = *head;
    while (temp->next != NULL)
    {
        node *ptr;
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
        temp = temp->next;
        if(temp == NULL)
        {
            break;
        }
    }
    
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    int n;
    printf("Enter no. of nodes\n");
scanf("%d",&n);
    create(&head,n);
    display(head);
    delete_alternatenode(&head);
    display(head);
    return 0;
}
