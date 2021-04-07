#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void append(int, int* array);

typedef struct Vector Vector;

int size(Vector);
int capacity(Vector);
bool isEmpty(Vector);
int atIndex(int, Vector);
void push(int, Vector*);
void insertAt(int, int, Vector*);

void resizeVector(Vector* v);

struct Vector {
  int size;
  int capacity;
  int* elements;
} vector;

int main(int argc, char* argv[]) {

  vector.size = 0;
  vector.capacity = 10;
  vector.elements = (int *) malloc(sizeof(int) * vector.capacity);

  for(int i = 0; i < vector.capacity-1; i++) {
    int value = i + 1;
    *(vector.elements + i) = value;
  }
  vector.size = vector.capacity;

  //printf("Size: %d\n", size(vector));
  //printf("Capacity: %d\n", capacity(vector));
  //printf("Is empty: %d\n", isEmpty(vector));
  //printf("Element at index 0: %d\n", atIndex(0, vector));
  //printf("Element at index 1: %d\n", atIndex(1, vector)); 
  //printf("Element at index 2: %d\n", atIndex(2, vector));

  //printf("push\n"); push(100, &vector);
  //printf("size of vector: %d\n", vector.size); 
  //printf("last element: %d\n", *(vector.elements + vector.size-1));

  //printf("push\n"); push(200, &vector);
  //printf("size of vector: %d\n", vector.size - 1);
  //printf("capacity: %d\n", vector.capacity);
  //printf("last element: %d\n", *(vector.elements + vector.size-1));
  //

  printf("The size of Vector is now: %d\n", vector.size);
  printf("The capacity of the Vector is now %d\n", vector.capacity);

  for (int i = 0; i < vector.size; i++) {
    printf("%d\n", *(vector.elements+i));
  }

  printf("==========\n");


  insertAt(1000, 2, &vector);
  printf("The size of Vector is now: %d\n", vector.size);
  printf("The capacity of the Vector is now %d\n", vector.capacity);
  for (int i = 0; i < vector.size-1; i++) {
    printf("%d\n", *(vector.elements+i));
  }
  return 0;
}

int size(Vector v) {
  return v.size;
}

int capacity(Vector v) {
  return v.capacity;
}

bool isEmpty(Vector v) {
  return v.size == 0;
}

int atIndex(int index, Vector v) {
  return *(v.elements + index);
}

void push(int value, Vector* v) {
  if (v->size == v->capacity) {
    printf("Vector is full, we need to resize\n");
    resizeVector(v);
  }
  *(v->elements + v->size) = value;
  v->size = v->size + 1;
}

void insertAt(int value, int index, Vector* v) {
  if (v->size == v->capacity) {
    resizeVector(v);
  }
  int size = v->size;
  if (index < size) {
    for (int i = size-1; i >= index; i--) {
      int valueToMove = *(v->elements+i);
      *(v->elements+i+1) = valueToMove;
    }
  }
  *(v->elements+index) = value;
  v->size = v->size + 1;
}

// Resize vector
void resizeVector(Vector* v) {
  Vector newV;
  newV.size = v->size;
  newV.capacity = v->capacity * 2;
  newV.elements = malloc(sizeof(int) * newV.capacity);
  for(int i = 0; i < v->size-1; i++) {
    *(newV.elements + i) = *(v->elements + i);
  }
  v->capacity = newV.capacity;
  v->elements = newV.elements;
}


