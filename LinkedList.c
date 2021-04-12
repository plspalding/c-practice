#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;
typedef struct Node Node;

struct LinkedList {
  struct Node* ptr;
} list;

struct Node {
  struct Node* ptr;
  int element;
};

int size(LinkedList);
bool empty(LinkedList);
int value_at(int index, LinkedList);

int main() {
  printf("Main called\n");

  struct Node node1;
  node1.ptr = NULL;
  node1.element = 10;

  struct Node node;
  node.ptr = &node1;
  node.element = 5;

  list.ptr = &node;

  // struct Node node1;
  // node1.ptr = NULL;
  // node.element = 10;

  printf("Node pointer = %p\n", node.ptr);
  printf("Element = %d\n", node.element);
  printf("Next element = %d\n", (*(node.ptr)).element);
  printf("Next element = %d\n", node.ptr->element);

  printf("The size of the linked list = %d\n", size(list));

  printf("\n====== Linked List 0 =======\n");
  LinkedList l;
  l.ptr = NULL;
  printf("Count of l = %d\n", size(l));
  fputs(empty(l) ? "true\n" : "false\n", stdout);

  printf("\n====== Linked List 1 =======\n");

  LinkedList l1;
  l1.ptr = &node1;
  printf("Count of l1 = %d\n", size(l1));
  fputs(empty(l1) ? "true\n" : "false\n", stdout);
  printf("Value at index 0: %d\n", value_at(0, l1));

  printf("\n====== Linked List 2 =======\n");

  Node n0;
  Node n1;
  Node n2;

  n0.ptr = &n1;
  n1.ptr = &n2;
  n2.ptr = NULL;

  n0.element = 1;
  n1.element = 2;
  n2.element = 3;

  LinkedList l2;
  l2.ptr = &n0;
  printf("Count of l2 = %d\n", size(l2));
  fputs(empty(l2) ? "true\n" : "false\n", stdout);
  printf("Value at index 0: %d\n", value_at(0, l2));
  printf("Value at index 1: %d\n", value_at(1, l2));
  printf("Value at index 2: %d\n", value_at(2, l2));
}

int size(LinkedList l) {
  Node *node = l.ptr;
  int count = 0;
  while (node != NULL) {
    count++;
    node = node->ptr;
  }
  return ++count;
}

bool empty(LinkedList l) {
  return l.ptr == NULL;
}

int value_at(int index, LinkedList l) {
  Node *node = l.ptr;
  int position = 0;
  //if (node != NULL && index == 0) { return node->element; }
  while (node != NULL) {
    if (position == index) { return node->element; }
    ++position;
    node = node->ptr;
  }
  abort();
}
