#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void add_begin()
{
    struct node *ptr ;
    ptr = (struct node*)malloc(sizeof(struct node));
    int z;
    printf("enter the data - ");
    scanf("%d", &z);
    ptr->data = z;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;
}
void add_last()
{
    struct node *ptr ;
    ptr= (struct node *)malloc(sizeof(struct node));
    int z;
    printf("enter the data - ");
    scanf("%d", &z);
    struct node *p;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->data = z;
    ptr->next = NULL;
}
void add_mid(int n)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p, *q;
    int z;
    printf("enter the data - ");
    scanf("%d", &z);
    p = head;

    for(int i=0; i<n; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = ptr;
    ptr->next = p;
    ptr->data = z;
    ptr->prev = q;
    p->prev = ptr;
}
void del_begin()
{
    struct node *p;
    p = head;
    head = p->next;
    head->prev = NULL;
    free(p);
}
void del_last()
{
    struct node *p, *q;
    p = head;
    while(p->next != NULL)
    {
        q=p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}
void del_mid(int n)
{
    struct node *p, *q, *r;
    p = head;
    for(int i=0; i<n; i++)
    {
        q=p;
        p = p->next;
    }
    q->next = p->next;
    r = p->next;
    r->prev = q;
    free(p);
}
void display()
{
    struct node *p;
    p = head;
    while(p->next != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("%d", p->data);
    printf("\n");
}
main()
{
    head = (struct node *)malloc(sizeof(struct node *));
    head->data = 5;
    head->next = NULL;
    head->prev = NULL;
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
            del_last();
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
