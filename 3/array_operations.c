#include<stdio.h>
#include<stdlib.h>
void read(int* );
void disp(int* );
void insert_pos(int* );
void delete_pos(int* );
void insert_by_ord(int*);
void delete_by_ele(int* );
int size=10, ne=0;
void main()
{
	int a[size],choice;
	for(;;)
	{
		printf("enter choice:\n 1:read\n 2:disp\n 3:insert_pos\n 4:delete_pos\n 5:insert_by_ord\n 6:delete_by_ele\n 7:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: read(a); break;
		case 2: disp(a); break;
		case 3: insert_pos(a); disp(a); break;
		case 4: delete_pos(a); disp(a); break;
		case 5: insert_by_ord(a); disp(a); break;
		case 6: delete_by_ele(a); disp(a); break;
		default:exit(0);
		}
	}
}


void read(int x[])
{
   int n,i;
   printf("eneter no of elements to read:");
   scanf("%d",&n);
   printf("enter elements");
   for(i=0;i<n;i++)
	scanf("%d",&x[i]);
   ne=n;
}


void disp(int x[])
{
   int i;
   if(ne==0)
      printf("empty");
      return;
   printf("array is:\n");
   for(i=0;i<ne;i++)
      printf("%d",x[i]);
}


void insert_pos(int x[])
{
int i,pos,ele;
if(ne==size)
printf("array full");
return;
printf("enter position");
scanf("%d",&pos);
printf("enter element");
scanf("%d",&ele);
if(pos>=1 && pos<=ne+1)
{
for(i=ne; i>=pos;i--)
x[i]=x[i-1];
x[i]=ele;
ne++;
}
else
printf("invalid position");
}


void delete_pos(int x[])
{
int i,pos;
if(ne==0) //check for empty
{
  printf("array is empty");
  return;
}
printf("eneter position of the element to be delete");
scanf("%d",&pos);
//check for valid position
if(pos>=1 && pos<=ne)
{
printf("delete:%d\n", x[pos-1]);
for(i=pos-1;i<ne-1;i++)
{
	x[i]=x[i+1];
}
ne--;
}
else
printf("invalid position");
}

void insert_by_ord(int x[])
{
int ele,i;
if(ne==size)
   printf("array full");
   return;
   printf("enter element");
   scanf("%d", &ele);
   i=ne-1;
   while(i>=0 && x[i]>ele)
   {
      x[i+1]=x[i];
      i--;
   }
   x[i+1]=ele;
   ne++;
}

void delete_by_ele(int x[])
{
    int ele,i;
    if(ne==0)
    {
       printf("array is empty");
       return;
    }
    printf("enter the element to be deleted");
    scanf("%d",&ele);
    for(i=0;i<ne && x[i]!=ele; i++);
    if(i==ne)
    {
       printf("element not found in the list\n");
       return;
    }
    printf("%d is deleted from position %d\n", x[i],i+1);
    for(;i<ne-1 ;i++);
    {
       x[i]=x[i+1];
    }
    ne--;
}
