#include "header.h"

int read_and_validation(int argc, char *argv[], Flist **head) {
  for (int i = 1; i < argc; i++) {
    char *extn = strrchr(argv[i], '.');
    if (extn != NULL && strcmp(extn, ".txt") == 0) {
      printf("%s is valid txt file", argv[i]);
      FILE *fptr = fopen(argv[i], "r");
      if (fptr != NULL) {
        fseek(fptr, 0, SEEK_END);
        if (ftell(fptr)) {
          if (insert_last(i, head, argv) == SUCCESS) {
            printf("%s file sucessfully inserted in flist \n", argv[i]);
          } else {
            printf("%s file is not inserted in flist \n", argv[i]);
          }
        }
      } else {
      }

    } else {
      printf("%s is not .txt file\n", argv[i]);
    }
  }
}

int create_db(Flist *head, Hash_t *hashTable) { return 0; }

int insert_fileName(char *fileName, Flist **head) {
  Flist *newNode = malloc(sizeof(Flist));
  newNode->arr = malloc(strlen(fileName) + 1);

  if (*head == NULL) {
    *head = newNode;
  }
}