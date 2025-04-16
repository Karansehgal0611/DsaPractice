#include<stdio.h>
void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int k[8]={1,5,3,9,188,25,78,63};
    insertionsort(k,8);
    for(int i=7;i>=0;i--)
    {
        printf("%d ",k[i]);
    }

}
