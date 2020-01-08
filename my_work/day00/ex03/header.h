#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct  s_art {
  char *name;
  int  price;
};

struct s_item {
  char           *key; //here the key will be the name
  struct s_art   *value;
  struct s_item  *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

#include <unistd.h>// size_t

size_t        hash(char *input);
struct s_dict *dictInit(int capacity);
int           dictInsert(struct s_dict *dict, char *key, struct s_art *value);
struct s_art  *dictSearch(struct s_dict *dict, char *key);

// OTHER

int searchPrice(struct s_dict *dict, char *name);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
