#include<stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node* right;
};
struct node* head=NULL;
struct node* curr;
void insert_at_end(int x)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->e=x;
    nn->right=NULL;
    if(head==NULL)
    {
        head=nn;
        curr = nn;
    }
    else
    {
        curr=head;
        while(curr->right!=NULL)
        {
            curr=curr->right;
        }
        curr->right=nn;
    }

}
void display()
{
    curr=head;
     while(curr->right!=NULL)
     {
          curr=curr->right;
          printf("%d ",curr->e);
     }
}
void main()
{
    int n,e,y;
    scanf("%d",&n);
    insert_at_end(6);
    insert_at_end(6);
    insert_at_end(6);
    insert_at_end(6);
    display();
}
