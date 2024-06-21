#include "user_catalog.h"
#include "user.h"

#include <stdlib.h>
#include <stdio.h>


//gcc -o main csv.c user.c user_catalog.c Array.c main.c -g -Og -std=gnu99

//valgrind ./main


main ()
{
    Array *users_catalog;

    // Users catalog alloc
    users_catalog = NULL;
    users_catalog = new_users_catalog ( 1000 );

    // Load users catalog
    load_users_catalog ( users_catalog );

    if (users_catalog)
    {

        // Per each user on catalog...
        for ( int i=0; i < total_users_catalog (*users_catalog); i++)
        {
            struct user *u;
        
            // Get user
            u = get_user (*users_catalog, i);
        
            // Print user
            printf_csv_user ( *u );
            
            // Free user
            free_user ( u );
        }
        
        // Free catalog
        free_users_catalog ( users_catalog );
    }
}