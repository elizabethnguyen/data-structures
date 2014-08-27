/* Work in progress ... learning to write linked lists from scratch. */
/* linkedlist.c 
   Elizabeth Nguyen */

#define NO_MEM = 1;

/* SinglyLinkedList: container for node 
   UNIDIRECTIONAL linked list: will store the head of the list
   also stores the size (0 initially).
   node: stores a void pointer for arbitrary values as well as
   a pointer to the next node (0 for end) */


struct SinglyLinkedList {
  struct sl_node *head;
  int size = 0;

  int (*add_first)(struct SinglyLinkedList *list, void *value);
  int (*add_last)(struct SinglyLinkedList *list, void *value);
  int (*delete)(struct SinglyLinkedList *list, struct sl_node *node);
};


struct sl_node {
  void *value;
  struct sl_node *next;
};

int
sl_add_last (struct SinglyLinkedList *list, void *newvalue)
{
  if (list->head == NULL) {
    struct sl_node *head;
    head = (struct sl_node *) malloc(sizeof(struct sl_node));

    if (head == NULL) {
      return NO_MEM;
    }

    head->value = newvalue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else {
    struct sl_node *node = list->head; 
    while (node->next != NULL) {
      node = node->next;
    }

    struct sl_node *tail;
    tail = (struct sl_node *) malloc(sizeof(struct sl_node));

    if (tail == NULL) {
      return NO_MEM;
    }

    tail->value = newvalue;
    tail->next = NULL;
    node->next = tail;
    list->size++;
  }
  return 0;
}

void
init_sl (struct SinglyLinkedList *list)
{
}

int
sl_add_first (struct SinglyLinkedList *list, void *newvalue)
{
  if (list->head == NULL) {
    struct sl_node *root;
    root = (struct sl_node *) malloc(sizeof(struct sl_node));

    if (root == NULL) {
      return NO_MEM;
    }

    root->value = newvalue;
    root->next =NULL;
    list->head = root;
    list->size++;
  } else {
    struct sl_node *head;
    head = (struct sl_node *) malloc(sizeof(struct sl_node));
    if (head == NULL) {
      return NO_MEM;
    }

    head->value = newvalue;
    head->next = list->head;
    list->head = head;
    list->size++;
  }

  return 0;

}

void
sl_delete (struct SinglyLinkedList *list, struct sl_node *node)
{
  struct sl_node *temp;

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

/* No idea what to do for this ... */
struct sl_node *
compareTo (struct SinglyLinkedList *list, int(*compareFunc)(const void *, const void *)) {
}

/* DOUBLYLINKEDLIST */
struct DoublyLinkedList
{
  struct dl_node *head;
  struct dl_node *tail;
  int size = 0;

  int (*add_first)(struct DoublyLinkedList *list, void *value); 
  int (*add_last)(struct DoublyLinkedList *list, void *value);
  int (*delete)(struct DoublyLinkedList *list, struct dl_node *node);
};

struct dl_node
{
  void * value;
  struct dl_node *prev;
  struct dl_node *next;
};

void
init_dl (struct DoublyLinkedList *list)
{
}

int
dl_add_last (struct DoublyLinkedList *list, void *newvalue) 
{
  if (list->head == NULL) {
    struct dl_node *head;
    head = (struct dl_node *) malloc(sizeof(struct dl_node));

    if (head == NULL) {
      return NO_MEM;
    }

    head->value = newvalue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else if (list->tail == NULL) {
    struct dl_node *tail;
    tail = (struct dl_node *) malloc(sizeof(struct dl_node));

    if (tail == NULL) {
      return NO_MEM;
    }

    tail->value = newvalue;
    tail->next = NULL;
    list->head->next = tail;
    list->size++;
  } else {
    struct dl_node *tail = list->tail;
    struct dl_node *newtail;

    newtail = (struct dl_node *) malloc(sizeof(struct dl_node));

    if (newtail == NULL) {
      return NO_MEM;
    }

    newtail->value = newvalue;
    newtail->next = NULL;
    tail->next = newtail;
    list->tail = newtail;
    list->size++;
  }

  return 0;
  }
}

int
dl_add_first (struct DoublyLinkedList *list, void *newvalue) 
{
  if (list->head == NULL) {
    struct dl_node *newhead;
    newhead = (struct dl_node *) malloc(sizeof(struct dl_node));

    if (newhead == NULL) {
      return NO_MEM;
    }

    newhead->value = newvalue;
    newhead->next = NULL;
    list->head = newhead;
    list->size++;
  } else {
    struct dl_node *head = list->head;
    struct dl_node *newhead;

    newhead = (struct dl_node *) malloc(sizeof(struct dl_node));

    if (newhead == NULL) {
      return NO_MEM;
    }

    newhead->value = newvalue;
    newhead->next = head->next;
    list->head = newhead;
    list->size++;
  }

  return 0;
  }
}

void
dl_delete (struct DoublyLinkedList *list, struct dl_node *node)
{
  struct dl_node *temp;

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
