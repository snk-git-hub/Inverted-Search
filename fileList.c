/***************************************************************************************************************************************************
*Author		:Shivanandu.K
*Date		:
*File		:fileList.c
*Title		:File name linked list
*Description	:Keeps track of every document that has been handed to the program, either through the command line
			:argument or through the "Update DATABASE" menu option.
****************************************************************************************************************************************************/
#include "inverted_search.h"

/* returns 1 if fname is already present in the file linked list, 0 otherwise */
int is_file_registered(char *fname)
{
	FileNode *curr = fileListHead;

	while (curr != NULL)
	{
		if (strcmp(curr->fname, fname) == 0)
		{
			return 1;
		}
		curr = curr->next;
	}

	return 0;
}

/* appends fname to the end of the file linked list and announces it,
 * exactly the way the sample run does : "Successful: inserting file name : <fname> into file linked list" */
void insert_filename(char *fname)
{
	FileNode *node = (FileNode *) malloc(sizeof(FileNode));

	if (node == NULL)
	{
		printf("Error : memory allocation failed while inserting file name\n");
		return;
	}

	strncpy(node->fname, fname, MAX_FNAME_LEN - 1);
	node->fname[MAX_FNAME_LEN - 1] = '\0';
	node->indexed = 0;
	node->next = NULL;

	if (fileListHead == NULL)
	{
		fileListHead = node;
	}
	else
	{
		FileNode *curr = fileListHead;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = node;
	}

	printf("Successful: inserting file name : %s into file linked list\n", fname);
}
