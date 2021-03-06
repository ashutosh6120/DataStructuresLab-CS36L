// Define a structure called Student with the members: name, reg_no, marks in 3 tests and average_ marks.
// Develop a menu driven program to perform the following by writing separate function
// for each operation: a)read information of N students b) display students information c)
// to calculate the average of best two test marks of each student


#include<stdio.h>
#include<stdlib.h>
#define MAX_NAME_LENGTH 100
#define MAX_ARRAY_SIZE 10
struct Student{
	char name[MAX_NAME_LENGTH];
	int reg_no;
	double marks[3];
	double avg_marks;
};

int size=0;
struct Student *read(struct Student*);
struct Student *display(struct Student*);
struct Student *best2avg(struct Student*);

int main()
{
	struct Student* s=NULL;
	int isRunning=1;
	while(isRunning){
		printf("1.read students into array\n 2.display elements in the array\n 3.get avg of best two marks\n 4.exit\n");
	printf("enter your choice:");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		s=read(s);
		break;
	case 2:
		display(s);
		break;
	case 3:
		best2avg(s);
		break;
	case 4:
		isRunning=0;
		break;
	default:
		printf("invalid choice\n");
		break;
	}
    }
if(s!=NULL)
free(s);
return 0;
}

struct Student *read(struct Student* arr) {
    int n, i, j;
    double total = 0.0;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    if (arr != NULL)
    free(arr);
    size = n;
    arr = (struct Student*) malloc(n*sizeof(struct Student));
    printf("Enter students details:\n");
    for (i = 0; i < n; i++) {
        total = 0.0;
        printf("Student %d name: ", i+1);
        scanf("%s", (arr + i)->name);
        printf("Student %d regn no.: ", i+1);
        scanf("%d", &(arr + i)->reg_no);
        for (j = 0; j < 3; j++) {
            printf("Student %d subject %d marks: ", i+1, j+1);
            scanf("%lf", &(arr + i)->marks[j]);
            total += (arr + i)->marks[j];
        }
        (arr + i)->avg_marks = total/3.0;
        printf("\n");
    }
    return arr;
}

struct Student *display(struct Student* arr) {
    int i;
    if (size == 0) {
        printf("Array empty. \n");
        return;
    }
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Student Name\t Student regn no.\t Marks 1\t Marks 2\t Marks 3\t Avg Marks\n");
    printf("--------------------------------------------------------------------------------------------\n");
    for (i = 0; i < size; i++)
        printf("%s\t\t%d\t\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\n", (arr + i)->name, (arr + i)->reg_no, (arr + i)->marks[0], (arr + i)->marks[1], (arr + i)->marks[2], (arr + i)->avg_marks);
}

struct Student *best2avg(struct Student* arr) {
    int i;
    if (size == 0) {
        printf("Array empty. \n");
        return;
    }
    printf("----------------------------------------------------------------\n");
    printf("Student Name\t Student reg no.\t Avg. of best two\n");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < size; i++) {
        double b1 = -1.0, b2 = -1.0;
        int j;
        for (j = 0; j < 3; j++) {
            if ((arr + i)->marks[j] >= b1) {
                b2 = b1;
                b1 = (arr + i)->marks[j];
            }

            if ((arr + i)->marks[j] >= b2 && (arr + i)->marks[j] != b1)
                b2 = (arr + i)->marks[j];
        }
        double avg = (b1 + b2)/2;
        printf("%s\t\t%d\t\t%.2f\n", (arr + i)->name, (arr + i)->reg_no, avg);
    }
}

