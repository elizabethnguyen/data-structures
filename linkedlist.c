/* Work in progress ... learning to write linked lists from scratch. */
/* linkedlist.c 
   Elizabeth Nguyen */

#define NO_MEM = 12;

/* SinglyLinkedList: container for node 
   UNIDIRECTIONAL linked list: will store the head of the list
   also stores the size (0 initially).
   node: stores a void pointer for arbitrary values as well as
   a pointer to the next node (0 for end) */


struct SinglyLinkedList {
  struct node *head;
  int size = 0;
};


struct node {
  void *value;
  struct node *next;
};

int
add_tail (struct SinglyLinkedList *list, void *newvalue)
{
  if (list->head == NULL) {
    struct node *head;
    head = (struct node *) malloc(sizeof(struct node));

    if (head == NULL) {
      return NO_MEM;
    }

    head->value = newvalue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else {
    struct node *node = list->head;
    
    while (node->next != NULL) {
      node = node->next;
    }

    struct node *tail;
    tail = (struct node *) malloc(sizeof(struct node));

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

int
add_head (struct SinglyLinkedList *list, void *newvalue)
{
  if (list->head == NULL) {
    struct node *root;
    root = (struct node *) malloc(sizeof(struct node));

    if (root == NULL) {
      return NO_MEM;
    }

    root->value = newvalue;
    root->next =NULL;
    list->head = root;
    list->size++;
  } else {
    struct node *head;
    head = (struct node *) malloc(sizeof(struct node));

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
delete_node (struct SinglyLinkedList *list, struct node *node)
{
  struct node *temp;

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
struct node *
compareTo (struct SinglyLinkedList *list, int(*compareFunc)(const void *, const void *)) {
}

/* Not yet worked on! */
struct DoublyLinkedList
{
  struct node *head;
  struct node *tail;
  int size = 0;
};

struct node
{
  void * value;
  struct node *prev;
  struct node *next;
};

int
add_tail (struct DoublyLinkedList *list, void *newvalue) 
{
  if (list->head == NULL) {
    struct node *head;
    head = (struct node *) malloc(sizeof(struct node));

    if (head == NULL) {
      return NO_MEM;
    }

    head->value = newvalue;
    head->next = NULL;
    list->head = head;
    list->size++;
  } else if (list->tail == NULL) {
    struct node *tail;
    tail = (struct node *) malloc(sizeof(struct node));

    if (tail == NULL) {
      return NO_MEM;
    }

    tail->value = newvalue;
    tail->next = NULL;
    list->head->next = tail;
    list->size++;
  } else {
    struct node *tail = list->tail;
    struct node *newtail;

    newtail = (struct node *) malloc(sizeof(struct node));

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
add_head (struct DoublyLinkedList *list, void *newvalue) 
{
  if (list->head == NULL) {
    struct node *newhead;
    newhead = (struct node *) malloc(sizeof(struct node));

    if (newhead == NULL) {
      return NO_MEM;
    }

    newhead->value = newvalue;
    newhead->next = NULL;
    list->head = newhead;
    list->size++;
  } else {
    struct node *head = list->head;
    struct node *newhead;

    newhead = (struct node *) malloc(sizeof(struct node));

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
