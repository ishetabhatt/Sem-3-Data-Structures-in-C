#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 20

int stack[N];
int top = -1;
void push(char x);
char pop();
int opCheck(char a);
int opPreced(char a);
void invalid();
void display(char arr[]);

void main() {
    char exp[50]; char post[50]; char x;
    int postFlag= 0;
    printf("Kindly enter expression: ");
    scanf("%s", exp);
    push('(');
    strcat(exp,")");
    for(int i = 0; i < strlen(exp); i++) {
        if(isdigit(exp[i]) || isalpha(exp[i]))
            post[postFlag++] = exp[i]; // operand
        else if(exp[i] == '(')
            push(exp[i]); // opening parenthesis
        else if(opCheck(exp[i]) == 1) { // operator
            if(opPreced(exp[i]) > opPreced(stack[top])) {
                push(exp[i]); }
            else {
                post[postFlag++] = pop();
                push(exp[i]);
            } 
        }
        else if(exp[i] == ')') {
            x = pop();
            while(x != '(') {
                post[postFlag++] = x;
                x = pop();
            } }
        else
            invalid();
    }
    display(post);
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

char pop() {
    if(top == -1) {
      printf("Stack underflow condition occurs.\n");
      invalid();
    }
    else {
        char x = stack[top];
        top--;
        return x;
    }
}

int opCheck(char a) {
    if(a == '^' || a == '*' || a == '/' || a == '+' || a ==
'-')
        return 1;
    else
        return 0;
}