#ifndef LIST_H
#define lIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int val;
	struct list *next;
} List;

static List *list_new(int val);
void list_add(List **list, int val);
void list_node_del(List **list, int val);
void list_free(List *list);

#endif
