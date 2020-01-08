#include "header.h"
#include <string.h>//	strcmp, strlen
#include <stdlib.h>//	malloc

#define INDEX(key)	(hash(key) % dict->capacity)

/*------------------------
	return hash result
--------------------------*/
size_t	hash(char *input)
{
	size_t	h = 0xcbf29ce484222325;
	for (int i = 0; input[i]; ++i)
	{
		h *= 0x100000001b3;
		h ^= input[i];
	}
	return (h);
}

/*-----------------------------------------------------------------------------
	initialize the dictionnary, given as parameter the capacity of the array.
-------------------------------------------------------------------------------*/
struct s_dict	*dictInit(int capacity)
{
	struct s_dict *dict = malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = malloc(sizeof(struct s_item*) * capacity);
	for (int i = 0; i < capacity; ++i)
		dict->items[i] = NULL;
	return (dict);
}

/*----------------------------------------------------------------------
	add one item in the dictionnary, if FAIL return 0, otherwise 1
------------------------------------------------------------------------*/
static struct s_item *createItem(char *key, int value)
{
	struct s_item *new = malloc(sizeof(struct s_item));
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

static void addToList(struct s_item *head, struct s_item *new)
{
	while (head->next)
		head = head->next;
	head->next = new;
}

int		dictInsert(struct s_dict *dict, char *key, int value)
{
	if (!key)
		return (0);
	struct s_item *new = createItem(key, value);
	int hash_index = INDEX(key);
	if (dict->items[hash_index])
		addToList(dict->items[hash_index], new);
	else
		dict->items[hash_index] = new;
	return (1);
}

/*-------------------------------------------------------------------
	find one element in the dictionnary, if not found, return -1
---------------------------------------------------------------------*/
int		dictSearch(struct s_dict *dict, char *key)
{
	int	index = INDEX(key);
	struct s_item *item = dict->items[index];
	while (item)
	{
		if (strcmp(key, item->key) == 0)
			return (item->value);
		item = item->next;
	}
	return (-1);
}

/*------------
	compress
--------------*/
/*
static int	howManyJesus(char *haystack, char *needle)
{
	if (!(haystack && needle))
		return (0);

	int	tally = 0;
	int	needle_len = strlen(needle);
	while ((haystack = strchr(haystack, needle[0])))
	{
		if (strncmp(haystack, needle, needle_len) == 0)
		{
			tally++;
			haystack += needle_len;
		}
		else
			haystack++;
	}
	return (tally);
}*/

char	*compress(char *book, struct s_dict *dict)
{
	int len = strlen(book);
//	for (int i = 0; i < dict->capacity; ++i)
//	{
//		len -= howManyJesus(book, dict->items[i]->key) * (strlen(dict->items[i]->key) - 2);
//	}
	char *new = malloc(len + 1);
	bzero(new, len + 1);
//	new[len] = '\0';
	int ni = 0;
	char **book_by_words = split(book, " ");
	int ret = 0;
	for (int i = 0; book_by_words[i]; ++i)
	{
		ret = dictSearch(dict, book_by_words[i]);
		if (ret == -1)
		{
			strcpy(new + ni, book_by_words[i]);
			ni += strlen(book_by_words[i]);
		}
		else
		{
			new[ni] = '@';
			new[ni + 1] = (char)ret;
			ni += 2;
		}
		new[ni++] = ' ';
	}
	return (new);
}
