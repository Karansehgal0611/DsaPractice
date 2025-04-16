#include<stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node* left;
    struct node* right;
};
struct node* createNode(int x)
{
    struct node* nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->e=x;
    nn->right=NULL;
    nn->left=NULL;
    return nn;
}
struct node* insert(struct node* root,int key)
{
    if(root==NULL)
    {
        root=createNode(key);
    }
    else if(key>root->e)
    {
        root->right=insert(root->right,key);
    }
    else
    {
        root->left=insert(root->left,key);
    }
    return root;
}
void Inorder(struct node* head)
{
    if(head==NULL)
    {
        return;
    }
    Inorder(head->left);
    printf("%d ",head->e);
    Inorder(head->right);
}
struct node* find_min(struct node* head)
{
    if(head==NULL)
    {
        return head;
    }
    else if(head->left==NULL)
    {
        return head;
    }
    else
    {
        return find_min(head->left);
    }
};
struct node* find_max(struct node* head)
{
    if(head==NULL)
    {
        return head;
    }
    else if(head->right==NULL)
    {
        return head;
    }
    else
    {
        return find_max(head->right);
    }
}
struct node* SearchBST(struct node* head, int key)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(key>head->e)
    {
        return SearchBST(head->right,key);
    }
    else if(key<head->e)
    {
        return SearchBST(head->left,key);
    }
    else
    {
        return head;
    }
}
struct node* delete_min(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left==NULL)
    {
        struct node* temp=root->right;
        free(root);
        return temp;
    }
    root->left=delete_min(root->left);
    return root;
};
struct node* deletion(struct node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(key>root->e)
    {
        root->right=deletion(root->right,key);
    }
    else if(key<root->e)
    {
        root->left=deletion(root->left,key);
    }
    else
    {
        if(root->right==NULL && root->left==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=find_min(root->right);
        root->e=temp->e;
        root->right=delete_min(root->right);

    }
    return root;
};
int main()
{
    int x,f;
    struct node* root=NULL;
    for(int i=0;i<8;i++)
    {
        printf("Enter the element: ");
        scanf("%d",&x);
        root=insert(root,x);
    }
    Inorder(root);
    printf("\n");
    struct node* min =find_min(root);
    printf(" %d ",min->e);
    struct node* max =find_max(root);
    printf(" %d ",max->e);
    printf("\n");
    struct node* n = SearchBST(root,max->e);
    if(n!=NULL)
    {
        printf("Found : %d",n->e);
    }
    else
    {
        printf("Element not found");
    }
    printf("\n");
    root=deletion(root,15);
    Inorder(root);
    printf("\n");
    root=deletion(root,18);
    Inorder(root);
    printf("\n");
    return 0;

}
