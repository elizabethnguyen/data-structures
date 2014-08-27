#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
#define NOMEM = 1
#define SUCCESS = 0

/* SinglyLinkedList: container for node 
   UNIDIRECTIONAL linked list: will store the head of the list
   also stores the size (0 initially).
   node: stores a void pointer for arbitrary values as well as
   a pointer to the next node (0 for end) */

int
slAddLast (struct SinglyLinkedList *list, void *newValue)
{
  if (list->head == NULL) {
    struct slNode *head;
    head = (struct slNode *) malloc(sizeof(struct slNode));
    
    if (head == NULL) {
      return NOMEM;
    }
    
    head->value = newValue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else {
    struct slNode *node = list->head; 
    while (node->next != NULL) {
      node = node->next;
    }
    
    struct slNode *tail;
    tail = (struct slNode *) malloc(sizeof(struct slNode));
    
    if (tail == NULL) {
      return NOMEM;
    }
    
    tail->value = newValue;
    tail->next = NULL;
    node->next = tail;
    list->size++;
  }
  return SUCCESS;
}

void
initSL (struct SinglyLinkedList *list)
{
}

int
slAddFirst (struct SinglyLinkedList *list, void *newValue)
{
  if (list->head == NULL) {
    struct slNode *root;
    root = (struct slNode *) malloc(sizeof(struct slNode));

    if (root == NULL) {
      return NOMEM;
    }

    root->value = newValue;
    root->next =NULL;
    list->head = root;
    list->size++;
  } else {
    struct slNode *head;
    head = (struct slNode *) malloc(sizeof(struct slNode));
    if (head == NULL) {
      return NOMEM;
    }

    head->value = newValue;
    head->next = list->head;
    list->head = head;
    list->size++;
  }

  return SUCCESS;
}

void
slDelete (struct SinglyLinkedList *list, struct slNode *node)
{
  struct slNode *nodeToRemove;

  if (list->size == 1) {
    free(list);
    return;
  } 
  
  if (list->head == node) {
    nodeToRemove = list->head;
    list->head = list->head->next;
  } else {
    node = list->head;
    while (node->next != node) {
      node = node->next;
    }
    nodeToRemove = node->next;
    if (nodeToRemove->next == NULL) {
      node->next = NULL;
    } else {
      node->next = nodeToRemove->next;
    }    
  }

  free(nodeToRemove);
  list->size--;
  return;
}

