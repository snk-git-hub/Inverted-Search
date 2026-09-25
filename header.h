#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node {
  char *arr;
  struct node *link;
} Flist;

// sub node
typedef struct sub_node {
  int wordCount;
  char *fileName;
  struct sub_node *link;
} Slist;
// Main node
typedef struct main_node {
  int fileCount;
  char *word;
  struct main_node *link;
  Slist *sublink;
} Mlist;
// Hash table
typedef struct hash_table {
  int index;
  Mlist *link;
} Hash_t;
#endif
int read_and_validation(int argc, char *argv[], Flist **head);
int insert_fileName(char *fileName, Flist **head);
int create_db(Flist *head, Hash_t *hashTable);