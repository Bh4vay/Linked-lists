// linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
} LINKED_LIST;


void
Create_LL (LINKED_LIST * list)
{
  list->head = NULL;
}

void
InsertAtBeg_LL (LINKED_LIST * list, int data)
{
  Node *newNode = (Node *) malloc (sizeof (Node));
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

void
InsertAtPos_LL (LINKED_LIST * list, int pos, int data)
{
  if (pos < 0)
    {
      return;
    }

  Node *newNode = (Node *) malloc (sizeof (Node));
  newNode->data = data;

  if (pos == 0)
    {
      newNode->next = list->head;
      list->head = newNode;
      return;
    }

  Node *current = list->head;
  for (int i = 0; i < pos - 1 && current != NULL; ++i)
    {
      current = current->next;
    }

  if (current == NULL)
    {
      free (newNode);
      return;
    }

  newNode->next = current->next;
  current->next = newNode;
}

void
DeleteAtBeg_LL (LINKED_LIST * list)
{
  if (list->head == NULL)
    {
      return;
    }

  Node *temp = list->head;
  list->head = list->head->next;
  free (temp);
}

void
DeleteAtPos_LL (LINKED_LIST * list, int pos)
{
  if (pos < 0 || list->head == NULL)
    {
      return;
    }

  if (pos == 0)
    {
      Node *temp = list->head;
      list->head = list->head->next;
      free (temp);
      return;
    }

  Node *current = list->head;
  for (int i = 0; i < pos - 1 && current != NULL; ++i)
    {
      current = current->next;
    }

  if (current == NULL || current->next == NULL)
    {
      return;
    }

  Node *temp = current->next;
  current->next = current->next->next;
  free (temp);
}

void
Print_LL (const LINKED_LIST * list)
{
  Node *current = list->head;

  while (current != NULL)
    {
      printf ("%d ", current->data);
      current = current->next;
    }

  printf ("\n");
}
#endif // LINKEDLIST_H
