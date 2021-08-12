#include<stdio.h>
int main()
{
    int x, *p1, **p2, *p3, **p4;
    p1=&x;
    p2=&p1;
    p3=p1;
    p4=p2;
    printf("enter value:");
    scanf("%d",p1);
    printf("x=%d\n",*(p1));
    printf("x=%d\n",**(p2));
    printf("x=%d\n",*(p3));
    printf("x=%d\n",**(p4));

}
