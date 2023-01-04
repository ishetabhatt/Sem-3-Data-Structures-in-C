// Deletion of element at the end of array

#include <stdio.h>
#include <stdlib.h>
#define max 5

void main() {
    int arr[max], i, j;
    printf("Enter the limit: ");
    scanf("%d", &j);
    if(j == 0) {
        printf("Data underflow taking place. Array does not exist.");
        exit(0);
    }
    printf("Enter the elements: ");
    for(i=0; i<j; i++)
        scanf("%d", &arr[i]);
    j--;
    printf("After deletion, the elements are: ");
    for(i = 0; i<j; i++)
        printf("%d ", arr[i]);
    printf("\n");
}