#include<stdio.h>
#include<conio.h>
void Insertion(void);
void Deletion(void);
void Display(void);
struct cqueue{
    int a[5];
    int front,rear;

}cq;

void main(){
    int choice;
    cq.front=-1;
    cq.rear=-1;
    do{
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Insertion();
                break;
            case 2:
                Deletion();
                break;
            case 3:
                Display();
                break;    
        }

    }while(choice<4);
}

void Insertion(){
    int item;
    if(cq.front==(cq.rear+1)%5)
    {
        printf("queue is full\n");
    }
    else{
        printf("Enter the item:");
        scanf("%d",&item);
        if(cq.rear==-1){
            cq.rear++;
            cq.front++;
            cq.a[cq.rear]=item;
        }
        else{
            cq.rear=((cq.rear+1)%5);
            cq.a[cq.rear]=item;
        }
    }
}

void Deletion(){
    if(cq.rear==-1){
        printf("queue empty\n\n");
    }
    else{
        if(cq.front==cq.rear){
            cq.front=-1;
            cq.rear=-1;
        }
        else
            cq.front=((cq.front+1)%5);
    }
}

void Display(){
    int temp;
    if(cq.rear==-1){
        printf("queue empty\n\n");
    }
    else{
        temp=cq.front;
        while(temp!=cq.rear){
            printf("%d\t",cq.a[temp]);
            temp=((temp+1)%5);
        }
        printf("%d",cq.a[temp]);
    }
}