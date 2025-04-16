#include<stdio.h>
void hanoi(int n ,char source ,char aux ,char target)
{
    if(n==1)
    {
        printf("move disk 1 from %c to %c\n",source,target);
        return;
    }
    hanoi(n-1,source,target,aux);
    printf("move disk %d from %c to %c\n",n,source,target);
    hanoi(n-1,aux,source,target);
}
void main()
{
    hanoi(4,'A','B','C');
}
