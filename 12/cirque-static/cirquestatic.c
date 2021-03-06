//CIRCULAR QUEUE STATIC PROGRAM !!!

#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = n;
    }
    else if(((rear + 1)% N)== front)
    {
        printf("queue full\n");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=n;
    }
}

void dequeue()
{
    if(front==-1 && rear ==-1)
    {
        printf("queue is empty\n");
    }
    else if(front == rear)
    {
        printf("deleted %d\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("deleted %d\n",queue[front]);
        front=(front+1)%N;
    }
}

void display()
{
    int i= front;
    if(front==-1 && rear ==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue is:\n");
        while(i!=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n",queue[rear]);
    }
}

void main()
{
    int ch;
    for(;;)
    {
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:Display\n");
        printf("4:Exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:  enqueue(); display();  break;
        case 2: dequeue(); display(); break;
        case 3: display();  break;
        case 4:exit(0); 
        }
    }
    
}