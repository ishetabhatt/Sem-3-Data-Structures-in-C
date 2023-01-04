#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define N 20 
int stack[N]; 
int top = -1;   

void push(char x); 
void pop();
void valid();
void invalid();

void main() { 
    char exp[50];
    printf("Kindly enter expression: ");
    fgets(exp, 50, stdin);
    for(int i = 0; i < strlen(exp); i++) { 
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') { 
            push(exp[i]); 
        } 
        else if(exp[i] == ')') { 
            if(stack[top] == '(')
                pop();
            else
                invalid();
        }
        else if(exp[i] == ']') { 
            if(stack[top] == '[')
                pop();
            else
                invalid();
        }
        else if(exp[i] == '}') { 
            if(stack[top] == '{')
                pop();
            else
                invalid();
        }
    } 

    if(top == -1) { 
        valid(); 
    } 
    else { 
        invalid(); 
    } 
} 

void push(char x) { 
    if(top == N-1) {
        printf("Stack overflow condition occurs.\n");
        invalid();
    }
    else {
        top++;
        stack[top] = x;
    }
} 

void pop() { 
    if(top == -1) {
        printf("Stack underflow condition occurs.\n");
        invalid();
    }
    else {
        top--;
    }
}

void valid() {
    printf("Stack is empty, the expression is valid.\n");
    exit(0);
}

void invalid() {
    printf("Stack is not empty, the expression is invalid.\n");
    exit(0);
}