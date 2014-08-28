struct slNode {
  void *value;
  struct slNode *next;
};

struct SinglyLinkedList {
  struct slNode *head;
  int size;
  int (*addFirst)(struct SinglyLinkedList *list, void *value);
  int (*addLast)(struct SinglyLinkedList *list, void *value);
  int (*delete)(struct SinglyLinkedList *list, struct slNode *node);
};

void initSL (struct SinglyLinkedList *list);
int slAddFirst (struct SinglyLinkedList *list, void *newValue);
int slAddLast (struct SinglyLinkedList *list, void *newValue);
void slDelete (struct SinglyLinkedList *list, struct slNode *node);
