#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int data;
 struct node *next;
 struct node *pre;
}node;
void create_dll(node **head,node **last){
 node *ptr;
 ptr = (node*)malloc(sizeof(node));
 printf("Enter data:- ");
 scanf("%d",&(ptr->data));
 ptr->pre = NULL;
 ptr->next = NULL;
 if(*head == NULL) {
 *head = *last = ptr;
 }
 else{
 (*last)->next = ptr;
 ptr->pre = *last;
 *last = ptr;
 }
}
int count_nodes(node *head){
 int count;
 while (head != NULL){
 count++;
 head = head->next;
 }
 return count;
}
void check_pallindrome(node *head,node *last){
 int flag = 0;
 int n;
 n = count_nodes(head);
 for(int i = 0;i<n/2;i++) {
 if(head->data == last->data){
 flag = 1;
 }
 else{
 flag = 0;
 break;
 }
 head = head->next;
 last = last->pre;
 }
 if(flag == 1)
CHANDNI MISHRA Sec – B 20012871
39
 {
 printf("The doubly linked list is a pallindrome\n");
 }
 else{
 printf("The doubly linked list is not a pallindrome\n");
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
 printf("Name-CHANDNI MISHRA\nSEC-B\nID-20012871\n");
 int choice;
 node *head = NULL,*last = NULL;
 int q = 1;
 while (q)
 {
 printf("1.Insert node\n2.Check pallindrome\n3.display\n4.quit\n");
 scanf("%d",&choice);
 switch (choice){
 case 1:
 create_dll(&head,&last);
 break;
 case 2:
 check_pallindrome(head,last);
 break;
 case 3:
 display(head);
 break;
 case 4:
 q = 0;
 break;
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
}
