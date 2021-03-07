//RECURSION PROBLEM PROGRAM 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int Factorial(int n)
{
    if(n == 0 )
    	return 1;
    else
       return n * Factorial(n-1);
}


int Fib(int x)
{
    if( x <= 1 )
	return x;
    int f1,f2,f;
    f1 = 0;
    f2 = 1;
    for(int i = 2; i <= x; i++ )
    {
	f= f1 + f2;
	f1 = f2;
	f2 = f;
    }
    return f;
}

int min(int arr[], int w)
{
    int small;
    if(w==0)
        return arr[w];
    small = min(arr, w-1);
    if(arr[w] > small)
        return small;
}

int product(int arr[], int n) {
    if (n == 1) return arr[0];

    return arr[n-1] * product(arr, n-1);
}


void Tower(int m, char Source, char Temp, char Dest)
{
    if(m==1)
    {
        printf("move %d from %c to %c\n",m,Source,Dest);
        return;
    }
    Tower(m-1, Source, Dest, Temp);
    printf("Move %d from %c to %c\n", m, Source, Dest);
    Tower(m-1, Temp, Source, Dest);
}

void inputArray(int arr[], int* n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    printf("Enter the elements: ");
    int i;
    for (i = 0; i < *n; i++) 
        scanf("%d", &arr[i]);
}

void printMenu()
{
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("3. Smallest element in an array\n");
    printf("4. Product of all elements in an array\n");
    printf("5. Tower of Hanoi Problem\n");
    printf("6. Exit\n");
}


int main()
{
    int isRunning = 1;
    while(isRunning)
    {
        int ch;
        printMenu();
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Factorial\n");
                    int n;
                    scanf("%d",&n);
                    int result;
                    result = Factorial(n);
                    printf("result = %d\n", result);
                    break;
            
            case 2: printf("Fibonacci\n");
                    int a;
                    printf("enter n:");
                    scanf("%d",&a);
                    int res = Fib(a);
                    printf("result = %d\n", res);
                    break;
            
            case 3: printf("Smallest element in an array\n");
                    int w, arr[15], j;
                    printf("enter no:");
                    scanf("%d",&w);
                    printf("enter elements in array:\n");
                    for(j=0 ; j< w ; j++)
                    {
                        scanf("%d",&arr[j]);
                    }
                    printf("smallest element is %d\n", min(arr,w-1));
                    break;

            case 4: inputArray(arr, &n);
                    printf("recursieProduct = %d\n", product(arr, n));
                    break;

            case 5: printf("Hanoi Tower Problem\n");
                    int m;
                    char S, T,D;
                    printf("enter m value:\n");
                    scanf("%d",&m);
                    Tower(m,'S', 'T', 'D');
                    break;

            case 6: isRunning = 0;
                    break;
        }
    }
}