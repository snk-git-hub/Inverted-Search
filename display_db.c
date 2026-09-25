#include "header.h"

int display_db(Hash_t *ht) {
  for (int i = 0; i < HASH_SIZE; i++) {
    Mlist *temp = ht[i].link;
    if (temp == NULL) {
      continue;
    }
    printf("Index %d:\n", i);
    while (temp != NULL) {
      printf("Word: %s, File Count: %d\n", temp->word, temp->fileCount);
      Slist *stemp = temp->sublink;
      while (stemp != NULL) {
        printf("  File Name: %s, Word Count: %d\n", stemp->fileName, stemp->wordCount);
        stemp = stemp->link;
      }
      temp = temp->link;
    }
  }
  return SUCCESS;
}