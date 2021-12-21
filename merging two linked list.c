#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int data;
 struct node *next;
}node;
void create_linkedlist(node **head,int n){
 for (int i = 0; i < n; i++){
 node *ptr,*temp;
 ptr = (node*)malloc(sizeof(node));
 printf("Enter data:- ");
 scanf("%d",&(ptr->data));
 ptr->next = NULL;
 if(*head == NULL) {
 *head = temp = ptr;
 }
 else{
 temp->next = ptr;
 temp = ptr;
 }
 }
}
void sort_linkedlist(node **head){
 node *ptr = *head;
 node *temp;
 while (ptr != NULL) {
 temp = ptr->next;
 while (temp != NULL) {
 if(ptr->data > temp->data){
 int k;
 k = ptr->data;
 ptr->data = temp->data;
 temp->data = k;
 }
 temp = temp->next;
 }
 ptr = ptr->next;
 }
}
void merge_linkedlist(node **head1,node **head2){
 node* ptr = *head1;
 while (ptr != NULL) {
 if(ptr->next == NULL) {
 ptr->next = *head2;
 break;
CHANDNI MISHRA Sec – B 20012871
36
}
 ptr = ptr->next;
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
 printf("Name-CHANDNI MISHRA\nSEC-B\nID-20012871\n");
 int n;
 node *head1 = NULL, *head2 = NULL;
 printf("Enter the number of node of first linked list:- ");
 scanf("%d",&n);
 create_linkedlist(&head1,n);
 printf("Enter the number of node of second linked list:- ");
 scanf("%d",&n);
 create_linkedlist(&head2,n);
 sort_linkedlist(&head1);
 sort_linkedlist(&head2);
 merge_linkedlist(&head1,&head2);
 display(head1);
 return 0;
 }
