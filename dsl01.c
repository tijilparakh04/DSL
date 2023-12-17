#include<stdio.h>
main()
{
    int n, i, z, k, m;
    printf("Enter the number of elements in array - ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array - \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be searched for in the array - ");
    scanf("%d", &z);
    for(i=0; i<n; i++)
    {
        if(arr[i]==z)
        {
            k=1;
            printf("%d is found at position %d in the array\n", z, i+1);
        }
    }
    if(k!=1)
    {
        printf("Element is not found");
    }
}