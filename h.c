void remove(struct node *root)
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
            break;
        }
    }
    free(ptr);
    q->left = NULL;
    q->right = NULL;
}