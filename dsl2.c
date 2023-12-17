#include<stdio.h>
void swap(int *p, int *q)
{
    int w;
    w = *p;
    *p = *q;
    *q = w;
}
void bubble(int a[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}
main()
{
    int n, i;
    printf("enter number of elements in array - ");
    scanf("%d", &n);
    int a[n];
    printf("enter elements in array - ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble(a, n);
    printf("the sorted array is - ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}