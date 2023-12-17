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
int binary (int a[], int p, int n, int k)
{
    int low=p, high=n;
    int mid = n+1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==k)
        {
            return mid;
        }
        else if(a[mid]>k)
        {
            return binary (a, p, mid-1, k);
        }
        else if(a[mid]<k)
        {
            return binary (a, mid+1, n, k);
        }
    }
    if(mid == n+1)
    {
        return mid;
    }
}
main()
{
    int n, i, k;
    printf("enter number of elements - ");
    scanf("%d", &n);
    int a[n];
    printf("enter elements in array - ");
    for(i=0; i<n; i++)
    {   
        scanf("%d", &a[i]);
    }
    bubble(a, n);
    printf("enter element to be searched for - ");
    scanf("%d", &k);
    int c = binary(a, 0, n, k);
    if (c==n+1)
    {
        printf("the element was not found.");
    }
    else
    {
        printf("the element is found at position %d in ascending order", c+1);
    }
}