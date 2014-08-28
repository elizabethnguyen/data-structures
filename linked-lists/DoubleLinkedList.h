struct dlNode
{
  void * value;
  struct dlNode *prev;
  struct dlNode *next;
};

struct DoubleLinkedList
{
  struct dlNode *head;
  struct dlNode *tail;
  int size;
  int (*addFirst)(struct DoubleLinkedList *list, void *value); 
  int (*addLast)(struct DoubleLinkedList *list, void *value);
  int (*delete)(struct DoubleLinkedList *list, struct dlNode *node);
};


void initDL (struct DoubleLinkedList *list);
int dlAddFirst (struct DoubleLinkedList *list, void *newValue);
int dlAddLast (struct DoubleLinkedList *list, void *newValue);
int dlDelete (struct DoubleLinkedList *list, struct dlNode *node);
