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
void push_front(int, LinkedList*);
void push_back(int, LinkedList*);
int front(LinkedList);
int last(LinkedList);

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

  printf("------Insert New Element at front------\n");
  push_front(1000, &l2);
  printf("Value at index 0: %d\n", value_at(0, l2));
  printf("Value at index 1: %d\n", value_at(1, l2));
  printf("Value at index 2: %d\n", value_at(2, l2));

  printf("------Insert new Element as end---------\n");
  push_back(170, &l2);
  push_back(2332, &l2);
  printf("Value at index 0: %d\n", value_at(0, l2));
  printf("Value at index 1: %d\n", value_at(1, l2));
  printf("Value at index 2: %d\n", value_at(2, l2));
  printf("Value at index 3: %d\n", value_at(3, l2));
  printf("Value at index 4: %d\n", value_at(4, l2));
  printf("Value at index 5: %d\n", value_at(5, l2));
  printf("Value at index 6: %d\n", value_at(6, l2));

  printf("------First and last element-------\n");
  printf("Front element = %d\n", front(l2));
  printf("Last element = %d\n", last(l2));
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

void push_front(int value, LinkedList* l) {
  if (l->ptr == NULL) {
    Node* node;
    node->element = value;
    node->ptr = NULL;
    l->ptr = node;
    return;
  }
  Node* currentHead = l->ptr;
  Node* newNode;
  newNode = malloc(sizeof *newNode); // Mallocing here for practice
  newNode->element = value;
  newNode->ptr = currentHead;
  l->ptr = newNode;
}

// I have left this here as a reminder / need to confirm
// I believe this code was not working as I was creating the node on the stack and
// not on the heap. The second implementation I tried works using malloc. I am now
// allocating the memory which I can then access later. (See function below)
//void push_back(int value, LinkedList* l) {
//  Node* currentNode = l->ptr;
//  while (currentNode->ptr != NULL) {
//    printf("CurrentNode->ptr->element: %d\n", currentNode->ptr->element);
//    currentNode = currentNode->ptr;
//  } 
//  Node node;
//  node.element = value;
//  printf("Node element = %d\n", node.element);
//  node.ptr = NULL;
//  currentNode->ptr = &node;
//  currentNode->ptr->element = 69;
//  printf("CurrentNode element = %d\n", currentNode->ptr->element);
//}

void push_back(int value, LinkedList* l) {
  Node* currentNode = l->ptr;
  while (currentNode->ptr != NULL) {
    currentNode = currentNode->ptr;
  } 
  Node* node;
  node = malloc(sizeof (LinkedList));
  node->element = value;
  node->ptr = NULL;
  currentNode->ptr = node;
  printf("Does it reach here?");
}

int front(LinkedList l) {
  return l.ptr->element; 
}

int last(LinkedList l) {
  Node* node = l.ptr;

  while (node->ptr != NULL) {
    node = node->ptr;
  }
  return node->element;
}
