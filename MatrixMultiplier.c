#include <stdio.h>
#include <stdlib.h>

void main() {
    int row1, row2, col1, col2, sum, i, j, k;
    printf("Enter the number of rows and columns for the first array: ");
    scanf("%d %d", &row1,&col1);
    printf("Enter the number of rows and columns for the second array: ");
    scanf("%d %d", &row2,&col2);

    if(col1 != row2) {
        printf("%d%dIncompatible matrices. Ammend.", col1,row2);
        exit(0);
    }

    int a[row1][col1]; 
    int b[row2][col2]; 
    int c[row1][col2];

    printf("Enter the elements for first array: \n");
    for(i = 0; i < row1; i++) {
        for(j = 0; j < col1; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements for second array: \n");
    for(i = 0; i < row2; i++) {
        for(j = 0; j < col2; j++) {
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < row1; i++) {
        for(j = 0; j < col2; j++) {
            c[i][j] = 0;
            }
        }

    for(k = 0; k < col2; k++) {
        for(i = 0; i < row1; i++) {
            for(j = 0; j < col2; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    // Printing c[][]
    for(i = 0; i < row1; i++) {
        for(j = 0; j < col1; j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n"); 
    }

}