//ascending priority queue using array
//Karan Vyas
//22BIT0092
#include<stdio.h>
#include<conio.h>
int cq_full(void);
int cq_empty(void);
void priority(void);
struct apqueue
{
int a[5];
int front,rear;
} apq;
void main()
{
int choice,item,temp;
apq.front=-1;
apq.rear=-1;
do
{
printf("\n1.insertion\n2.deletion\n3.display\n4.exit");
printf("\nEnter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
if(cq_full()==1)
printf("\nqueue is full");
else
{
printf("\nenter the item");
scanf("%d",&item);
if(apq.rear==-1)
{
apq.front=0;
apq.rear=0;
apq.a[apq.rear]=item;
}
else
apq.a[++apq.rear]=item;
}
priority();
break;
}
case 2:
{
if(cq_empty()==1)
printf("\nqueue empty");
else
{
if((apq.rear==apq.front)&&(apq.rear!=-1))
   {
       apq.rear=-1;
       apq.front=-1;
       }
       else
        apq.front++;
}
break;
}
case 3:
{
    if(cq_empty()==1)
        printf("\nqueue empty");
    else
        {
            temp=apq.front;// priority();
    while(temp<=apq.rear)
        {
            printf("%d\t",apq.a[temp]);
    temp++;
    }
    }
    }
    break;
    }
    } while(choice<4);
}

int cq_full()
{
    if(apq.rear==4)
        return 1;
    else
        return 0;
}

int cq_empty()
{
    if(apq.rear==-1)
        return 1;
    else
        return 0;
}

void priority()
{
    int i,j,k,temp;
    for(i=1;i<=apq.rear;i++) // Changed number of iterations and comparison
    {
        temp = apq.a[i];
        j = i - 1;
        while (j >= 0 && apq.a[j] > temp)// Shift elements greater than temp to the right
        {
            apq.a[j + 1] = apq.a[j];
            j--;
        }

        apq.a[j + 1] = temp; // Insert temp at the correct position
    }
}