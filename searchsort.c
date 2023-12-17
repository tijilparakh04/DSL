#include <stdio.h>

void swap(int *p, int*q)
{
    int t;
    t = *p;
    *p=*q;
    *q=t;
}

void bubble(int a[], int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void selection(int a[], int n)
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]< a[i])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            swap(&a[k], &a[i]);
        }
    }
}

void insertion(int a[], int n)
{
    int i, j, k;
    for(i=1; i<n; i++)
    {
        k=i;
        for(j=i-1; j>=0; j--)
        {
            if(a[j]>a[k])
            {
                swap(&a[j], &a[k]);
                k--;
            }
        }
    }
}

int partition(int a[],int lb, int ub)
{
    int pivot = a[ub];
    int i = (lb-1);
    int j;
    for(j=lb; j<ub; j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[ub]);
    return (i+1);
}

void quicksort(int a[], int lb, int ub)
{
    if(lb<ub)
    {
        int i;
        i = partition(a, lb, ub);
        quicksort(a, lb, i-1);
        quicksort(a, i+1, ub);
    }
}

void merge(int a[], int lb, int mid, int ub)
{
    int n1,n2;
    n1 = mid-lb+1;
    n2 = ub - mid;
    int a1[n1];
    int a2[n2];
    int i,j;
    for(i=0; i<n1; i++)
    {
        a1[i] = a[lb+i];

    }
    for(i=0; i<n2; i++)
    {
        a2[i] = a[mid+i+1];
    }
    i=0;
    j=0;
    int k=lb;
    while(i<n1&&j<n2)
    {
        if(a1[i]< a2[j])
        {
            a[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            a[k] = a2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k] = a1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        mergesort(a, lb, mid);
        mergesort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}

void linearsearch(int a[] , int n, int k)
{
    int i, j=0;
    for(i=0; i<n; i++)
    {
        if(a[i]==k)
        {
            j++;

        }
    }
    if(j==0)
    {
        printf("element not found");
    }
    else if(j==1)
    {
        printf("the number %d occurs in the array once at position -> ", k);
    }
    else
    {
        printf("the number %d occurs in the array %d times at positions -> ", k, j);
    }
    while(j!=0)
    {
        for(i=0; i<n; i++)
        {
            if(a[i]==k)
            {
                printf("%d, ", i+1);
                j--;
            }
        }
    }

}

void binarysearch(int a[], int n, int k )
{
    int low = 0;
    int high = n-1;
    int l = n+1;
    int mid = n+1;
    while(low<=high)
    {
        mid = ((low+high)/2);
        if(k<a[mid])
        {
            high = mid-1;
        }
        else if (k>a[mid])
        {
            low = mid+1;
        }
        else
        {
            l = mid;
            break;
        }
    }
    if(l==n+1)
    {
        printf("element not found");
    }
    else
    {
        printf("the number %d occurs in the array at position when sorted -> %d", k, l+1);
    }
}

void binaryrecursive(int a[], int r, int u, int k)
{
    int low = r; 
    int high = u;
    int mid;
    if(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==k)
        {
            printf("the number %d occurs in the array at position when sorted -> %d", k, mid+1);
            return;
        }
        else if(k<a[mid])
        {
            binaryrecursive(a,r,mid-1,k);
        }
        else if(k>a[mid])
        {
            binaryrecursive(a,mid+1,u,k);
        }
    }
    else
    {
        printf("element not found");
    }
}

main()
{
    int n;
    printf("enter the number of elements in the array - ");
    scanf("%d", &n);
    int a[n], i;
    printf("enter elements in the array - \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a,0, n-1);
    printf("the sorted array is - ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    int k;
    printf("enter the number to be searched - ");
    scanf("%d", &k);
    binaryrecursive(a, 0,n, k);
}