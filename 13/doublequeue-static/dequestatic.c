// DOUBLE ENDED QUEUE or DEQUE WITH STATIC

#include<stdio.h>
#include<stdlib.h>

#define N 5
int deque[N];
int f=-1, r=-1;

void enqueuefront() //INSERT FRONT
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if((f==0 && r==N-1) || (f==r+1) )
    {
        printf("queue is full\n");
    }
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[f] = n;
    }
    else if(f==0)
    {
        f=N-1;
        deque[f] = n;
    }
    else
    {
        f--;
        deque[f] = n;
    }
}

void enqueuerear()
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if((f==0 && r==N-1) || (f==r+1) )
    {
        printf("queue is full\n");
    }
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[r] = n;
    }
    else if(r==N-1)
    {
        r=0;
        deque[r] = n;
    }
    else
    {
        r++;
        deque[r] = n;
    }   
}

void display()
{
    int i = f;
    if(f==-1 && r==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        while(i!=r)
        {
            printf("%d\n",deque[i]);
            i = (i+1) % N;
        }
        printf("%d\n",deque[r]);
    }
}

void dequeuefront()
{
    if(f==-1 && r==-1)
    {
        printf("empty queue\n");
    }    
    else if(f==r) //only one element
    {
        printf("deleted %d\n",deque[f]); // can use deque[r];
        f=r=-1;
    }
    else if(f==N-1)
    {
        printf("deleted %d\n",deque[f]);
        f = 0;
    }
    else
    {
        printf("deleted %d\n",deque[f]);
        f++;
    }
}

void dequeuerear()
{
    if(f==-1 && r==-1)
    {
        printf("empty queue\n");
    }    
    else if(f==r) //only one element
    {
        printf("deleted %d\n",deque[r]); // can use deque[r];
        f=r=-1;
    }
    else if(r == 0)
    {
        printf("deleted %d\n",deque[r]);
        r=N-1;
    }
    else
    {
        printf("deleted %d\n",deque[r]);
        r--;
    }
}

void main()
{
    int ch;
    for(;;)
    {
        printf("1:Insert Front\n");
        printf("2:Insert Rear\n");
        printf("3:Delete Front\n"); 
        printf("4:Delete Rear\n"); 
        printf("5:Display\n");
        printf("6:Exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:  enqueuefront(); display();  break;
        case 2:  enqueuerear(); display();  break;
        case 3:  dequeuefront(); display();  break;
        case 4:  dequeuerear(); display();  break;
        case 5: display();  break;
        case 6:exit(0); 
        }
    }
}