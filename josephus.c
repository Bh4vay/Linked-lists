#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insertAtEnd(struct node** headRef,int data){
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(*headRef==NULL){
        newNode->next=newNode;
        *headRef=newNode;
        return;
    }
    struct node* temp = *headRef;
    while(temp->next!=*headRef){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=*headRef;
}

void josephus(int m,struct node* head){
    struct node* temp = head;
    struct node* pre;
    while(temp->next!=temp){
        int count=1;
        while(count!=m){
            pre=temp;
            temp=temp->next;
            count++;
        }
        pre->next=temp->next;
        temp=temp->next;
    }
    printf("Alive is %dth",temp->data);
}

void print(struct node* head){
    if(head == NULL){
        return;
    }
    struct node* temp = head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

int main() {
 
    int n,m;
    printf("Enter number of players:");
    scanf("%d",&n);
    printf("Enter number of skips:");
    scanf("%d",&m);
    struct node* head = NULL;
    for(int i=1;i<=n;i++){
        insertAtEnd(&head,i);
    }
    // print(head);
    josephus(m,head);
    
    return 0;
}