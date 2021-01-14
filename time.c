//time program
/* 	Define a structure called Time containing 3 integer members(hour,minute,second). Develop a menu driven program to perform the following by writing separate 		function for each operation. a) To read time b) To display time c)To Update time d) Add two times by writing Add(T1,T2) which returns the new Time.
	Update function increments the time by one second and returns the new time(if the increment results in 60 seconds, then the second member is set to zero 	and minute member is incremented by one. Then , if the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. 	Finally when the hour becomes 24, it is set to zero)
	Note: Illustrate the use of pointer to a structure variable and passing and returning  of  structure type to and from the function(both by value and 		reference).
*/


#include<stdio.h>
#include<stdlib.h>
struct TIME
{
	int hour, min, sec;
};
typedef struct TIME time;
void read(time*);
void disp(time*);
void update(time*);
void add(time*, time*, time*);
void main()
{
    int ch;
    time t1,t2,t3,t4;
    for(;;)
    {
	printf("enter choice:\n 1: read\n 2: update\n 3: add\n 4: exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:
		  printf("read t1=\n");
		  read(&t1);
		  printf("read t2=\n");
		  read(&t2);
		  printf("\nt1=");
		  disp(&t1);
		  printf("\nt2=");
		  disp(&t2);
		  break;
	   case 2:
		  read(&t3);
		  update(&t3);
		  disp(&t3);
		  break;
	   case 3:
		  add(&t1, &t2, &t4);
		  disp(&t4);
		  break;
	   default: exit(0);
	}
     }
}

void read(time *t)
{
    printf("enter hours min and sec\n ");
    scanf("%d %d %d", &t->hour, &t->min, &t->sec);
}

void disp(time *t)
{
    printf("%d : %d : %d\n", t->hour, t->min, t->sec);
}

void update(time *t)
{
    t->sec++;
    if(t->sec==60)
    {
        t->min=t->min+t->sec/60;
        t->sec=t->sec%60;
	if(t->min>=60)
	{
	   t->hour+=t->min/60;
	   t->min=t->min % 60;
	   if(t->hour >= 24)
	   {
		t->hour= t->min= t->sec=0;
	   }
	}
     }
}


void add(time *t1, time *t2, time *t3)
{
     t3->hour= t1->hour + t2->hour;
     t3->min= t1->min + t2->min;
     t3->sec= t1->sec + t2->sec;
     if(t3->sec >=60)
     {
	t3->min= t3-> min + t3->sec/60;
	t3->sec= t3->sec % 60;
	if(t3->min >= 60 )
	{
	   t3->hour+=t3->min/60;
	   t3->min= t3->min %60;
	   if(t3->hour>=24)
		t3->hour= t3->min= t3->sec= 0;
	}
     }
}
		  

