//Double Linked list declaring root address inside main function
//Append,delete_using_index,count_node,reverse,display function are in the code
#include<stdio.h>
#include<stdlib.h>

//Creating of node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//appending node
void append(struct node **start,int d)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    if(*start==NULL)
    {
        *start=temp;
    }
    else
    {
        struct node *temp1=*start;
        while(temp1->right!=NULL)
        {
            temp1=temp1->right;
        }
        temp->left=temp1;
        temp1->right=temp;
    }
}

//counting total number of nodes in double linked list
int count_node(struct node **start)
{
    struct node *temp=*start;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->right;
    }
    return c;
}

//Deleting node of given index
//index belongs to natural number in below function
void delete_using_index(struct node **start, int index)
{
    int n=count_node(&*start);
    if(n<index )
    {
        printf("\nInvalid index");
    }
    else
    {
        struct node *temp1=*start;
        if(index==1)
        {
            temp1->right->left=NULL;
            *start=temp1->right;
        }
        else if(index==n)
        {
            while(temp1->right!=NULL)
            {
                temp1=temp1->right;
            }
            temp1->left->right=NULL;
        }
        else
        {
            for(int i=1;i<index;i++)
                temp1=temp1->right;
            temp1->left->right=temp1->right;
            temp1->right->left=temp1->left;
        }
    }
}

//Reverse traversing of double linked list
void reverse(struct node **start)
{
    struct node *temp=*start;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    while(temp!=NULL)
    {
        printf("\n %d",temp->data);
        temp=temp->left;
    }
}

//displaying all the elements of linked list
void display(struct node **start)
{
    if(*start==NULL)
        printf("\nNo node are present\n");
    else
    {
        struct node *temp=*start;
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp=temp->right;
        }
    }
}

//main function
int main()
{
    struct node *root=NULL;
    append(&root,5);
    append(&root,10);
    append(&root,53);
    append(&root,57);
    append(&root,8);
    printf("\n Double Linked List element are:\n");
    display(&root);
    printf("\n Total number of nodes in Double Linked List are: %d\n",count_node(&root));
    printf("\n Double Linked List element after reversing are:\n");
    reverse(&root);
    printf("\n Double Linked List element after deleting 3rd index are:\n");
    delete_using_index(&root,3);
    display(&root);
    return 0;
}
