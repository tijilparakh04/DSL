#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void add_item(struct node **root)
{
    int x;
    printf("\nenter the data - ");
    scanf("%d", &x);
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    struct node *ptr = *root, *q;
    q = NULL;
    while(ptr!=NULL)
    {
        q = ptr;
        if(x<ptr->data)
        {
            ptr = ptr->left;
        }
        else if(x>ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            printf("duplicate value entered.");
            return;
        }
    }
    if(x<q->data)
    {
        q->left = p;
    }
    else if(x>q->data)
    {
        q->right = p;
    }
}
/*void remove(struct node *root)
{
    struct node *ptr, *q;
    ptr = root;
    q = NULL;
    int x;
    printf("which node do you want to remove?\n");
    scanf("%d", x);
    while(ptr->data!=x)
    {
        q=ptr;
        if(x<ptr->data)
        {
            ptr = ptr->left;
        }
        else if(x>ptr->data)
        {
            ptr = ptr->right;
        }
        if(ptr==NULL)
        {
            printf("wrong input.");
            return;
        }
    }
    if (ptr->left == NULL && ptr->right == NULL)
    {
        free(ptr);
        if(x<q->data)
        {
            q->left = NULL;
        }
        else
        {
            q->right = NULL;
        }
    }
    else if (ptr->left == NULL && ptr->right != NULL)
    {
        if(x<q->data)
        {
            q->left = ptr->right;
        }
        else
        {
            q->right = ptr->right;
        }
        free(ptr);
    }
    else if (ptr->left != NULL && ptr->right == NULL)
    {
        if(x<q->data)
        {
            q->left = ptr->left;
        }
        else
        {
            q->right = ptr->left;
        }
        free(ptr);
    }
    //fix else statement
    else
    {
        if(x<q->data)
        {
            q->left = ptr->left;
        }
        else
        {
            q->right = ptr->left;
        }
    }
    
}
*/
void pre_order(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
    
}
void in_order(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}
void post_order(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}
void my_order(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    my_order(root->right);
    printf("%d ", root->data);
    my_order(root->left);
}
main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("enter root data - ");
    scanf("%d", &x);
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    int z;
    int d = 0;
    while(d<1)
    {
        printf("\nENTER 1 TO ADD AN ELEMENT TO TREE\n2 FOR PRE ORDER TRAVERSAL\n3 FOR IN ORDER TRAVERSAL\n4 FOR POST ORDER TRAVERSAL\n5 TO EXIT\n");
        scanf("%d", &z);
        printf("\n");
        switch(z)
        {
            case 1:
            add_item(&root);
            break;
            case 2:
            pre_order(root);
            break;
            case 3:
            in_order(root);
            break;
            case 4:
            post_order(root);
            break;
            case 5:
            my_order(root);
            break;
            case 6:
            d=2;
            break;
            default:
            printf("WRONG INPUT, ENTER AGAIN.");
            break;
        }
    }
}