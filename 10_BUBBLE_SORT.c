#include<stdio.h>
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}
int main()
{
    int k[8]={1,5,3,9,188,25,78,63};
    bubblesort(k,8);
    for(int i=0;i<8;i++)
    {
        printf("%d ",k[i]);
    }

}
