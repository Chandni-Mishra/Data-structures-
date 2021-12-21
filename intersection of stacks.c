#include<stdio.h>
#include<stdlib.h>
#define max 100
void push(int *arr,int *top,int num);
void display(int *arr,int *top);
void intersection(int *arr,int *arr1,int *top,int *top1);
int main()
{
    int top=-1,top1 = -1;
    int arr[max],arr1[max];
    int n;
    printf("Enter total number to be entered\n");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        int num;
        printf("Enter number\n");
        scanf("%d",&num);
    push(arr,&top,num);
    }
     for(int i = 0;i<n;i++)
    {
        int num;
        printf("Enter number\n");
        scanf("%d",&num);
    push(arr1,&top1,num);
    }
    display(arr,&top);
    display(arr1,&top1);
    intersection(arr,arr1,&top,&top1);
    return 0;
}
void push(int *arr,int *top,int num)
{
    if(*top == max-1)
    {
        printf("Stack is full\n");
    }
    else
    {

        *top = *top+1;
        *(arr+(*top)) = num;
    }
}
void display(int *arr,int *top)
{
    for(int i=(*top);i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void intersection(int *arr,int *arr1,int *top,int *top1)
{
     for(int i=(*top);i>=0;i--)
     {
         for(int j=(*top1);j>=0;j--)
         {
              if(arr[i] == arr1[j])
              {
                  printf("%d ",arr[i]);
              }
         }
     }
}
