#include<stdio.h>
struct stack
{
    int arr[5];
    int top;
}st;
int main()
{
    st.top=-1;
    int x;
    for(int i=0;i<6;i++)
    {
        scanf("%d",&x);
        push(x);
    }
    display();
    printf("\n");
    pop();
    display();
    printf("\n");
    pop();
    display();
    return 0;
}
void push(int e)
{
    if(st.top==4)
    {
        printf("Stack overflow");
    }
    else
    {
        st.top++;
        st.arr[st.top]=e;
    }
}
void pop()
{
    if(st.top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        st.top--;
    }
}
void display()
{
    int temp;
    if(st.top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        temp=st.top;
        while(temp>=0)
        {
            printf("%d ",st.arr[temp]);
            temp--;
        }
    }
}
