// Addition and Subtraction of two multidimension arrays

#include <stdio.h>
#include <stdlib.h>

void main() {
    int row, column, choice, i, j;
    printf("What operation do you want to perform on your matrices? [1 for addition, 2 for subtraction]: ");
    scanf("%d", &choice);
    if((choice == 1 || choice == 2) == 0) {
        printf("%d Invalid choice.\n\n", choice);
        exit(0);
    }

    printf("Please insert number of rows: ");
    scanf("%d", &row);
    printf("Please insert number of columns: ");
    scanf("%d", &column);
    int a[row][column]; int b[row][column]; int c[row][column];

    printf("Please enter elements of the first array: \n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("Enter element at (%d,%d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Please enter elements of the second array: \n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("Enter element at (%d,%d): ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    switch(choice) {
        case 1:
            for(i = 0; i < row; i++) {
                for(j = 0; j < column; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            break;
        case 2: 
            for(i = 0; i < row; i++) {
                for(j = 0; j < column; j++) {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }
            break;            
    }
    
    printf("The following is the resulting matrix: \n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

