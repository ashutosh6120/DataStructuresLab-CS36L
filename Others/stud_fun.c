#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
  int regno;
  char name[10];
  int totalmarks;
};

void Read(struct Student *);
void Disp(struct Student*);
void  Max(struct Student *);
void Insert(struct Student*);
void Delete(struct Student*);
int size, NE=0;
 void main()
{
  struct Student *S;

  int choice;
  printf("enter size:");
  scanf("%d",&size);
  S = (struct Student *) malloc(size* sizeof(struct Student));
  for(;;)
  {
   printf("enter choice\n1:Read\n2:Display\n3:Find highest\n4:Insert\n5:Delete\n6:exit\n");
  scanf("%d", &choice);
  switch(choice)
  {

    case 1: Read(S); Disp(S); break;
    case 2: Disp(S); Disp(S); break;
    case 3: Max(S); break;
    case 4: Insert(S); Disp(S); break;

    case 5: Delete(S); Disp(S); break;
    default:exit(0);

  }
  }
  //free(S);
  getch();
}



void Read(struct Student *S)
{
  int i, N;
   printf("enter noo of students information you want to read\n");
   scanf("%d", &N);
  for(i=0;i<N;i++)
  {
    printf("enter Regno  name total marks of  student %d\n:",i+1);
   scanf("%d%s %d", &(S+i)->regno, &(S+i)->name, &(S+i)->totalmarks);
  }
  NE=N;
}



  void Disp(struct Student *S)

{     int i;
  printf("\nReg number     Name   TotalMarks\n__________________________\n");
  for(i=0;i<NE;i++)
  {
   printf("%d   %s   %d\n", (S+i)->regno, (S+i)->name,
     (S+i)->totalmarks);
  }
}

void Max(struct Student *S)
{
   int large, si,i;
  large = S->totalmarks;
 si=0;
   for(i=1;i<NE;i++)
   {
     if((S+i)->totalmarks > large)
     {
	 large = (S+i)->totalmarks;
	 si = i;
     }
  }

  printf("Highest marks is scored is %d\n", large);
  printf("student who scored is:\n");
  printf("Regno:%d\tName:%s\n", (S+si)->regno,(S+si)->name);

 }


 void Insert(struct Student *S)
 {
    int i, regno, totalmarks;
    char name[10];
   if(NE==size)
   {
     printf("Insufficient memory\n Reallocating by doubling the size");
     //return;
     S = (struct Student*) realloc(S,size*2);
   }
   printf("Enter student information\n");
   printf("Enter Reg no:");
   scanf("%d",&regno);
   printf("enter name:");
   scanf("%s", name);
   printf("enter marks:");
   scanf("%d", &totalmarks);
   i=NE-1;
   while(i>=0 && (S+i)->regno > regno)
     {
      (S+i+1)->regno=(S+i)->regno;
     strcpy((S+i+1)->name,(S+i)->name);
      (S+i+1)->totalmarks=(S+i)->totalmarks;
      i--;
     }


      (S+i+1)->regno=regno;
      strcpy((S+i+1)->name,name);
      (S+i+1)->totalmarks=totalmarks;
      NE++;
  }
   void Delete(struct Student *S)
 {
    int i, regno;

   if(NE==0)
   {
     printf("Empty\n");
     return;
   }

   printf("Enter Reg no:");
   scanf("%d",&regno);
    for(i=0; i<NE; i++)
	{
	   if((S+i)->regno ==regno)
	     break;
	}
	if(i==NE)
	{
	   printf("student with reg no %d doesn't exist in the list\n");
	   return;
	}
	for(;i<NE; i++)
	{
	  (S+i)->regno = (S+i+1)->regno;
	  strcpy((S+i)->name,(S+i+1)->name);
	  (S+i)->totalmarks = (S+i+1)->totalmarks;
	}

      NE--;
    }
