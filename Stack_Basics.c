//Stack Implementation using single linked std::list 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int d;
    struct node *link;
};

struct node *top=NULL;

void push(int data){
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->d=data;
    new->link=top;
    top=new;
}

struct node *pop(){
    if(top==NULL){
        printf("\nNo node is there");
        return NULL;
    }
    else{
        struct node *temp=top;
        top=top->link;
        return temp;
        
    }
}

void Traverse(){
    if(top==NULL){
        printf("\nNo nodes are Present");
    }
    else{
        struct node *temp=top;
        while(temp!=NULL)
        {
            printf(" %d",temp->d);
            temp=temp->link;
        }
    }
    
}

int main(){
    push(5);
    push(10);
    push(15);
    printf("\n %d is data of Top node\n",top->d);
    printf(" Stack elements are: ");
    Traverse();
    struct node *ad=pop();
    printf("\n %d is the data of poped node",ad->d);
}