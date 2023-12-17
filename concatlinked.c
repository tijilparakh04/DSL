#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *head2;

void add_begin(struct node **head)
{
    struct node *ptr;
    ptr= (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter the number - ");
    scanf("%d", &x);
    ptr->data = x;
    ptr->next = *head;
    *head = ptr;
}
void add_last(struct node *head)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *ptr2;
    int x;
    ptr2 = head;
    printf("Enter the number - ");
    scanf("%d", &x);
    while(ptr2->next !=NULL)
    {
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr;
    ptr->data = x;
    ptr->next = NULL;
}
void del_begin(struct node **head)
{
    struct node *ptr;
    ptr = *head;
    *head = ptr->next;
    free(ptr);
}
void del_end(struct node *head)
{
    struct node *p, *ptr;
    ptr = head;
    while (ptr->next!= NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    
}
void add_mid(struct node *head, int n)
{
    struct node *ptr, *q;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    int i;
    ptr = head;
    for(i=0; i<n; i++)
    {
        q = ptr;
        ptr = ptr->next;
    }
    int x;
    printf("Enter the number - ");
    scanf("%d", &x);
    q->next = p;
    p->data = x;
    p ->next = ptr;
}
void del_mid(struct node *head, int n)
{
    struct node *p, *q;
    p = head;
    int i;
    for(i=0; i<n; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}
void display(struct node *head)
{
    struct node *p;
    p = head;
    while(p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    printf("\n");
}
void concatenate(struct node *head, struct node *head2)
{
    struct node *ptr;
    ptr = head;
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;
}
void reverse(struct node **head) {
    struct node *p, *q, *r;
    p = *head;
    q = NULL;

    while(p !=  NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    *head = q;
}
main()
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    head2 = (struct node*)malloc(sizeof(struct node));
    head2->data = 1;
    head2->next = NULL;
    
    int m, n=0, b=0;
    int choice;
    while(b<1)
    {
        printf("1. Create or edit 1st linked list.\n2. Create or edit 2nd linked list.\n3. Concatenate and display.\n4. Exit.\n\nEnter what you want to do - ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            n=0;
            while (n<1)
            {
                printf("\n\nYou are now making changes to linked list 1.\n\n1.Add at beginning\n2.Add at end\n3.Add in middle\n4.Delete from beginning\n5.Delete from end\n6.Delete from middle\n7.Reverse\n8.Display\n9.Exit to main menu.\n\n");
                printf("Enter your choice - ");
                scanf("%d", &m);
                switch(m)
                {
                    case 1:
                    add_begin(&head);
                    break;
                    case 2:
                    add_last(head);
                    break;
                    case 3:
                    int z;
                    printf("enter position - ");
                    scanf("%d", &z);
                    add_mid(head, z);
                    break;
                    case 4:
                    del_begin(&head);
                    break;
                    case 5:
                    del_end(head);
                    break;
                    case 6:
                    int k;
                    printf("enter position - ");
                    scanf("%d", &k);
                    del_mid(head,k);
                    break;
                    case 7:
                    reverse(&head);
                    break;
                    case 8:
                    display(head);
                    break;
                    case 9:
                    n=2;
                    break;
                    default:
                    printf("wrong input. enter again");
                    
                }
            }
            break;
            case 2:
            n=0;
            while (n<1)
            {
                printf("\n\nYou are now making changes to linked list 2.\n\n1.Add at beginning\n2.Add at end\n3.Add in middle\n4.Delete from beginning\n5.Delete from end\n6.Delete from middle\n7.Reverse\n8.Display\n9.Exit to main menu.\n\n");
                printf("Enter your choice - ");
                scanf("%d", &m);
                switch(m)
                {
                    case 1:
                    add_begin(&head2);
                    break;
                    case 2:
                    add_last(head2);
                    break;
                    case 3:
                    int z;
                    printf("enter position - ");
                    scanf("%d", &z);
                    add_mid(head2, z);
                    break;
                    case 4:
                    del_begin(&head2);
                    break;
                    case 5:
                    del_end(head2);
                    break;
                    case 6:
                    int k;
                    printf("enter position - ");
                    scanf("%d", &k);
                    del_mid(head2,k);
                    break;
                    case 7:
                    reverse(&head2);
                    break;
                    case 8:
                    display(head2);
                    break;
                    case 9:
                    n=2;
                    break;
                    default:
                    printf("wrong input. enter again");
                    
                }
            }
            break;
            case 3:
            concatenate (head, head2);
            display(head);
            break;
            case 4:
            b=2;
            break;
            default:
            printf("wrong input. enter again.");
            break;
        }
    }
}

