#include<stdio.h>
int identical(int *p,int n1, int *q, int n2);
void main()
{
    int a[10], b[10],*p1,*p2,n1,n2,i;
    p1=a;
    p2=b;
    printf("enter the no of elements of first array\n");
    scanf("%d",&n1);
    printf("enter the elements of first array\n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",p1+i);
    }
    printf("enter the no of elements of second array\n");
    scanf("%d",&n2);
    printf("enter the elements of second array\n");
    for(i=0;i<n2;i++)
    {
        scanf("%d",p2+i);
    }
    identical(p1,n1,p2,n2);
}
int identical(int *p,int n1,int *q, int n2)
{
    int i=0;
    if(n1!=n2)
    {
        printf("0 is returned\n");
        return 0;
    }
    else
    {
        if(n1==n2)
        {
            for(i=0;i<n1;i++)
            if(*(p+i)==*(q+i))
            {
                printf("1 is returned\n");
                return 1;
            }
            else
            {
                printf("0 is returned\n");
                return 0;
            }
        }

    }
}
