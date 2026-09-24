#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    char *arr;
    struct node *link;
}Flist;
#endif
