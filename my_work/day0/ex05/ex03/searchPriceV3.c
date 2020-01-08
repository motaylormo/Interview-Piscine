#include "header.h"
#include <string.h>//	strcmp
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
	add one element in the dictionnary, if FAIL return 0, otherwise 1
------------------------------------------------------------------------*/
static struct s_item *createItem(char *key, struct s_art *value)
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

int		dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	if (!(key && value))
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
	find one element in the dictionnary, if not found, return NULL
---------------------------------------------------------------------*/
struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	int	index = INDEX(key);
	struct s_item *item = dict->items[index];
	while (item)
	{
		if (strcmp(key, item->key) == 0)
			return (item->value);
		item = item->next;
	}
	return (NULL);
}
