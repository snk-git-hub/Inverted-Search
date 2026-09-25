#include "header.h"
int main(int argc, char *argv) {
  Flist *head = NULL;
  // hash table
  Hash_t ht[27];
  // initialize hash table
  for (int i = 0; i < 27; i++) {
    ht[i].index = i;
    ht[i].link = NULL;
  }

  if (read_and_validation(argc, argv, &head) == EXIT_SUCCESS) {
    printf("read and vaaalidation is successful!");
    int choice;
    printf("1.Create Database\n");
    printf("2.Display Database\n");
    printf("3.Search Database\n");
    printf("4.Update Database\n");
    printf("5.Save Database\n");
    printf("6.Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      /*Create db*/
      break;
    case 2:
      /*Display db*/
      break;
    case 3:
      /*Search db*/
      break;
    case 4:
      /*Update db*/
      break;
    case 5:
      /*Save db*/
      break;
    case 6:
      /*Exit*/
      return 0;
    default:
      printf("Invalid choice!");
    }

  } else {
    printf("Error: read and validation is not compleated!");
  }
  return 0;
}