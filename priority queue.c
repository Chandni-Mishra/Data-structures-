#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void insert_by_priority(int,int*,int*,int*);
void delete_by_priority(int*,int*,int*);
void check(int,int*,int*);
void display_pqueue(int*,int,int); 
void main(){
 int n, ch;
 int pri_que[MAX];
 int front = -1, rear=-1;
 while (1) {
 printf("\n1 - Insert an element into queue");
 printf("\n2 - Delete an element from queue");
 printf("\n3 - Display queue elements");
 printf("\n4 - Exit");
 printf("\nEnter your choice : "); 
 scanf("%d", &ch);
 switch (ch) {
 case 1: 
 printf("\nEnter value to be inserted : ");
 scanf("%d",&n);
 insert_by_priority(n,pri_que,&front,&rear);
 break;
 case 2:
 // printf("\nEnter value to delete : ");
 // scanf("%d",&n);
 delete_by_priority(pri_que,&front,&rear);
 break;
 case 3: 
 display_pqueue(pri_que,front,rear);
 break;
 case 4: 
 exit(0);
 default: 
 printf("\nChoice is incorrect, Enter a correct choice");
 }}}
/* Function to insert value into priority queue */
void insert_by_priority(int data,int *pri_que,int *front,int *rear){
CHANDNI MISHRA Sec – B 20012871
27
 if (*rear >= MAX - 1) {
 printf("\nQueue overflow no more elements can be inserted");
 return;
 }
 if ((*front == -1) && (*rear == -1)) {
 *front = *front+1;
 *rear = *rear+1;
 pri_que[*rear] = data;
 return;
 } 
 else{
 check(data,pri_que,rear);
 *rear = *rear+1;
}
void check(int data,int *pri_que,int *rear){
 int i,j;
 for (i = 0; i <= *rear; i++) {
 if (data >= pri_que[i]) {
 for (j = *rear + 1; j > i; j--) {
 pri_que[j] = pri_que[j - 1];
 }
 pri_que[i] = data;
 return;
 }
 }
 pri_que[i] = data;
}
void delete_by_priority(int *pri_que,int *front,int *rear){
 int i;
 if ((*front==-1) && (*rear==-1)) {
 printf("\nQueue is empty no elements to delete");
 return;}
 printf("The deleted item is :- %d",pri_que[*front]);
 *front = *front+1;
}
void display_pqueue(int *pri_que,int front,int rear){
 if ((front == -1) && (rear == -1)) {
 printf("\nQueue is empty");
 return;
 }
 for (; front <= rear; front++) {
 printf(" %d ", pri_que[front]);
 }
