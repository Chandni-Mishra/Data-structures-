#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int data;
 struct node *next;
}node;
void enqueue(node **front,node **rear,int num){
 node *ptr;
 ptr = (node*)malloc(sizeof(node));
 ptr->data = num;
 ptr->next = NULL;
 if(*front == NULL) {
 *front = *rear = ptr;
 }
 else{
 (*rear)->next = ptr;
 *rear = ptr;
 }
}
void dequeue(node **front,node **rear){
 node *ptr;
 ptr = *front;
 if(ptr == NULL){
 printf("Queue is empty ");
 }
 if(*front == *rear) {
 printf("Deleted item is:- %d\n",(*front)->data);
 *front = *rear = NULL;
 free(ptr);
 }
 elsE {
 printf("Deleted item is:- %d\n",(*front)->data);
 *front = (*front)->next;
 free(ptr);
 }
}
void display(node *front){
 if(front == NULL)
 {
CHANDNI MISHRA Sec – B 20012871
24
 printf("Queue is empty\n");
 }
 else {
 while(front != NULL)
 {
 printf("%d ",front->data);
 front = front->next;
 }
 printf("\n");
 }
}
int main(){
 int choice;
 node *front = NULL;
 node *rear = NULL;
 int q = 1;
 while(q) {
 printf("NAME-CHANDNI MISHRA\nSECTION-B\nID-20012871\n");
 printf("Enter choice from below option\n");
 printf("1.enqueue\n2.dequeue\n3.display\n4.quit\n");
 scanf("%d",&choice);
 switch (choice){
 case 1:
 printf("Enter a number to enqueue:- ");
 int num;
 scanf("%d",&num);
 enqueue(&front,&rear,num);
 break;
 case 2:
 dequeue(&front,&rear);
 break;
 case 3:
 printf("Elements in the queue are:- ");
 display(front);
 break;
 case 4:
 q = 0;
 break;
 }
 }
 return 0;
}
