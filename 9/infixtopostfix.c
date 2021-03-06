//INFIX TO POSTFIX PROGRAM

#include<stdio.h>
#include<string.h>

struct stk
{
	char item[50];
	int top;
};
typedef struct stk STK;

void push(char c, STK *s)  //INSERTING FUNCTION
{
     if(s->top==49)
        printf("stack is full cannot push any element\n");
     else
	s->top++;
	s->item[s->top] = c;
}

char pop(STK *s)  // DELETING FUNCTION
{
     char c;
     if(s->top== -1)
        printf("stack is empty cannot pop any element\n");
     else
        c=s->item[s->top];
	s->top--;
     return c;
}


int operand(char c)  // OPERANDS
{
    switch(c)
    {
        case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '$':
	case '^': return 0;
	default: return 1;
    }
}

int Sprec(char c)   //STACK PRECEDENCE CHECKING
{
    switch(c)
    {
        case '+':
	case '-': return 2;
	case '*':
	case '/': return 4;
	case '$':
	case '^': return 7;
	case '(': return 0;
    }
}

int Iprec(char c)   //INFIX  PRECEDENCE CHECKING
{
    switch(c)
    {
        case '+':
	case '-': return 1;
	case '*':
	case '/': return 3;
	case '$':
	case '^': return 8;
	case '(': return 9;
	case ')': return 0;
    }
}


void inpost(char in[], char po[])
{
     STK s;
     char c;
     int i=0, j=0;
     s.top= -1;
     while((c = in[i++])!='\0')  //SCANNING INFIX EXPRESSION
     {
	if(operand(c)) //	IF THIS TRUE ADD TO POSTFIX STRING
	    po[j++]=c;
	else
	{
            while(s.top!=-1 && Sprec(s.item[s.top]) > Iprec(c))
	    {
		if(c==')')   // CHECKING FOR PARENTHESES
		{
		     while(s.item[s.top]!='(')
		     po[j++]=pop(&s);
		     pop(&s);
		     break; 	// ONCE WE ARRIVE AT THE PARENTHESE BREAKING OUT
		}
		else
		    po[j++]=pop(&s);
	    } //INNER WHILE LOOP ENDS

	    if(c!=')')
		push(c, &s);
	}	// ELSE LOOP BRACKET

      } //OUTER WHILE LOOP BRACKET

      while(s.top!=-1)
	po[j++]=pop(&s);
	po[j]='\0';     //INFIX TO POSTFIX PROGRAM END
}


void main()
{
     char in[50], po[50];
     for(;;)
     {
	printf("enter exp and 10 to stop execution\n");
        scanf("%s",in);
	if(strcmp(in,"10")==0)
	   break;
        inpost(in,po);
	printf("%s\n",po);
     }
}
