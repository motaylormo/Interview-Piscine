#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_item {
  char          *key;
  int           value;
  struct s_item *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

#include <unistd.h>// size_t

// DICTIONNARY
size_t        hash(char *input);
struct s_dict *dictInit(int capacity);
int           dictInsert(struct s_dict *dict, char *key, int value);
int           dictSearch(struct s_dict *dict, char *key);
// OTHER

char          *compress(char *book, struct s_dict *dict);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readBookFile(void);
void readWordsFile(char ***pWords, int *pLenWords);

char **split(char *str, char *delimiter);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
