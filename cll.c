#include "cll.h"


int main()
{
    ss* head = NULL;
    insertAtHead(&head,1);
    insertAtHead(&head,2);
    insertAtHead(&head,3);
    insertAtHead(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtMid(head->next->next,10);
    print(head);
    deleteAtEnd(&head);
    print(head);
    deleteAtMid(&head,head->next->next);
    print(head);
}