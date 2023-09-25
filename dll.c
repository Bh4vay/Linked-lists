#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
typedef struct node ss;

void insertAtHead(ss** headRef,int data)
{
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*headRef == NULL){
        // newNode->next=*headRef;
        *headRef = newNode;
        return;
    }
    newNode->next=*headRef;
    (*headRef)->prev=newNode;
    *headRef = newNode;
}

void insertAtEnd(ss** headRef,int data){
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*headRef==NULL){
        // newNode->next=*headRef;
        //(*headRef)->prev=newNode;
        *headRef = newNode;
        return;
    }
    ss* temp = *headRef;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtMid(ss* node,int data){
    ss* newNode = (ss*)malloc(sizeof(ss));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    newNode->next=node->next;
    node->next->prev=newNode;
    node->next=newNode;
    newNode->prev=node;
}

void delAtHead(ss** headRef){
    ss* temp = *headRef;
    if(*headRef==NULL){
        return;
    }
    if((*headRef)->next==NULL){
        *headRef=NULL;
        free(temp);
        return;
    }
    (*headRef)->next->prev=NULL;
    *headRef=(*headRef)->next;
    free(temp);
}

void delAtEnd(ss** headRef){
    ss* temp=*headRef;
    if(*headRef==NULL){
        return;
    }
    if((*headRef)->next==NULL){
        *headRef=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void delAtMid(ss** headRef,ss* ntbd){
    ss* temp = *headRef;
    ss* pre = NULL;
    while(temp!=ntbd){
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    temp->next->prev=pre;
    free(temp);
}

void print (ss* temp){
    if(temp==NULL){
        return;
    }
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}

int main(){
    ss* head = NULL;
    
    insertAtHead(&head,3);
    insertAtHead(&head,2);
    insertAtHead(&head,1);
    print(head);
    insertAtEnd(&head,5);
    insertAtEnd(&head,4);
    print(head);
    insertAtMid(head->next->next,9);
    print(head);
    delAtHead(&head);
    print(head);
    delAtEnd(&head);
    print(head);
    delAtMid(&head,head->next->next);
    print(head);
}