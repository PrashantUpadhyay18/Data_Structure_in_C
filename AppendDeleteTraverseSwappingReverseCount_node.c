// All about single linked 

#include<stdio.h> //Basic c lib used for i/o operation
#include<stdlib.h> //used because of malloc fun

//Creating a node
struct node{
    int data;
    struct node *next;
};
//Count the Number of nodes in Linked list
int count_node(struct node **temp){
    struct node *temp1=*temp;
    int count=0;
    while(temp1!=NULL){
        count++;
        temp1=temp1->next;
    }
    return count;
}
//append operation
void append(int d, struct node **temp){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    if(*temp==NULL)
        *temp=new;
    else{
        struct node *temp1=*temp;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=new;
    }
}
//deletion of node using Index
void delete_node(struct node **temp,int index){
    int total_no_node=count_node(&*temp);
    if(index>total_no_node)
        printf("\n Invalid index number");
    else
    {
        if(index==1)
        {
             struct node *new=*temp;
            *temp=new->next;
        }
        else
        {
            struct node *prev=*temp;
            for(int i=1;i<index-1;i++)
            {
                prev=prev->next;
            }
            prev->next=prev->next->next;
        }
    }
}
//Traverse Operation
void Traverse(struct node **temp){
    if(*temp==NULL){
        printf("\nNo nodes are Present");
    }
    else{
        struct node *temp1=*temp;
        while(temp1!=NULL)
        {
            printf(" %d",temp1->data);
            temp1=temp1->next;
        }
    }
    
}

//Swapping two nodes of linked list using Index
//Note: Index1 should always be less than Index2
void Swap_using_index(struct node **temp,int index1,int index2){
    int total_node=count_node(&*temp);
    if(index1>total_node || index2>total_node || index1<=0 || index2<=0 || index1>=index2 || index1+1==index2)
    {
        if(1+index1==index2)
        {
            if(index1==1)
            {
                struct node *root=*temp;
                struct node *temp1=root->next->next,*temp2=root->next;
                root->next->next=root;
                root->next=temp1;
                *temp=temp2;
                
            }
            else
            {
                struct node *prev=*temp;
                for(int i=1;i<2-1;i++)
                    prev=prev->next;
                struct node *temp1=prev->next,*temp2=temp1->next;
                temp1->next=temp2->next;
                temp2->next=temp1;
                prev->next=temp2;
                    
            }
        }
        else
        {
             printf("Index Numbers are not valid");
        }
    }
       
    else{
        if(index1==1){
            struct node *prev_index2=*temp,*temp2=*temp;
            for(int i=1;i<index2-1;i++)
            {
                prev_index2=prev_index2->next;
            }
            struct node *temp1=prev_index2->next->next;
            prev_index2->next->next=temp2->next;
            *temp=prev_index2->next;
            prev_index2->next=temp2;
            temp2->next=temp1;
        }
        else{
            struct node * prev1=*temp, *prev2=*temp;
            for(int i=1;i<index1-1;i++)
            {
                prev1=prev1->next;
            }
            for(int i=1;i<index2-1;i++)
            {
                prev2=prev2->next;
            }
            struct node *temp1=prev1->next->next,*temp2=prev1->next,*temp3=prev2->next->next,*temp4=*temp;
            prev1->next=prev2->next;
            prev1->next->next=temp1;
            prev2->next=temp2;
            prev2->next->next=temp3;
        }
        
    }
    
}
//Reversing of Sigle Linked list by swapping data
void reverse(struct node **root)
{
    struct node *root1=*root;
    int total_node=count_node(&root1);
    int n=(total_node/2),j=total_node,i;
    for(i=1;i<=n;i++)
    {
        Swap_using_index(&root1,i,j);
        j--;
    }
    printf("\n1st Linked list after reversing by data");
    Traverse(&root1);
    
}
//Main Function
int main(){
    struct node *start1=NULL,*start2=NULL;
    append(4,&start1);
    append(5,&start1);
    append(6,&start1);
    append(7,&start1);
    append(8,&start1);
    append(8,&start2);
    append(99,&start2);
    append(45,&start2);
    printf("\nThe total number of node in 1st Linked list is: %d",count_node(&start1));
    printf("\n1st Single Linked list elements of are: ");
    Traverse(&start1);
    Swap_using_index(&start1,4,5);
    printf("\n1st Single Linked list elements of are after swap 4th and 5th index: ");
    Traverse(&start1);
    reverse(&start1);
    printf("\n2st Single Linked list elements of are: ");
    Traverse(&start2);
}