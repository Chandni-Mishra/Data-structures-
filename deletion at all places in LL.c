#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void create_node(int n,node **head);
void display(node **head);
void delete_node(node **head);
void delete_end(node **head);
void delete_mid(node **head);
int main()
{
     node *head;
     int n;
     printf("Enter total number of nodes you want to enter\n");
     scanf("%d",&n);
     create_node(n,&head);
     display(&head);
     delete_node(&head);
     display(&head);
     delete_end(&head);
     display(&head);
     delete_mid(&head);
     display(&head);
     return 0;
}
void create_node(int num,node **head)
{
    for(int i=0;i<num;i++)
    {
        node *ptr,*temp;
        if(i == 0)
        {
            ptr=(node*)malloc(sizeof(node));
            temp = *head = ptr;
            printf("Enter value to be inserted at first place\n");
            scanf("%d",&(ptr->data));
            ptr->next = NULL;
        }
        else
        {
            ptr = (node*)malloc(sizeof(node));
            temp->next = ptr;
            temp = ptr;
            printf("Enter another data\n");
            scanf("%d",&(temp->data));
            temp->next = NULL;
        }
    }
}
void display(node **head)
{
    node *temp;
    temp = *head;
    printf("\nElements in the list are\n");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
//deletion from beggining
void delete_node(node **head)
{
    node *temp;
    temp = *head;  
    *head = temp->next;  
    free(temp);  
}
//deletion from last
void delete_end(node **head)
{
   node *temp,*ptr;
   temp = *head;
   while(temp != NULL){
   if(temp->next->next == NULL)
   {
       ptr = temp->next;
       temp->next = NULL;
       free(ptr);
       break;
   } 
   temp=temp->next;
   }
}
// deletion form mid
void delete_mid(node **head)
{
    int n=0;
    node *temp;
    temp = *head;
    while(temp != NULL)
    {
        n = n+1;
        temp = temp->next;
    }
    temp = *head;
    for(int i=0;i<(n/2);i++)
    {
        if(i == (n/2)-1)
        {
            node *ptr;
            ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
}
