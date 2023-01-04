// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;

void push(int n);
void pop();
void peek();
void display();

void main()
{
    int ch, n;
    do {
        printf("\n\nEnter your choice: \n");
        printf("1 - push()\n");
        printf("2 - pop()\n");
        printf("3 - peek()\n");
        printf("4 - display()\n");
        printf("0 - exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch(ch) {
            case 1:
                printf("Please enter an element: ");
                scanf("%d", &n);
                push(n);
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 0:
                printf("Thank you for using stacks.");
                exit(0);
            default:
                printf("Invalid Choice!");
        }   } while(ch != 0);
}

void push(int n) {
    if(top == N-1) {
        printf("Stack overflow condition occurs.");
    }
    else {
        top++;
        stack[top] = n;
    }
}

void pop() {
    int item;
    if(top == -1) {
        printf("Stack underflow condition occurs.");
    }
    else {
        item = stack[top];
        top--;
        printf("The element that was popped is %d.", item);
    }
}

void peek() {
    if(top == -1) {
        printf("Stack is totally empty.");
    }
    else {
        printf("The element at the top is %d.\n\n", stack[top]);
    }
}

void display() {
    printf("The stack is: ");
    for(int i = 0; i<=top; i++) {
        printf("%d ", stack[i]);
    }
}

