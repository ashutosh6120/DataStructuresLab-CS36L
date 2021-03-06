//EVALUATING POSTFIX EXPRESSION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdlib.h>

void Evaluate(char c[]);
float Compute (float,float,char);
struct stk
{
    float item [40];
    int top;
};
typedef struct stk STK;

void push(float c, STK *s)
{
    if(s->top==39)
        printf("Stack is full\n");
    else
        s->top++;
        s->item[s->top]=c;
}

float pop(STK *s)
{
    float c;
    if(s->top==-1)
        printf("stack is empty\n");
    else
        c=s->item[s->top];
        s->top--;
        return c;
}

int isoperand(char c)
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

void Evaluate(char po[])
{
    STK s;
    char c;
    float op1, op2, res;
    int i=0;
    s.top=-1;
    while((c=po[i++])!='\0')
    {
        if(isoperand(c))
            push(c-'0',&s);
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            res = Compute(op1,op2,c);
            push(res,&s);
        }
    }
    res=pop(&s);
    if(s.top!=-1)
        printf("Invalid Expression\n");
    else
        printf("value of expression is: %f\n", res);
}

float Compute(float op1,float op2, char opr)
{
    switch(opr)
    {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '^': return pow(op1,op2);
        case '$': return pow(op1,op2);
        default: printf("Invalid Expression\n");
    }
}

void main()
{
    char pos[50];
    for(;;)
    {
        printf("enter expression or 0 to stop the execution:\n");
        scanf("%s",pos);
        if(strcmp(pos,"0")==0)
            break;
        Evaluate(pos);
    }
}