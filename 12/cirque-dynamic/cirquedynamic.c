//CIRCULAR QUEUE USING LINKED LIST !!!
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front =0, *rear=0;
//struct node *front=0;
//struct node *rear=0;

void enqueue()
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = 0;
    if(rear == 0)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf("Underflow\n");
    }
    else if(front == rear) //Checking if only one element then queue will be empty
    {
        front = rear = 0;
        free(temp);
    }
    else //more than element in list
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");
        while(temp->next!=front)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
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