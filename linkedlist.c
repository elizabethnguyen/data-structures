/* Work in progress ... learning to write linked lists from scratch. */
/* linkedlist.c 
   Elizabeth Nguyen */

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

void
add_node (struct SinglyLinkedList *list, void *newvalue)
{
  if (list->head == 0) {
    struct node *root;
    root = (struct node *) malloc(sizeof(struct node));
    root->value = newvalue;
    root->next = 0;
    list->head = root;
    list->size++;
  } else {
    node = list->head;
    while (node->next != 0) {
      node = node->next;
    }
    tail = (struct node *) malloc(sizeof(struct node));
    tail->value = newvalue;
    tail->next = 0;
    node->next = tail;
    list->size++;
  }
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
    if (nodeToRemove->next == 0) {
      node->next = 0;
    } else {
      node->next = nodeToRemove->next;
    }    
  }

  free(nodeToRemove);
  list->size--;
  return;
}

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

struct doublynode
{
  void * value;
  struct node *prev;
  struct node *next;
};
