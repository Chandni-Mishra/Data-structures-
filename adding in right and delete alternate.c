#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int data;
 struct node *next;
}node;
void create(node **head,int n){
 for (int i = 0; i < n; i++) {
 node *ptr,*temp;
 ptr = (node*)malloc(sizeof(node));
 printf("Enter data:- ");
 scanf("%d",&(ptr->data));
 ptr->next = NULL;
 if(*head == NULL){
 *head = temp = ptr;
 }
 else {
 temp->next = ptr;
 temp = ptr;
 }
 } 
}
void delete_alternatenode(node **head){
 node *temp = *head;
 while (temp->next != NULL) {
 node *ptr;
 ptr = temp->next;
 temp->next = ptr->next;
 free(ptr);
 temp = temp->next;
 }
}
void display(node *head){
 while (head != NULL) {
 printf("%d ",head->data);
 head = head->next;
 }
 printf("\n");
 
}
int main(int argc, char const *argv[])
{
 printf("NAME-CHANDNI MISHRA \nSECTION-B\nID-20012871\n");
 node *head = NULL;
 create(&head,5);
 display(head);
 delete_alternatenode(&head);
 display(head);
 return 0;
 }
