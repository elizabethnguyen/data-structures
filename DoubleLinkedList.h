#include "DoubleLinkedList.c"

struct DoubleLinkedList
{
  struct dlNode *head;
  struct dlNode *tail;
  int size = 0;

  int (*addFirst)(struct DoublyLinkedList *list, void *value); 
  int (*addLast)(struct DoublyLinkedList *list, void *value);
  int (*delete)(struct DoublyLinkedList *list, struct dlNode *node);
};

struct dlNode
{
  void * value;
  struct dlNode *prev;
  struct dlNode *next;
};

void initDL (struct DoublyLinkedList *list);
int dlAddFirst (struct DoublyLinkedList *list, void *newValue);
int dlAddLast (struct DoublyLinkedList *list, void *newValue);
void dlDelete (struct DoublyLinkedList *list, struct dlNode *node);
