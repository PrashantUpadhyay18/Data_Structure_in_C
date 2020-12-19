//Queue implementation using static array 
#include<stdio.h>
#define SIZE 3
int arr[SIZE];
int front=-1,back=-1;
void insert_queue(int d)
{
    if(back==SIZE-1 || front==SIZE-1)
        printf("\n Overflow\n");
    else
        {
            if(front==-1)
                {
                    front++;back++;
                    arr[front]=d;
                }
            else
                {
                    back++;
                    arr[back]=d;
                }
            
        }
}
void delete()
{
    if(front==-1 || back==-1 || front==back+1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        front++;
    }
}
void display()
{
    for(int i=front;i<=back;i++)
        printf("%d \n",arr[i]);
}
int main()
{
    insert_queue(5);
    insert_queue(10);
    insert_queue(3);
    printf("\nDisplaying all the elements in queue\n");
    display();
    delete();
    printf("Displaying all elements in a queue after deleting one element\n");
    display();
    return 0;
}