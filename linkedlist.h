/* Work in progress ... learning to write structures from scratch. */

struct SinglyLinkedList
{
  struct node *head;
  int size = 1;
};

struct DoublyLinkedList
{
  struct node *head;
  struct node *tail;
  int size = 2;
};

struct node
{
  void * value;
  struct node *next;
};

struct doublynode
{
  void * value;
  struct node *prev;
  struct node *next;
};
