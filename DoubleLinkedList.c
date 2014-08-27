#define NOMEM = 1;

/* DOUBLYLINKEDLIST */
void
initDl (struct DoublyLinkedList *list)
{
}

int
dlAddLast (struct DoublyLinkedList *list, void *newValue) 
{
  if (list->head == NULL) {
    struct dlNode *head;
    head = (struct dlNode *) malloc(sizeof(struct dlNode));

    if (head == NULL) {
      return NOMEM;
    }

    head->value = newValue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else if (list->tail == NULL) {
    struct dlNode *tail;
    tail = (struct dlNode *) malloc(sizeof(struct dlNode));

    if (tail == NULL) {
      return NOMEM;
    }

    tail->value = newValue;
    tail->next = NULL;
    list->head->next = tail;
    list->size++;
  } else {
    struct dlNode *tail = list->tail;
    struct dlNode *newTail;

    newTail = (struct dlNode *) malloc(sizeof(struct dlNode));

    if (newTail == NULL) {
      return NOMEM;
    }

    newTail->value = newValue;
    newTail->next = NULL;
    tail->next = newTail;
    list->tail = newTail;
    list->size++;
  }

  return 0;
}


int
dlAddFirst (struct DoublyLinkedList *list, void *newValue) 
{
  if (list->head == NULL) {
    struct dlNode *newHead;
    newhead = (struct dlNode *) malloc(sizeof(struct dlNode));

    if (newHead == NULL) {
      return NOMEM;
    }

    newHead->value = newValue;
    newHead->next = NULL;
    list->head = newHead;
    list->size++;
  } else {
    struct dlNode *head = list->head;
    struct dlNode *newHead;

    newhead = (struct dlNode *) malloc(sizeof(struct dlNode));

    if (newHead == NULL) {
      return NOMEM;
    }

    newHead->value = newValue;
    newHead->next = head->next;
    list->head = newHead;
    list->size++;
  }

  return 0;
}

void
dlDelete (struct DoublyLinkedList *list, struct dlNode *node)
{
  struct dlNode *temp;

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
