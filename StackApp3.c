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
//void display(char arr[]);

void main() {
    char exp[50]; char post[50]; char par[50] = "("; char x, temp;
    int postFlag = 0, right = strlen(exp);

    printf("Kindly enter expression: ");
    scanf("%s", exp);
    strcat(par, exp);
    strcat(par, ")");
    strcpy(exp, par);
    //push('(');
    

	//strcat(exp,")");

    for(int i = 0; i < right; i++)  
    {  
        temp = exp[i];  
        exp[i] = exp[right];  
        exp[right] = temp;  
        right--;  
    }  

    printf("%s", exp);

    //char exp[50] = strrev(exp);
    // push('(');
	// strcat(exp,")");

    for(int i = 0; i < strlen(exp); i++) {
        if(exp[i] == ')')
            exp[i] = '(';
        if(exp[i] == '(')
            exp[i] = ')';
    }

    for(int i = 0; i < strlen(exp); i++) { 

        if(isdigit(exp[i]) || isalpha(exp[i])) {
            post[postFlag++] = exp[i]; // operand added to postfix expression
            printf("%c\n", post[postFlag-1]); }

        else if(exp[i] == '(')
            push(exp[i]); // opening parenthesis

        else if(opCheck(exp[i]) == 1) { // operator
            if(opPreced(exp[i]) >= opPreced(stack[top])) {
                push(exp[i]); 
            }
            else {
                post[postFlag++] = pop();
                push(exp[i]);
                printf("%c\n", post[postFlag-1]);
            }
        }

        else if(exp[i] == ')') {    
            x = pop();
            while(x != '(') {
                post[postFlag++] = x;
                printf("%c\n", post[postFlag-1]); 
                x = pop();
                
            }
        }

        else
            invalid();
    }
    for(int i = 0; i < strlen(post); i++) {
        printf("%c", post[i]);
    }
    printf("\n");
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
    if(a == '^' || a == '*' || a == '/' || a == '+' || a == '-')
        return 1;
    else
        return 0;
}

int opPreced(char a) {
    if(a == '^')
        return 3;
    else if(a == '*' || a == '/')
        return 2;
    else if(a == '+' || a == '-')
        return 1;
    else
        return 0;
}

void invalid() {
    printf("Invalid.\n");
    exit(0);
}

// //void display(char arr[]) {
//     printf("Following is the result: ");
//     //int x = strlen(arr);
//     //for(int i = 0; i < x; i++) {
//     //    printf("%c", arr[i]);
//     //}
//     int x = strlen(arr);
//     char temp;
//     //printf("%s\n", strrev(arr));
//     for(int i = 0; i < x; i++)  
//     {  
//         temp = arr[i];  
//         arr[i] = arr[x];  
//         arr[x] = temp;  
//         x--;  
//     }
//     //printf("%s", arr);
//     x = strlen(arr);
//     for(int i = 0; i < x; i++) {
//        printf("%c", arr[i]);
//     }
// }