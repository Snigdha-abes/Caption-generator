#include <stdio.h>

#define MAX 20 

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    int m, n, a[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Transpose the matrix
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&a[i][j], &a[j][i]);
        }
    }

    // Reverse each row to get the clockwise rotated matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(&a[i][j], &a[i][n - 1 - j]);
        }
    }

    // Print rotated matrix
    printf("Rotated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}