// PRIORITY QUEUE OF JOBS !!!

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct JOBS{
    int job_id;
    char job_name[15];
    int priority;
};
typedef struct JOBS jobs;

struct Queue{
    jobs items[MAX];
    int f,r;
};
typedef struct Queue queue;

queue enqueue(queue Q)
{
    if(Q.r==MAX-1)
    {
        printf("queue full\n");
    }
    else
    {
        jobs J;
        printf("enter job id, name, priority:");
        scanf("%d%s%d",&J.job_id,&J.job_name,&J.priority);
        Q.items[++Q.r] = J;
    }
    return Q;
}

queue dequeue(queue Q)
{
    if(Q.f>Q.r)
    {
        printf("Queue empty\n");
    }
    else
    {
        int minI=0,i;
        jobs min=Q.items[0];
        for(i=Q.f;i<=Q.r;i++){
            if(Q.items[i].priority<min.priority){
                min=Q.items[i];
                minI=i;
            }
        }
        for(i=minI;i<Q.r;i++){
            Q.items[i]=Q.items[i+1];
        }
        Q.r--;
        printf("Dequeued\tjob_id: %d\tjob_name: %s\tpriority: %d\t",min.job_id,min.job_name,min.priority);
    }
    return Q;
}

void display(queue Q)
{
    int i;
    if(Q.f > Q.r)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("\n---------------------------\n");
        printf("id\t Name\t Priority\n");
        printf("\n---------------------------\n");
        for(i=Q.f; i<=Q.r; i++)
        {
            printf("%d\t%s\t%d\n",Q.items[i].job_id, Q.items[i].job_name, Q.items[i].priority);
        }
        printf("\n");
    }
}


void main()
{
    int ch;
    queue Q;
    Q.f=0;
    Q.r=-1;
    for(;;)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: Q=enqueue(Q); display(Q); break;
            case 2: Q=dequeue(Q); display(Q); break;
            case 3: display(Q); break;
            case 4: exit(0);
        }
    }

}