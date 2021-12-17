#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void create(int num,node **head);
void display(node **head);
void insert_first(node **head);
void insert_end(node **head);
void insert_middle(int n,node **head);
int main()
{
    int n;
    printf("Enter number of nodes you want to enter\n");
    scanf("%d",&n);
    node *head;
    create(n,&head);
    display(&head);
    insert_first(&head);
    display(&head);
    insert_end(&head);
    display(&head);
    insert_middle(n+2,&head);
    display(&head);
}
void create(int num,node **head)
{
    for(int i=0;i<num;i++)
    {
        node *ptr,*temp;
        if(i == 0)
        {
            ptr = (node*)malloc(sizeof(node));
            temp = *head = ptr;
            printf("Enter the first value to be entered\n");
            scanf("%d",&(ptr->data));
            ptr->next = NULL;
        }
        else
        {
            ptr=(node*)malloc(sizeof(node));
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
   printf("Elements in the list are\n");
  while(temp != NULL)
   {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
//insertion at first
void insert_first(node **head)
{
    node *ptr,*temp;
    ptr = (node*)malloc(sizeof(node));
    ptr->next = *head;
    printf("\nEnter element to be inserted at first place\n");
    scanf("%d",&(ptr->data));
    *head = ptr;
    temp = *head;
}
void insert_end(node **head)
{
    node *ptr,*temp;
    temp = *head;
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            ptr = (node*)malloc(sizeof(node));
            temp->next = ptr;
            temp = ptr;
            printf("\nEnter the value to be inserted at end\n");
            scanf("%d",&(temp->data));
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
}
void insert_middle(int n,node **head)
{
    node *ptr,*temp;
    temp = *head;
    for(int i=0;i<(n/2);i++)
    {
        if(i == (n/2-1))
        {
            ptr=(node*)malloc(sizeof(node));
            ptr->next = temp->next;
            temp->next = ptr;
            temp = ptr;
            printf("\nEnter element to be inserted in middle\n");
            scanf("%d",&(temp->data));
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}
