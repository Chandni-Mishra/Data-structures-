#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    float sum=0;
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    printf("Enter the number of columns\n");
    scanf("%d",&m);
    int *ptr[n];
    for(int i=0;i<n;i++)
    {
        ptr[i] = (int*)malloc(m*sizeof(int));
    }
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&ptr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        sum = 0;
         for(int j=0;j<m;j++)
        {
         sum = sum+ptr[j][i];
        }
        printf("%0.2f ",(sum/m));
    }

    return 0;
}


