/***************************************************************************************************************************************************
*Author		:Shivanandu.K
*Date		:
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"

/* definitions of the globals declared as extern in the header */
WordNode *table[TABLE_SIZE];
FileNode *fileListHead = NULL;

static void display_menu(void)
{
	printf("Select your choice among following options:\n");
	printf("1. Create DATABASE\n");
	printf("2. Display Database\n");
	printf("3. Update DATABASE\n");
	printf("4. Search\n");
	printf("5. Save Database\n");
	printf("Enter your choice\n");
}

int main(int argc, char *argv[])
{
	int choice;
	char fname[MAX_FNAME_LEN];
	char word[MAX_WORD_LEN];

	if (argc < 2)
	{
		printf("Usage: %s <file name>\n", argv[0]);
		return 1;
	}

	/* the very first file given on the command line is inserted into the
	 * file linked list, exactly like every later "Update DATABASE" does   */
	insert_filename(argv[1]);

	do
	{
		display_menu();
		choice = get_valid_choice();

		switch (choice)
		{
			case 1:
				/* indexes every file in the file linked list that has
				 * not been added to the database yet                  */
				create_database();
				break;

			case 2:
				display_database();
				break;

			case 3:
				printf("Enter the file name to update data:");
				scanf("%99s", fname);
				insert_filename(fname);
				create_database();
				break;

			case 4:
				printf("Enter the word you want to search: ");
				scanf("%99s", word);
				search_word(word);
				break;

			case 5:
				printf("Enter the file name to save database: ");
				scanf("%99s", fname);
				save_database(fname);
				break;

			default:
				break;
		}

		printf("\nDo you want to continue ?\n");
		printf("Enter y/Y to continue and n/N to discontinue\n");

	} while (get_continue_choice() != 'n');

	return 0;
}
