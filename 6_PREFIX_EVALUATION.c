#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
struct stack
{
    int arr[25];
    int top;
}st;
char prefix[30];
int pop()
{
    int e;
    e=st.arr[st.top];
    st.top--;
    return e;
}
void push(int x)
{
    st.top++;
    st.arr[st.top]=x;
}
void eval()
{
    int i,op1,op2;
    for(i=0;prefix[i]!='\0';i++)
    {
        switch(prefix[i])
        {
        case '+':
            {
                char res;
                op1=pop();
                op2=pop();
                res=op1+op2;
                push(res);
                break;
            }
        case '-':
            {
                char res;
                op1=pop();
                op2=pop();
                res=op1-op2;
                push(res);
                break;
            }
        case '*':
            {
                char res;
                op1=pop();
                op2=pop();
                res=op1*op2;
                push(res);
                break;
            }
        case '/':
            {
                char res;
                op1=pop();
                op2=pop();
                res=op1/op2;
                push(res);
                break;
            }
        case '^':
            {
                char res;
                op1=pop();
                op2=pop();
                res=pow(op1,op2);
                push(res);
                break;
            }
        default:
            push(prefix[i]-48);
        }
    }
}
void main()
{
    st.top=-1;
    scanf("%s",&prefix);
    strrev(prefix);
    eval();
    printf("%d",st.arr[st.top]);
}
