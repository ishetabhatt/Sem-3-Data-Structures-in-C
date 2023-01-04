#include<stdio.h>
#include<string.h> 
//#include<limits.h>
#include <ctype.h>
#include<stdlib.h>
# define MAX 100
int top = -1;
char stack[MAX];

// checking if stack is full
int isFull() {
    return top == MAX - 1;
} 

// checking is stack is empty
int isEmpty() { 
    return top == -1; 
}

// Push function here, inserts value in stack and increments stack top by 1
void push(char item) {
    if (isFull()) 
        return; 
	top++;
	stack[top] = item;
}

// Function to remove an item from stack.  It decreases top by 1 
int pop() { 
    if (isEmpty()) 
        return INT_MIN; 
        
    // decrements top and returns what has been popped      
    return stack[top--]; 
} 

// Function to return the top from stack without removing it 
int peek(){ 
    if (isEmpty()) 
        return INT_MIN; 
    return stack[top]; 
} 

// A utility function to check if the given character is operand 
// int checkIfOperand(char ch) {
//     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
// } 

// Fucntion to compare precedence
// If we return larger value means higher precedence 
int precedence(char ch) 
{ 
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
} 

// The driver function for infix to postfix conversion 
int getPostfix(char* exp) 
{ 
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i) 
    { 
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output. 
        if(isdigit(exp[i]) || isalpha(exp[i]))  
            exp[++j] = exp[i]; 

        // Here, if we scan character ‘(‘, we need push it to the stack. 
        else if (exp[i] == '(') 
            push(exp[i]); 

        // Here, if we scan character is an ‘)’, we need to pop and print from the stack  
        // do this until an ‘(‘ is encountered in the stack. 
        else if (exp[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                exp[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1; // invalid exp              
            else
                pop(stack); 
        } 
        else // if an opertor
        { 
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) 
                exp[++j] = pop(stack); 
            push(exp[i]); 
        } 

    } 

    // Once all inital exp characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty(stack)) 
        exp[++j] = pop(stack); 

    exp[++j] = '\0'; 
    
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    //change brackets
    brackets(exp);
    //get postfix
    getPostfix(exp);
    // reverse string again
    reverse(exp);
}

int main()
{    
    char exp[50];
    printf("Kindly enter exp: ");
    scanf("%s", exp);
    InfixtoPrefix(exp); 

    printf("The prefix is: ");
    printf("%s\n",exp);

    return 0; 
}