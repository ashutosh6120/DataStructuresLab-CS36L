#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_ORDER 10

int* add(int*, int*, int, int);

int main() {
    int P[MAX_MATRIX_ORDER][MAX_MATRIX_ORDER];
    int Q[MAX_MATRIX_ORDER][MAX_MATRIX_ORDER];
    int m, n, i, j;
    int* ptr;

    printf("Enter row and col of matrices:");
    scanf("%d %d", &n, &m);
    if (m > 10 || n > 10) {
        printf("Insufficient memory.");
        return -1;
    }

    printf("Enter elements of P matrix: \n");
    ptr = &P[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", (ptr + i * m + j));
        }
    }

    printf("Enter elements of Q matrix: \n");
    ptr = &Q[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", (ptr + i * m + j));
        }
    }

    int* result = add(P, Q, m, n);

    printf("Resultant matrix: \n");
    ptr = &P[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", *(result + i * m + j));
        }
        printf("\n");
    }

    free(result);
    return 0;
}


int* add(int* P, int* Q, int n, int m) {
    int* result = (int*) malloc(n * m * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            *(result + i * m + j) = *(P + i * m + j) + *(Q + i * m + j);
        }
    }
    return result;
}
