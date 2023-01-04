#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;   
};

int nodeCount=0;
struct node *newNode=NULL, *head=NULL;

void add();
void insert();
void delete();
void display();

void add(){
    struct node *temp;
    nodeCount++;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->next=NULL;
    printf("Enter value of node #%d: ", nodeCount);
    scanf("%d", &newNode->data);
    if(head==NULL){
        head = newNode;
        temp = head;
    }
    else{
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    head->prev = temp;
    temp->next = head;
}