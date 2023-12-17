#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};  

stack<struct node *> in;
stack<struct node *> pre;
stack<struct node *> post;

void add_node(struct node **root)
{
    int x;
    cout<<"enter the data - ";
    cin>>x;
    if(*root == NULL )
    {
        *root = (struct node *)malloc(sizeof(struct node ));
        struct node *l;
        l = *root;
        l->data = x;
        l->left = NULL;
        l->right = NULL;
        cout<<"Root node successfully added."<<endl;
        return;
    }
    struct node *p, *q;
    p = *root;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node ));
    ptr->data = x;
    while(p!=NULL)
    {
        q=p;
        if(x<p->data)
        {
            p=p->left;
        }
        else if(x>p->data)
        {
            p=p->right;
        }
        else
        {
            cout<<"Duplicate value entered."<<endl;
            return;
        }
    }
    if(x<q->data)
    {
        q->left = ptr;
    }
    else
    {
        q->right = ptr;
    }
    ptr->left = NULL;
    ptr->right = NULL;
    cout<<"Node successfully added."<<endl;
}

void add_ulta(struct node **root, int x)
{
    if(*root == NULL )
    {
        *root = (struct node *)malloc(sizeof(struct node ));
        struct node *l;
        l = *root;
        l->data = x;
        l->left = NULL;
        l->right = NULL;
        return;
    }
    struct node *p, *q;
    p = *root;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node ));
    ptr->data = x;
    while(p!=NULL)
    {
        q=p;
        if(x<p->data)
        {
            p=p->right;
        }
        else if(x>p->data)
        {
            p=p->left;
        }
        else
        {
            cout<<"Duplicate value entered."<<endl;
            return;
        }
    }
    if(x<q->data)
    {
        q->right = ptr;
    }
    else
    {
        q->left = ptr;
    }
    ptr->left = NULL;
    ptr->right = NULL;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void myorder(struct node *root)
{
    if(root!=NULL)
    {
        myorder(root->right);
        cout<<root->data<<" ";
        myorder(root->left);
    }
}

void inorder_iterative(struct node *root)
{
    struct node *p;
    p=root;
    while(true)
    {
        while(p!=NULL)
        {
            in.push(p);
            p = p->left;
        }
        if(in.empty())
        {
            break;
        }
        p = in.top();
        cout<< p->data<<" ";
        in.pop();
        p=p->right;
    }
}

void preorder_iterative(struct node *root)
{
    struct node *p, *pr;
    pr= root;
    pre.push(pr);
    while(!pre.empty())
    {
        p = pre.top();
        cout<<p->data<<" ";
        pre.pop();
        if(p->right!=NULL)
        {
            pre.push(p->right);
        }
        if(p->left!=NULL)
        {
            pre.push(p->left);
        }   
    }
}

void postorder_iterative(struct node *root)
{
    struct node *p;
    p=root;
    struct node *q;
    do
    {
        if(p!=root)
            p = post.top();

        while(p!=NULL)
        {
            post.push(p);
            p = p->left;
            cout<<" v";
        }

        if(p!=post.top())
        {   
            p = post.top();
            cout<<p->data<<" ";
            q=p;
            post.pop();
        }
        p = post.top();
        if(p->right!=q)
        {
            p = p->right;
        }
        else
        {
            cout<<p->data<<" ";
            q=p;
            post.pop();
            // if(!post.empty())
            // {
                
            // }
        }
        
    }while(!post.empty());
}

void remove(struct node *root, int x)
{
    struct node *p, *q;
    p=root;
    while(p->data != x)
    {
        q=p;
        if(x<p->data)
        {
            p=p->left;
        }
        else if(x>p->data)
        {
            p=p->right;
        }
    }
    if(p->left==NULL && p->right == NULL)
    {
        if(x>q->data)
        {
            q->right = NULL;
        }
        else if(x<q->data)
        {
            q->left = NULL;
        }
        free(p);
        return;
    }
    else if(p->left == NULL && p->right !=NULL)
    {
        if(x>q->data)
        {
            q->right = p->right;
        }
        if(x<q->data)
        {
            q->left = p->right;
        }
        free(p);
        return;
    }
    else if(p->left != NULL && p->right ==NULL)
    {
        if(x>q->data)
        {
            q->right = p->left;
        }
        if(x<q->data)
        {
            q->left = p->left;
        }
        free(p);
        return;
    }
    else 
    {
        struct node *a = p;
        struct node *b = p->right;
        while(b->left !=NULL)
        {
            a=b;
            b=b->left;
        }
        if(a!=root)
        {
            a->left = b->right;
        }
        else
        {
            a->right = b->right;
        }
        p->data = b->data;
        free(b);
        return;
    }
}

int c=0;

void count_leaf(struct node *root)
{   
    if(root!=NULL)
    {
        if(root->left == NULL && root->right == NULL)
        {
            c++;
        }
        count_leaf(root->left);
        count_leaf(root->right);
    }
}

void mirror(struct node *root, struct node **root2)
{
    if(root!=NULL)
    {
        add_ulta(root2, root->data);
        mirror(root->left, root2);
        mirror(root->right, root2);
    }
}

void search(struct node *root, int n)
{
    if(root!=NULL)
    {
        if(n==root->data)
        {
            cout<<"Data found";
        }
        search(root->left, n);
        search(root->right, n);
    }
}
main()
{
    struct node *root2 = NULL;
    struct node *root = NULL;
    int z;
    int d = 0;
    while(d<1)
    {
        printf("\nENTER -\n1 TO ADD AN ELEMENT TO TREE\n2 FOR PRE ORDER TRAVERSAL\n3 FOR IN ORDER TRAVERSAL\n4 FOR POST ORDER TRAVERSAL\n5 FOR DESCENDING ORDER\n6 FOR INORDER ITERATIVE\n7 FOR REMOVAL\n8 FOR LEAF COUNT\n9 TO CREATE MIRRORED BST\n10 FOR PREORDER ITERATIVE\n11 FOR POSTORDER ITERATIVE\n12 TO EXIT\n\n");
        scanf("%d", &z);
        printf("\n");
        switch(z)
        {
            case 1:
            add_node(&root);
            break;
            case 2:
            preorder_iterative(root);
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            myorder(root);
            break;
            case 6:
            inorder_iterative(root);
            break;
            case 7:
            int y;
            cout<<"enter the node to be removed - ";
            cin>>y;
            remove(root, y);
            break;
            case 8:
            c=0;
            count_leaf(root);
            cout<<"Number of leaf nodes - "<<c<<endl;
            break;
            case 9:
            mirror(root, &root2);
            cout<<"The original bst had preorder traversal as - ";
            preorder(root);
            cout<<"\nThe mirrored bst has preorder traversal as - ";
            preorder(root2);
            break;
            case 10:
            preorder_iterative(root);
            break;
            case 11:
            postorder_iterative(root);
            break;
            case 12:
            d=2;
            break;
            default:
            printf("WRONG INPUT, ENTER AGAIN.");
            break;
        }
    }
}