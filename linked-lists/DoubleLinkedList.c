#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
#define SUCCESS 0
#define NOMEM 1
#define NONODE 2

/* DOUBLYLINKEDLIST */
void
initDl (struct DoubleLinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->addFirst = &dlAddFirst;
  list->addLast = &dlAddLast;
  list->delete = &dlDelete;
}

int
dlAddLast (struct DoubleLinkedList *list, void *value) 
{
  struct dlNode *newNode;
  struct dlNode *position;

  newNode = (struct dlNode *) malloc(sizeof(struct dlNode));

  if (newNode == NULL) {
    return NOMEM;
  }
  
  if (list->head != NULL) {
    position = list->head;

    while (position->next != NULL) {
      position = position->next;
    }
    position->next = newNode;
    list->tail = newNode;
  } else {
    list->head = newNode;
  }
  newNode->value = value;
  newNode->next = NULL;
  list->size++;

  return SUCCESS;
}


int
dlAddFirst (struct DoubleLinkedList *list, void *value) 
{
  struct dlNode *newNode;
  newNode = (struct dlNode *) malloc(sizeof(struct dlNode));

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
dlDelete (struct DoubleLinkedList *list, struct dlNode *nodeToRemove)
{
  struct dlNode *placeholderNode;
  struct dlNode *position;

  if (list->size == 1) {
    free(list);
    return SUCCESS;
  }

  position = list->head;
  
  if (nodeToRemove == position) {
    if (list->head->next == list->tail) {
      list->tail = NULL;
    }
    list->head = list->head->next;
    free(position);
    list->size--;
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
    list->tail = position;
  } else {
    position->next = placeholderNode->next;
  }

  free(placeholderNode);
  list->size--;
  return SUCCESS;

}
