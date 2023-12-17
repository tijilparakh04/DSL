#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void add_begin()
{
    struct node *p, *ptr;
    p= (struct node *)malloc(sizeof(struct node*));
    int x;
    printf("Enter data value - ");
    scanf("%d", &x);
    ptr = head;
    while(ptr->next !=head)
    {
        ptr = ptr->next;
    }
    p->data = x;
    p->next = head;
    ptr->next = p;
    head = p;
}
void add_last()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node*));
    struct node *ptr;
    int x;
    ptr = head;
    printf("Enter data value - ");
    scanf("%d", &x);
    while(ptr->next !=head)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->data = x;
    p->next = head;
}
void del_begin()
{
    struct node *p, *ptr;
    ptr =head;
    while(ptr->next !=head)
    {
        ptr = ptr->next;
    }
    p = head;
    head = p->next;
    ptr->next =head;
    free(p);
}
void del_end()
{
    struct node *p, *ptr;
    ptr = head;
    while (ptr->next!= head)
    {
        p = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    p->next = head;
}
void add_mid(int n)
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
void del_mid(int n)
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
void display()
{
    struct node *p;
    p = head;
    while(p->next != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    printf("\n");
}
main()
{
    head = (struct node*)malloc(sizeof(struct node *));
    head->data = 5;
    head->next = head;
    int m, n=0;
    while (n<1)
    {
        printf("enter number - ");
        scanf("%d", &m);
        switch(m)
        {
            case 1:
            add_begin();
            break;
            case 2:
            add_last();
            break;
            case 3:
            int z;
            printf("enter position - ");
            scanf("%d", &z);
            add_mid(z);
            break;
            case 4:
            del_begin();
            break;
            case 5:
            del_end();
            break;
            case 6:
            int k;
            printf("enter position - ");
            scanf("%d", &k);
            del_mid(k);
            break;
            case 7:
            display();
            break;
            case 8:
            n=2;
            break;
            default:
            printf("wrong input. enter again");
        }
    }
}