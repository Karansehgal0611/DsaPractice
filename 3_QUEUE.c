#include<stdio.h>
struct queue
{
    int arr[5];
    int front;
    int rear;
}q;
void enqueue(int x)
{
    if(q.rear==4)
    {
        printf("Queue Overflow");
    }
    else
    {
        if(q.rear==-1)
        {
            q.rear++;
            q.front++;
            q.arr[q.rear]=x;
        }
        else
        {
            q.rear++;
            q.arr[q.rear]=x;
        }
    }
}
void dequeue()
{
    if(q.rear==-1)
    {
        printf("Queue Undeflow");
    }
    else
    {
        if(q.rear==q.front)
        {
            q.rear=-1;
            q.front=-1;
        }
        else
        {
            q.front++;
        }
    }
}
void display()
{
    int temp;
    if(q.rear==-1)
    {
        printf("Queue Underflow");
    }
    else
    {
        temp=q.front;
        while(temp<=q.rear)
        {
            printf("%d ",q.arr[temp]);
            temp++;
        }
    }
}
void main()
{
    q.rear=-1;
    q.front=-1;
    int x;
    for(int i=0;i<5;i++)
    {
        scanf("%d ",&x);
        enqueue(x);
    }
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
    enqueue(8);
    display();
    printf("\n");


}
