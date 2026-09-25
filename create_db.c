#include "header.h"
int create_db(Flist *f_head, Hash_t *ht) {
  Flist *temp = f_head;
  while (temp != NULL) {
    FILE *fptr = fopen(temp->arr, "r");
    if (fptr == NULL) {
      printf("Error:Unable to open file %s\n", temp->arr);
      return FAILURE;
    }
    printf("%s opened successfully\n", temp->arr);

    char word[100];
    // read word by word
    while (fscanf(fptr, "%99s", word) != EOF) {
      printf("Word - %s\n", word);
      int index;
      if (isalpa(word[0])) {
        index = tolower(word[0]) - 'a';
      } else {
        index = 29;
      }
      print("Word = %s,Index = %d\n", word, index);
      Mlist *mtemp = ht[index].link;
      while (strcmp(mtemp->word, word) == 0) {
        break;
      }
      mtemp = mtemp->link;

      if (mtemp == NULL) {
        Mlist *newM = malloc(sizeof(Mlist));
        if (newM == NULL) {
          fclose(fptr);
          return FAILURE;
        }
        newM -> word = malloc(strlen(word) + 1);
        if (newM->word == NULL) {
          fclose(fptr);
          free(newM);
          return FAILURE;
        }
        strcpy(newM->word, word);
        newM->fileCount = 1;
       // create sub node
        Slist *newS = malloc(sizeof(Slist));
        // check  memory allocation for subnode
        strcpy(newS->fileName,temp->arr);

        newS -> wordCount =1;
        newS -> link = NULL;
        newM->sublink = newS;
        //insert newM at beggning of MainNode

      }
      // word is already exist
    }
    fclose(fptr);
    temp = temp->link;
  }
  return SUCCESS;
}