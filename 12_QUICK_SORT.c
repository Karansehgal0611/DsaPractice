#include<stdio.h>
int partition(int arr[], int lb, int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    int temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
}
void quicksort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
int main()
{
    int k[8]={1,5,3,9,188,25,78,63};
    quicksort(k,0,7);
    for(int i=0;i<8;i++)
    {
        printf("%d ",k[i]);
    }

}
