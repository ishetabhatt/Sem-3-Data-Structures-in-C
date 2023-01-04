#include <stdio.h>
#include <stdlib.h>

void main() {
    int row, col, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    int arr[row][col]; int trans[col][row];
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("Enter element at (%d,%d): ",i,j);
            scanf("%d", &trans[j][i]);
        }
    }
    printf("The elements are: \n");
    for(i = 0; i < col; i++) {
        for(j = 0; j < row; j++) {
            printf("%d " , trans[i][j]);
        }
        printf("\n");
    }
}