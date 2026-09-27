/***************************************************************************************************************************************************
*Author         :Shivanandu.K
*Date           :
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include "inverted_search.h"

/* first letter based hash used everywhere in this file :
 *   a..z / A..Z  -> 0..25
 *   anything else -> its own ASCII value (e.g. '?' -> 63)             */
int compute_hash(char *word)
{
	unsigned char c = (unsigned char) word[0];

	if (isalpha(c))
	{
		return tolower(c) - 'a';
	}

	return (int) c;
}

/* finds (or creates) the WordNode for "word" inside its hash bucket,
 * then records that it occurred once more inside file "fname"        */
static void add_word_occurrence(char *word, char *fname)
{
	int index = compute_hash(word);
	WordNode *wnode = table[index];
	WordNode *prevWnode = NULL;

	while (wnode != NULL)
	{
		if (strcmp(wnode->word, word) == 0)
		{
			break;
		}
		prevWnode = wnode;
		wnode = wnode->next;
	}

	if (wnode == NULL)
	{
		/* first time we ever see this word : create its node */
		wnode = (WordNode *) malloc(sizeof(WordNode));
		strncpy(wnode->word, word, MAX_WORD_LEN - 1);
		wnode->word[MAX_WORD_LEN - 1] = '\0';
		wnode->file_count = 0;
		wnode->files = NULL;
		wnode->next = NULL;

		if (prevWnode == NULL)
		{
			table[index] = wnode;
		}
		else
		{
			prevWnode->next = wnode;
		}
	}

	/* now look for fname inside this word's file list */
	FileEntry *fnode = wnode->files;
	FileEntry *prevFnode = NULL;

	while (fnode != NULL)
	{
		if (strcmp(fnode->fname, fname) == 0)
		{
			break;
		}
		prevFnode = fnode;
		fnode = fnode->next;
	}

	if (fnode == NULL)
	{
		/* word seen for the first time in this particular file */
		fnode = (FileEntry *) malloc(sizeof(FileEntry));
		strncpy(fnode->fname, fname, MAX_FNAME_LEN - 1);
		fnode->fname[MAX_FNAME_LEN - 1] = '\0';
		fnode->count = 1;
		fnode->next = NULL;

		if (prevFnode == NULL)
		{
			wnode->files = fnode;
		}
		else
		{
			prevFnode->next = fnode;
		}

		wnode->file_count++;
	}
	else
	{
		fnode->count++;
	}
}

/* goes through the file linked list and indexes every file that has
 * not been added to the database yet - used both by "Create DATABASE"
 * and by "Update DATABASE"                                            */
void create_database(void)
{
	FileNode *node = fileListHead;
	char word[MAX_WORD_LEN];
	FILE *fp;

	while (node != NULL)
	{
		if (!node->indexed)
		{
			fp = fopen(node->fname, "r");
			if (fp == NULL)
			{
				printf("Error : unable to open file %s\n", node->fname);
				node = node->next;
				continue;
			}

			while (fscanf(fp, "%99s", word) == 1)
			{
				add_word_occurrence(word, node->fname);
			}

			fclose(fp);
			node->indexed = 1;

			printf("Successful : Creation of DATABASE for file: %s\n", node->fname);
		}

		node = node->next;
	}
}

/* prints every bucket, in index order, and every word inside it, in
 * the order the words were first met - matches the sample run exactly */
void display_database(void)
{
	int i;

	printf("[index]\t[word]\tfile_count file/s\tFile : File_name word_count\n\n");

	for (i = 0; i < TABLE_SIZE; i++)
	{
		WordNode *wnode = table[i];

		while (wnode != NULL)
		{
			printf("[%d]\t[ %s ]  %d file/s: ", i, wnode->word, wnode->file_count);

			FileEntry *fnode = wnode->files;
			while (fnode != NULL)
			{
				printf("File : %s %d ", fnode->fname, fnode->count);
				fnode = fnode->next;
			}
			printf("\n");

			wnode = wnode->next;
		}
	}
}

/* looks up a single word (case sensitive, same as the way it was stored)
 * and reports which files contain it and how many times                */
void search_word(char *word)
{
	int index = compute_hash(word);
	WordNode *wnode = table[index];

	while (wnode != NULL)
	{
		if (strcmp(wnode->word, word) == 0)
		{
			break;
		}
		wnode = wnode->next;
	}

	if (wnode == NULL)
	{
		printf("Word %s is not present in the database\n", word);
		return;
	}

	printf("Word %s is present in %d file/s\n", word, wnode->file_count);

	FileEntry *fnode = wnode->files;
	while (fnode != NULL)
	{
		printf("In file: %s %d time/s\n", fnode->fname, fnode->count);
		fnode = fnode->next;
	}
}

/* dumps the whole hash table to a text file so it can be reloaded later :
 *   #:<index>
 *   <word>:<file_count>:<fname>:<count>:...:#
 * one such block per non empty bucket, exactly like backup.txt           */
void save_database(char *fname)
{
	FILE *fp = fopen(fname, "w");
	int i;

	if (fp == NULL)
	{
		printf("Error : unable to open file %s\n", fname);
		return;
	}

	for (i = 0; i < TABLE_SIZE; i++)
	{
		WordNode *wnode = table[i];

		if (wnode == NULL)
		{
			continue;
		}

		fprintf(fp, "#:%d\n", i);

		while (wnode != NULL)
		{
			fprintf(fp, "%s:%d:", wnode->word, wnode->file_count);

			FileEntry *fnode = wnode->files;
			while (fnode != NULL)
			{
				fprintf(fp, "%s:%d:", fnode->fname, fnode->count);
				fnode = fnode->next;
			}
			fprintf(fp, "#\n");

			wnode = wnode->next;
		}
	}

	fclose(fp);
	printf("Database is saved\n");
}
