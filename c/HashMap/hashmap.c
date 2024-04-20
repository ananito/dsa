#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { CAPACITY = 21 };
typedef struct Node Node;
struct Node {
  char *key;
  int value;
  struct Node *next;
};
typedef struct HashMap HashMap;
struct HashMap {
  Node *data[CAPACITY];
};
/* Hashing Function could be better ig */
int hash(char *key) { return strnlen(key, 100) % CAPACITY; }

HashMap *create() {
  HashMap *map = malloc(sizeof(HashMap));
  if (map == NULL) {
    return NULL;
  }
  for (int i = 0; i < CAPACITY; i++) {
    map->data[i] = NULL;
    //   map->data[i] = (Node *)malloc(sizeof(Node));
    //   if (map->data[i] == NULL) {
    //     return NULL;
    //   }
    //   map->data[i]->key = NULL;
    //   map->data[i]->value = 0;
    //   map->data[i]->next = NULL;
  }
  return map;
}

void insert(char *key, int value, HashMap *hmap) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    err(EXIT_FAILURE, "Your memory is doomed");
  }
  // Populate the newNode Feed with the data
  newNode->key = (char *)malloc(sizeof(char) * strnlen(key, 100) + 1);
  strcpy(newNode->key, key);
  newNode->value = value;
  newNode->next = NULL;

  int hashid = hash(key);
  if (hmap->data[hashid] == NULL) {
    hmap->data[hashid] = newNode;
  } else {
    if (hmap->data[hashid]->next == NULL &&
        (strcmp(hmap->data[hashid]->key, key) == 0)) {
      hmap->data[hashid]->value = value;
      return;
    }
    Node *current = hmap->data[hashid];
    while (current->next != NULL) {
      if (strcmp(current->key, key) == 0) {
        current->value = value;
        return;
      }
      current = current->next;
    }
    current->next = newNode;
    return;
  }
  // printf("hashid = %d\n", hashid);
  // hmap->data[hashid]->key = (char *)malloc(sizeof(char *) * strnlen(key,
  // 100)); if (!hmap->data[hashid]->key) {
  //   err(EXIT_FAILURE, "Your memory is doomed");
  // }
  //
  // strcpy(hmap->data[hashid]->key, key);
  // printf(" hmap->data[hashid]->key = %s\n", hmap->data[hashid]->key);
  // // ASSIGIN VALUE
  // hmap->data[hashid]->value = value;
}

void print_list(HashMap *hmap) {
  for (int i = 0; i < CAPACITY; i++) {
    printf("Index Number: %d :", i);
    // Node *current = (Node *)malloc(sizeof(Node));
    // if (!current) {
    //   free(current);
    //   err(EXIT_FAILURE, "Your memory is doomed");
    // }
    Node *current = hmap->data[i];

    while (current != NULL) {
      printf("\"%s\": %d-> ", current->key, current->value);
      current = current->next;
    }
    printf("NULL\n");
  }
}

void search(char *key, HashMap *hmap) {
  int hashid = hash(key);
  // Node *current = (Node *)malloc(sizeof(Node));
  // if (!current) {
  //   free(current);
  //   err(EXIT_FAILURE, "Your memory is doomed");
  // }
  Node *current = hmap->data[hashid];
  while (current != NULL) {
    if (strncmp(current->key, key, 100) == 0) {
      printf("%d\n", current->value);
      return;
    }
    current = current->next;
  }
  printf("Not Found!\n");
}

void destroy(HashMap *hmap) {
  for (int i = 0; i < CAPACITY; i++) {
    Node *current = hmap->data[i];
    Node *next;
    while (current != NULL) {
      next = current->next;
      free(current->key);
      free(current);
      current = next;
    }
  }
  free(hmap);
}

int main(void) {
  HashMap *hmap = create();
  insert("Hello", 5, hmap);

  insert("Hella", 2, hmap);

  insert("Hell", 2, hmap);

  // printf("hmap->data[5]->value = %d\n", hmap->data[5]->value);
  // print_list(hmap);
  search("Hello", hmap);
  search("dhd", hmap);
  destroy(hmap);

  return EXIT_SUCCESS;
}
