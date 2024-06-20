#ifndef _ARRAY_H_
#define _ARRAY_H_


typedef struct array
{
    int i; //current index
    int capacity;
    void **data;
} Array;


Array *new_array (int capacity);

void add_array (Array *, void *data);

void *get_array (Array, int pos);

int length_array (Array);

void free_array (Array *);


#endif
