#include <stdio.h>
#include <stdlib.h>
#define max 20

void main() {
    int arr[max], lim, pos;
    printf("Enter the limit: ");
    scanf("%d", &lim);

    if(lim == 0) {
        printf("Stack underflow occuring in array, terminating program\n");
        exit(0);
    }

    printf("Enter the elements: ");
    for(int i = 0; i < lim; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the position at which you want deletion to occur: ");
    scanf("%d", &pos);

    for(int k = pos; k < lim; k++)
        arr[k] = arr[k+1];
    lim--;

    printf("Displaying final array...\n");
    for(int i = 0; i < lim; i++)
        printf("%d ", arr[i]);
    printf("\n");
}