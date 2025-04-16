#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
struct avl
{
    int e;
    struct avl* left;
    struct avl* right;
    int h;
};
struct avl* head=NULL;
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(struct avl* n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        return n->h;
    }
}
struct avl* singleleft(struct avl* k2);
struct avl* singleright(struct avl* k1);
struct avl* insert(struct avl* root, int key)
{
    if(root==NULL)
    {
        root=(struct avl*)malloc(sizeof(struct avl));
        root->e=key;
        root->right=NULL;
        root->left=NULL;
        root->h=0;
        if(head==NULL)
        {
            head=root;
        }
    }
    else if(key<root->e)
    {
        root->left=insert(root->left,key);
    }
    else
    {
        root->right=insert(root->right,key);
    }

    root->h=1+max(height(root->right),height(root->left));

    int bf=height(root->left)-height(root->right);

    //LL CASE
    if(bf>1 && key < root->left->e)
    {
        return singleright(root);
    }
    //LR CASE
    else if(bf>1&&key>root->left->e)
    {
        root->left=singleleft(root->left);
        return singleright(root);
    }
    //RR CASE
    else if(bf<1&&key>root->right->e)
    {
        return singleleft(root);
    }
    //RL CASE
    else if(bf<1&&key<root->right->e)
    {
        root->right=singleright(root->right);
        return singleleft(root);
    }
    return root;
};
struct avl* singleright(struct avl* k1)
{
    struct avl* k2;
    k2=k1->left;
    k1->left=k2->right;
    k2->right=k1;
    k1->h=1+max(height(k1->left),height(k1->right));
    k2->h=1+max(height(k2->left),height(k2->right));
    return k2;
};
struct avl* singleleft(struct avl* k2)
{
    struct avl* k1;
    k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k1->h=1+max(height(k1->left),height(k1->right));
    k2->h=1+max(height(k2->left),height(k2->right));
    return k1;

};
void Inorder(struct avl* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ",root->e);
    Inorder(root->right);
}

void preorder(struct avl* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->e);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct avl* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->e);
}
int main()
{
    int n,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d);
        head=insert(head,d);
    }
    preorder(head);
    printf("\n");
    Inorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
    return 0;
}
