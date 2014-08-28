#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
#define SUCCESS 0
#define NOMEM 1
#define NONODE 2

/* SinglyLinkedList: container for node 
   UNIDIRECTIONAL linked list: will store the head of the list
   also stores the size (0 initially).
   node: stores a void pointer for arbitrary values as well as
   a pointer to the next node (0 for end) */

void
initSL (struct SinglyLinkedList *list)
{
  list->head = NULL;
  list->size = 0;
  list->addFirst = &slAddFirst;
  list->addLast = &slAddLast;
  list->delete = &slDelete;
}

int
slAddLast (struct SinglyLinkedList *list, void *value)
{
  struct slNode *newNode;
  struct slNode *position;

  newNode = (struct slNode *) malloc(sizeof(struct slNode));

  if (newNode == NULL) {
    return NOMEM;
  }

  if (list->head != NULL) {
    position = list->head;
    
    while (position->next != NULL) {
      position = position->next;
    }
    position->next = newNode;
  } else {
    list->head = newNode;
  }
  newNode->value = value;
  newNode->next = NULL;
  list->size++;
  return SUCCESS;
}

int
slAddFirst (struct SinglyLinkedList *list, void *value)
{
  struct slNode *newNode;
  newNode = (struct slNode *) malloc(sizeof(struct slNode));

  if (newNode == NULL) {
    return NOMEM;
  }

  if (list->head != NULL) {
    newNode->next = list->head;
    list->head = newNode;
  } else {
    list->head = newNode;
    newNode->next = NULL;
  }

  newNode->value = value;
  list->size++;
  return SUCCESS;
}

int
slDelete (struct SinglyLinkedList *list, struct slNode *nodeToRemove)
{
  struct slNode *placeholderNode;
  struct slNode *position;

  if (list->size == 1) {
    free(list);
    return SUCCESS;
  } 

  position = list->head;

  if (nodeToRemove == position) {
    list->head = list->head->next;
    list->size--;
    free(position);
    return SUCCESS;
  }

  while (nodeToRemove != position->next) {
    position = position->next;
    if (position == NULL) {
      return NONODE;
    }
  }
  
  placeholderNode = position->next;
  
  if (placeholderNode->next == NULL) {
    position->next = NULL;
  } else {
    position->next = placeholderNode->next;
  }   
 
  free(placeholderNode);
  list->size--;
  return SUCCESS;
}


