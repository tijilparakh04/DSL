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
    struct node *p;
    p= (struct node *)malloc(sizeof(struct node*));
    int x;
    printf("Enter data value - ");
    scanf("%d", &x);
    p->data = x;
    p->next = *head;
    *head = p;
}
void add_last(struct node *head)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node*));
    struct node *ptr;
    int x;
    ptr = head;
    printf("Enter data value - ");
    scanf("%d", &x);
    while(ptr->next !=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->data = x;
    p->next = NULL;
}
void del_begin(struct node **head)
{
    struct node *p;
    p = *head;
    *head = p->next;
    free(p);
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
void add_mid(struct node *head,int n)
{
    struct node *ptr, *q;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node *));
    int i;
    ptr = head;
    for(i=0; i<n; i++)
    {
        q = ptr;
        ptr = ptr->next;
    }
    int x;
    printf("enter the data - ");
    scanf("%d", &x);
    q->next = p;
    p->data = x;
    p ->next = ptr;
}
void del_mid(struct node *head,int n)
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
void unique(struct node *head)
{
    struct node *p, *q, *r;
    p = head;
    struct node *temp;
    while(p != NULL)
    {
        q = p->next;
        r = p;
        while(q != NULL)
        {
            if (q->data == p->data)
            {
                r->next = q->next;
                temp = q;
                q = q->next;
                free(temp);
            }
            else
            {
                r = r->next;
                q = q->next;
            }
        }
        p = p->next;
    }
}

void intersection (struct node *head, struct node *head2)
{
    unique(head);
    unique(head2);
    struct node *p, *q;
    p = head;
    while(p!=NULL)
    {
        q = head2;
        while(q!=NULL)
        {
            if(q->data == p->data)
            {
                printf("%d ", p->data);
                break;

            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
    }
}

void unionn(struct node *head, struct node *head2)
{
    concatenate(head, head2);
    unique(head);
    display(head);
}
main()
{
    head = (struct node*)malloc(sizeof(struct node *));
    head->data = 5;
    head->next = NULL;
    head2 = (struct node*)malloc(sizeof(struct node *));
    head2->data = 5;
    head2->next = NULL;
    
    int m, n=0, b=0;
    int choice;
    while(b<1)
    {
        printf("enter linked list number - ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            n=0;
            while (n<1)
            {
                printf("enter number - ");
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
                    display(head);
                    break;
                    case 8:
                    unique(head);
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
                printf("enter number - ");
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
                    display(head2);
                    break;
                    case 8:
                    unique(head2);
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
            unionn(head, head2);
            break;
            case 5:
            intersection(head, head2);
            break;
            case 6:
            b=2;
            break;
            default:
            printf("wrong.");
            break;
        }
    }
}

