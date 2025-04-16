#include<stdio.h>
void merge(int arr[],int lb, int mid, int ub)
{
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    int b[ub+1];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    else if(j>ub)
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            k++;
            i++;
        }
    }
    for(int i=lb;i<=ub;i++)
    {
        arr[i]=b[i];
    }
}
void mergesort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int main()
{
    int k[8]={1,5,3,9,188,25,78,63};
    mergesort(k,0,8);
    for(int i=0;i<8;i++)
    {
        printf("%d ",k[i]);
    }

}
