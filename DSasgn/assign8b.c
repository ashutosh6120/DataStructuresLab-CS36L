//DYNAMIC ARRAY OPERATIONS!!!

#include <stdio.h>
#include <stdlib.h>

#define INI_ARRAY_SIZE 10

// Funtion prototypes
void read();
void display();
void insert();
void delete1();
void insert_by_order();
void delete_by_element();

// Global variables
int size = 0;
int capacity = INI_ARRAY_SIZE;
int* A;

int main() {
    int isRunning = 1;
    A = (int*) malloc(INI_ARRAY_SIZE*sizeof(int));

    while (isRunning) {
        printf("\n\nPerform operations on array: \n");
        printf("-------------------------------------------\n");
        printf("1. Read elements into array\n");
        printf("2. Display elements in array\n");
        printf("3. Insert ele into array at some position\n");
        printf("4. Delete ele from array at some position\n");
        printf("5. Insert ele by order\n");
        printf("6. Delete ele by value\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        unsigned int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                read();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                display();
                break;
            case 4:
                delete1();
                display();
                break;
            case 5:
                insert_by_order();
                display();
                break;
            case 6:
                delete_by_element();
                display();
                break;
            case 7:
                printf("exited\n");
                isRunning = 0;
                break;
            default:
                printf("Invalid option.\n");
                isRunning = 0;
                break;
        }
    }
    return 0;
}

// Function to read integers into the array
void read() {
    int n, i;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    if (n > capacity) {
        printf("Resizing array \n");
        A = (int*) realloc(A, capacity*2*sizeof(int));
        capacity *= 2;
    }

    size = n;

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (A + i));
    }
}

// Function to display the elements of an array in a presentable form
void display() {
    if (size == 0) {
        printf("The array is empty\n");
    } else {
        int i;
        printf("A[] = %d ", *(A));
        for (i = 1; i < size; i++) {
            printf("%d ", *(A + i));
        }
        printf("\n");
    }
}

// Function to insert elements to any position in an array.
void insert() {
    if (size == capacity) {
        printf("Resizing::\n");
        A = (int*) realloc(A, capacity*2*sizeof(int));
        capacity *= 2;
    }
    int pos, ele;
    printf("Enter position to insert array into: ");
    scanf("%d", &pos);
    printf("Enter element to insert into array: ");
    scanf("%d", &ele);
    if (pos >= 1 && pos <= size+1) {
        int i;
        for (i = size; i >= pos; i--)
            *(A + i) = *(A + i - 1);
        *(A + i) = ele;
        size++;
    } else {
        printf("Invalid position, Cannot insert. \n");
        return;
    }
}

void delete1() {
    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    } else {
        int pos;
        printf("Enter position of element to be deleted: ");
        scanf("%d", &pos);
        if (pos >= 1 && pos <= size) {
            int i;
            for (i = pos - 1; i < size - 1; i++) {
                *(A + i) = *(A + i + 1);
            }
            size--;
        } else {
            printf("Invalid position. Cannot delete. \n");
            return;
        }
    }
}

void insert_by_order() {
    if (size == capacity) {
        printf("Resizing::\n");
        A = (int*) realloc(A, capacity*2*sizeof(int));
        capacity *= 2;
    }
    int ele, i;
    printf("Enter the element to be inserted in order: ");
    scanf("%d", &ele);
    for (i = size - 1; i >= 0 && *(A + i) > ele; i--)
        *(A + i + 1) = *(A + i);
    *(A + i + 1) = ele;
    size++;
}

void delete_by_element() {
    if (size == 0) {
        printf("Array is empty. Cannot delete. \n");
        return;
    } else {
        int i, ele;
        printf("Enter the element to be delete: ");
        scanf("%d", &ele);
        for (i = 0; i < size && *(A + i) != ele; i++);
        if (i == size) {
            printf("Element not found,Cannot delete \n");
            return;
        } else {
            printf("%d is deleted from position %d.\n", ele, i);
            for (; i < size - 1; i++) {
                *(A + i) = *(A + i + 1);
            }
            size--;
        }
    }
}
