#include<stdio.h>
int main()
{
    int a[10] ,i,n;
    int *p1;
    p1=a;
    printf("Enter the no of elements=\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",p1+i);
    }
    printf("\n");
    printf("the elements in array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(p1+i));
    }
    printf("The elements in reverse order are:\n");
    for(i=n-1; i>=0;i--)
    {
        printf("%d ", *(p1+i));
        printf("\n");
    }
    return 0;

}
