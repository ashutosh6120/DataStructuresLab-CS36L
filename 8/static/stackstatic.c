//STACK IMPLEMENTATION USING STATIC

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size=15;
struct stack
{
	int items [15];
	int top;
};
typedef struct stack STK;
void Push(STK*);
void Pop(STK*);
void Disp(STK*);

void main()
{
	STK S;
	int ch;
	S.top=-1;
	for(;;)
	{
		printf("enter choice\n1:Push\n2:Pop\n3:Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:Push(&S); Disp(&S); break;
			case 2:Pop(&S); Disp(&S); break;
			case 3:Disp(&S); break;
			default:exit(0);
		}
	}
}


void Push(STK *S)
{
	int item;
	if(S->top==size-1)
	{
		printf("stack full\n");
		return;
	}
	printf("enter the item:");
	scanf("%d",&item);
	++S->top;
	S->items[S->top]=item;
}


void Pop(STK *S)
{
	if(S->top==-1)
	{
		printf("stack empty\n");
		return;
	}
	printf("deleted %d\n",S->items[S->top]);
	S->top--;
}


void Disp(STK *S)
{
	int i;
	if(S->top==-1)
	{
		printf("stack empty\n");
		return;
	}
	printf("stack is:\n");
	for(i=S->top;i>=0;i--)
		printf("%d\n",S->items[i]);
}
