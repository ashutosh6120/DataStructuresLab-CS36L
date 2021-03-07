//DATA QUEUE !!!

#include<stdio.h>
#include<stdlib.h>

#define MAX 7
struct QUEUE
{
    int items[MAX];
    int f,r;
};
typedef struct QUEUE queue;

queue enqueue(int n, queue Q)
{
    if(Q.r==MAX-1)
    {
        printf("queue full\n");
    }
    else
    {
        Q.items[++Q.r] = n;
    }
    return Q;
}

void displayQueue(queue Q)
{
    int i;
    if(Q.f > Q.r)
    {
        printf("empty\n");
    }
    else
    {
        for(i=Q.f; i<=Q.r; i++)
        {
            printf("%d\n",Q.items[i]);
        }
    }
}

void displaydata(queue Q[])
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("grp %d:",(i+1));
        displayQueue(Q[i]);
    }
}

int main()
{
    int ch,data;
    queue Q[4];
    for(int i=0; i<4; i++)
    {
        Q[i].f=0;
        Q[i].r=-1;
    }
    for(;;)
    {
        printf("1:Enter number\n2:Display data grp\n3:Exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter number:");
                    scanf("%d",&data);
                    if(data<10)
                        Q[0]=enqueue(data,Q[0]);
                    else if(data < 19)
                        Q[1]=enqueue(data,Q[1]);
                    else if(data < 29)
                        Q[2]=enqueue(data,Q[2]);
                    else
                        Q[3]=enqueue(data,Q[3]);
                    break;
            case 2: displaydata(Q); break;
            case 3: exit(0);
        }
    }
    return 0;
}