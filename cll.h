#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node ss;

void insertAtHead(ss** headRef,int data)
{
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    if(*headRef==NULL){
        newNode->next=newNode;
        *headRef=newNode;
        return;
    }
    newNode->next=*headRef;
    ss* temp=*headRef;
    while(temp->next!=*headRef){
        temp=temp->next;
    }
    temp->next=newNode;
    *headRef=newNode;
}

void insertAtEnd(ss** headRef,int data){
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    if (*headRef==NULL){
        newNode->next=newNode;
        *headRef=newNode;
        return;
    }
    newNode->next=*headRef;
    ss* temp=*headRef;
    while(temp->next!=*headRef){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtMid(ss* node,int data)
{
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    newNode->next=node->next;
    node->next=newNode;
}

void deleteAtEnd(ss** headRef){
    ss* temp = *headRef;
    ss* pre = *headRef;
    while(temp->next!=*headRef){
        pre = temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
}

void deleteAtMid(ss** headRef,ss* ntbd){
    ss* temp = *headRef;
    ss* pre = *headRef;
    while(temp!=ntbd){
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
}

void print(ss* head)
{
    if(head == NULL){
        return;
    }
    ss* temp = head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}