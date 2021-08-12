// Write a function that receives a sorted array of integers and an integer value and inserts the value
// in its correct place. use pointer to array

#include <stdio.h>
#define MAX_ARR_SIZE 10

void read(int*, int*);
void insert(int*, int*);
void disp(int*, int);

int main()
{
    int a[MAX_ARR_SIZE], n;
    read(a, &n);
    insert(a, &n);
    disp(a, n);
    return 0;
}

void read(int *arr, int *nptr) {
    printf("Enter no of elements in array: ");
    scanf("%d", nptr);
    if (*nptr > MAX_ARR_SIZE) {
        printf("memory insufficient\n");
        return;
    }

    int *ptr;
    printf("Enter elements in ascending order: ");
    for (ptr = arr; ptr < arr + *nptr; ptr++)
        scanf("%d", ptr);
}

void insert(int* arr, int* nptr) {
    int ele;
    if (*nptr == MAX_ARR_SIZE) {
        printf("Array is full,Cannot insert\n");
        return;
    }
    printf("Enter the element into array: ");
    scanf("%d", &ele);
    int* ptr;
    for (ptr = arr + *nptr - 1; ptr >= arr && *ptr > ele; ptr--)
        *(ptr + 1) = *ptr;
    *(ptr + 1) = ele;
    (*nptr)++;
}

void disp(int* arr, int n) {
    printf("\nnew sorted array:");
    int *ptr;
    for (ptr = arr; ptr < arr + n; ptr++)
        printf("%d ", *ptr);
    printf("\n");
}
