#include "Array.h"

#include <stdlib.h>


// Further encapsulation


Array *new_array (int capacity)
{
    Array *array;
    
    // Array alloc
    array = NULL;
    array = (struct array *) malloc (sizeof (struct array));
    
    if ( array )
    {
        // Array init
        array->i = 0;
        array->capacity = capacity;

        // Array storage
        array->data = (void *) malloc (sizeof (void *) * capacity);
        // to-do: error handling
    }
    // to-do: error handling

    return array;
}

void add_array (Array *array, void *data)
{
    // Array is full
    if (array->i == array->capacity)
    {
        void **tmp;

        // Realloc
        tmp = NULL;
        tmp = (void *) reallocarray ( array->data, array->capacity*2, sizeof (void *) );

        if ( tmp )
        {
            array->capacity <<= 1; // capacity * 2
            array->data = tmp;
        }
        //to-do: error handling
    }

    if (array->i < array->capacity) // Safe-guard
    {
        // Add element
        array->data [ array->i ] = data;
        // Update current index
        array->i++;
    }
}

void *get_array (Array a, int pos)
{
    if (pos < a.i)
        return ( a.data[pos] );
    else
        return NULL;
}

int length_array (Array a)
{
    return ( a.i );
}

void free_array (Array *a)
{
    if ( a )
    {
        // Array storage
        free (a->data);
        // Array
        free ( a );
    }
}
