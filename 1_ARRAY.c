#include<stdio.h>
int main()
{
    int arr[10];
    int n,pos,key,x,flag=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    //INSERTION
    scanf("%d",&pos);
    scanf("%d",&key);
    for(int i=n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=key;
     for(int i=0;i<n+1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%\n");
    //DELETION
    scanf("%d",&x);
    for(int i=0;i<n+1;i++)
    {
        if(arr[i]==x)
        {
            pos=i;
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("Element not found");
    }
    else
    {
        for(int i=pos;i<n+1;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n+1;i++)
    {
        printf("%d ",arr[i]);
    }
    }
    return 0;
}

