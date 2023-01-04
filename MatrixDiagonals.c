#include <stdio.h>
#include <stdlib.h>

void main() {
    int ord, i, j, sumDgl = 0, sumUp = 0, sumDown = 0;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &ord);
    int arr[ord][ord];

    for(i = 0; i < ord; i++) {
        for(j = 0; j < ord; j++) {
            printf("Enter element at (%d,%d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = 0; i < ord; i++) {
        for(j = 0; j < ord; j++) {
            if(i < j)
                sumUp += arr[i][j];
            else if(i > j)
                sumDown += arr[i][j];
            else
                sumDgl += arr[i][j];
        }
    }
    
    printf("Sum of all diagonal elements: %d \n", sumDgl);
    printf("Sum of upper diagonal elements: %d \n", sumUp);
    printf("Sum of lower diagonal elements: %d \n", sumDown);
}