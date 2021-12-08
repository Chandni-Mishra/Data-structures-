#include<stdio.h>
 #include<stdlib.h>
 #define max 100
 void push(int *arr,int *top)
 {
     if(*top == max-1)
     {
        printf("Stack is full can't insert any element\n");
     }
     else
     {
        int element;
        printf("Enter the element to be inserted\n");
        scanf("%d",&element);
        *top = *top+1;
        *(arr+(*top)) = element;
     }
 }
 void pop(int *arr,int *top)
 {
     if(*top == -1)
     {
        printf("Stack is empty\n");
     }
     else
     {
        printf("Deleted item is %d\n",*(arr+(*top)));
        *top = *top-1;
     }
 }
 void display(int *arr,int top)
 {
     printf("Elements of stack are\n");
     for(int i=top;i>=0;i--)
     {
        printf("%d ",*(arr+i));
     }
 }
 int main()
 {
     int arr[max],n;
     int top=-1,q = 1;
     while(q){
     printf("\nChoices available are\n1.Push\n2.Pop\n3.Display\n4.Peak\n5.quit\n");
     int choice;
     printf("Enter your choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
      push(arr,&top);
      break;
     case 2:
       pop(arr,&top);
       break;
     case 3:
       display(arr,top);
       break;
     case 4:
       printf("%d",arr[top]);
       break;
     case 5:
        q = 0;
        break;
     }
     }
        return 0;
 }
