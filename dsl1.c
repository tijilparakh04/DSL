#include<stdio.h>
main()
{
    int i, arr[10];
    for(i=0; i<10; i++)
    {
        printf("Enter number %d - ", i+1);
        scanf("%d", &arr[i]);
    }
    for(i=0; i<10; i++)
    {
        printf("%d\n", arr[i]);
    }   
}