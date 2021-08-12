#include <stdio.h>
#define MAX_SIZE 17

void read(int*, int*);
void disp(int*, int);
void reverse(int*, int);

int main() {
    int a[MAX_SIZE], n;
    read(a, &n);
    disp(a, n);
    reverse(a, n);
    disp(a, n);
    return 0;
}

void read(int* arr, int* nptr) {
    printf("Enter no of elements in array:");
    scanf("%d", nptr);
    if (*nptr > MAX_SIZE) {
        printf(" memory insufficient\n");
        return;
    }

    int *ptr;
    printf("Enter elements of array: ");
    for (ptr = arr; ptr < arr + *nptr; ptr++)
        scanf("%d", ptr);
}

void disp(int* arr, int n) {
    printf("The elements are:");
    int *ptr;
    for (ptr = arr; ptr < arr + n; ptr++)
        printf("%d ", *ptr);
    printf("\n");
}

void reverse(int* arr, int n) {
    printf("Reversed array:\n");
    int *p1, *p2;
    for (p1 = arr, p2 = arr + n - 1; p1 < p2; p1++, p2--) {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}
