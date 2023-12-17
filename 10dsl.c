#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int top = -1;

struct node
{
    int data;
    struct node* next;
};

struct graph
{
    int n;
    int *visited;
    struct node **list;
}g1;

void create_graph(int n)
{
    struct graph *g1 = (struct graph*)malloc(sizeof(struct graph));
    g1->n = n;
    g1->list = malloc(n * sizeof(struct node*));

    int i;
    for (i = 0; i < n; i++)
    {
        g1->list[i] = NULL;
    }
}

void add(struct graph *g1, int n)
{
    int i, m;
    for(i=0; i<n; i++)
    {
        printf("enter the value number %d in the graph - ", i+1);
        scanf("%d", &m);
        g1->list[i] = m;
    }
}

void add_edge(struct graph *g1)
{
    
}


int stack[100];

void push(int n)
{
    top = top+1;
    stack[top] = n;
}
void pop()
{
    top = top-1;
}

void dfs(struct graph *g1, int n)
{
    struct graph *ptr;
    ptr = g1;
    ptr->visited[i] = 
}