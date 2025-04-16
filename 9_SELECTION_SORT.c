#include<stdio.h>
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

int main()
{
    int k[8]={1,5,3,9,188,25,78,63};
    selectionsort(k,8);
    for(int i=0;i<8;i++)
    {
        printf("%d ",k[i]);
    }

}
