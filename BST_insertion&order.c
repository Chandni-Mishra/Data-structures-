#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
void insert_node(node **temp,int data)
{
    if(*temp == NULL)
    {
        node *ptr;
        ptr=(node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        *temp = ptr;
    }
    else
    {
        if((*temp)->data > data)
        {
            insert_node(&((*temp)->left),data);
        }
        else
        {
            insert_node(&((*temp)->right),data);
        }
    }
}
void display_in(node *root)
{
     if(root != NULL)
     {
         display_in(root->left);
         printf("%d ",root->data);
         display_in(root->right);
     }
}
void display_pre(node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        display_pre(root->left);
        display_pre(root->right);
    }
}
void display_post(node *root){
    if(root != NULL)
    {
        display_post(root->left);
        display_post(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    node *root = NULL;
    insert_node(&root,20);
    insert_node(&root,1);
    insert_node(&root,67);
    insert_node(&root,58);
    insert_node(&root,12);
    insert_node(&root,32);
    insert_node(&root,4);
    printf("In preorder elements are\n");
    display_pre(root);
    printf("\n");
    printf("In inorder elements are\n");
    display_in(root);
    printf("\n");
    printf("In postorder elements are\n");
    display_post(root);
    return 0;
}
