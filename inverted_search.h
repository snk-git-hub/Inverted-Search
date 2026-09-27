/***************************************************************************************************************************************************
*Author		:Shivanandu.K
*Date		:
*File		:inverted_search.h
*Title		:Common header for the inverted search project
*Description	:Holds every struct, macro and function prototype shared between main.c, database.c, fileList.c and validate.c
****************************************************************************************************************************************************/
#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN   100
#define MAX_FNAME_LEN  100
#define TABLE_SIZE     128

/* ---- one entry per document that contains a given word ---- */
typedef struct FileEntry
{
	char fname[MAX_FNAME_LEN];
	int  count;
	struct FileEntry *next;
} FileEntry;

/* ---- one node per unique word that hashes into a bucket ---- */
typedef struct WordNode
{
	char word[MAX_WORD_LEN];
	int  file_count;
	FileEntry *files;
	struct WordNode *next;
} WordNode;

/* ---- linked list of the file names registered with the program ---- */
typedef struct FileNode
{
	char fname[MAX_FNAME_LEN];
	int  indexed;		/* 0 = not yet added to the database, 1 = already done */
	struct FileNode *next;
} FileNode;

/* the inverted index itself : an array of hash buckets */
extern WordNode *table[TABLE_SIZE];

/* the linked list that tracks every file name given to the program */
extern FileNode *fileListHead;

/* -------------------- fileList.c -------------------- */
void insert_filename(char *fname);
int  is_file_registered(char *fname);

/* -------------------- database.c -------------------- */
int  compute_hash(char *word);
void create_database(void);
void display_database(void);
void search_word(char *word);
void save_database(char *fname);

/* -------------------- validate.c -------------------- */
int  get_valid_choice(void);
char get_continue_choice(void);

#endif //INVERTED_SEARCH_H
