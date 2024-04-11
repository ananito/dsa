#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
} LinkedList;

void InsertList(LinkedList *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    return;
  } else {
    Node *current = list->head;
    while (current->next != NULL) {

      current = current->next;
    }
    current->next = newNode;
    return;
  }
}

void DestroyList(LinkedList *list) {
  Node *current = list->head;
  Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);

    current = next;
  }
  free(list);
}
void PrintList(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
int main(void) {
  LinkedList *list = malloc(sizeof(LinkedList));
  for (int i = 1; i <= 100; i++) {
    InsertList(list, i);
  }
  PrintList(list);

  DestroyList(list);
  return 1;
}
