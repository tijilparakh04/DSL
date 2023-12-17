#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void add_begin(struct node **head)
{
    struct node *p;
    p= (struct node *)malloc(sizeof(struct node));
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
    p = (struct node *)malloc(sizeof(struct node));
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
    p = (struct node *)malloc(sizeof(struct node));
    int i;
    ptr = head;
    for(i=0; i<n; i++)
    {
        q = ptr;
        ptr = ptr->next;
        if (ptr==NULL)
        {
            printf("wrong index");
            return;
        }
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
void reverse(struct node *head) {
    struct node *p, *q, *r;
    p = head;
    q = NULL;

    while(p !=  NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    head = q;
}
main()
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;
    
    int m, n=0;
    while (n<1)
    {
        printf("WELCOME.\n1.Add a number at the beginning of linked list.\n2.Add a number at the end of linked list.\n3.Add a number at a specific position of the linked list.\n4.Delete a number from the beginning of linked list.\n5.Delete a number from the end of linked list.\n6.Delete a number from a specific position in the linked list.\n7. Reverse the linked list.\n8.Display the linked list.\n\n");
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
            reverse(head);
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
}

void unique()
{
    struct node *p;
    p = head;
    int n=1;
    while(p->next != NULL)
    {
        p = p->next;
    }
    printf("%d", n);
}

