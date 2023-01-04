#include <stdio.h>
#include <stdlib.h>
#define max 20

void main() {
    int arr[max], lim, n, pos;
    printf("Enter the limit: ");
    scanf("%d", &lim);

    if(lim >= max) {
        printf("Stack overflow occuring in array, terminating program\n");
        exit(0);
    }

    printf("Enter the elements: ");
    for(int i = 0; i < lim; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter element you wish to insert: ");
    scanf("%d", &n);

    printf("Enter position of element %d: ", n);
    scanf("%d", &pos);

    for(int k=lim; k >= pos; k--)
        arr[k+1] = arr[k];
    arr[pos] = n;
    lim++;

    printf("Displaying final array...\n");
    for(int i = 0; i < lim; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
