#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
struct stack
{
    int arr[25];
    int top;
}st;
char postfix[60];

void push(int x)
{
    st.top++;
    st.arr[st.top]=x;
}
int pop()
{
    int e;
    e=st.arr[st.top];
    st.top--;
    return e;
}
void eval()
{
    int op1,op2;
    for(int i=0;postfix[i]!='\0';i++)
    {

        switch(postfix[i])
        {
            case '+':
                {
                char res;
                op1=pop();
                op2=pop();
                res=(op2)+(op1);
                push(res);
                break;
                }

            case '-':
                {
                    char res;
                    op1=pop();
                    op2=pop();
                    res=(op2)-(op1);
                    push(res);
                    break;
                }
            case '*':
                {
                    char res;
                    op1=pop();
                    op2=pop();
                    res=(op2)*(op1);
                    push(res);
                    break;
                }
            case '/':
                {
                    char res;
                    op1=pop();
                    op2=pop();
                    res=(op2)/(op1);
                    push(res);
                    break;
                }
            case '^':
                {
                    char res;
                    op1=pop();
                    op2=pop();
                    res=pow((op2),(op1));
                    push(res);
                    break;
                }
            default:
                push(postfix[i]-48);

        }
    }
}
void main()
{
    st.top=-1;
    scanf("%s",&postfix);
    eval();
    printf("%d",st.arr[st.top]);
}

