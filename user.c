#include "user.h"

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>


// Future encapsulation


struct user *new_user ( char username[],
                        char name[],
                        char gender[],
                        char birth_date[],
                        char account_creation[],
                        char pay_method[],
                        char account_status[] 
)
{
    struct user *user;

    // User alloc
    user = NULL;
    user = (struct user *) malloc (sizeof (struct user));

    // User set
    if (user)
    {
        user->username         = strdup ( username );
        user->name             = strdup ( name );
        user->gender           = strdup ( gender );
        user->birth_date       = strdup ( birth_date );
        user->account_creation = strdup ( account_creation );
        user->pay_method       = strdup ( pay_method );
        user->account_status   = strdup ( account_status );

    }
    // to-do: error handling

    return user;
}

void printf_user (struct user u)
{
    printf ("%s %s %s %s %s %s %s \n", u.username,
                                        u.name,
                                        u.gender,
                                        u.birth_date,
                                        u.account_creation,
                                        u.pay_method,
                                        u.account_status
    );
}

void printf_csv_user (struct user u)
{
    printf ("%s;%s;%s;%s;%s;%s;%s\n", u.username,
                                        u.name,
                                        u.gender,
                                        u.birth_date,
                                        u.account_creation,
                                        u.pay_method,
                                        u.account_status
    );
}

void free_user (struct user *user)
{
    if ( user )
    {
        // User values
        free (user->username);
        free (user->name);
        free (user->gender);
        free (user->birth_date);
        free (user->account_creation);
        free (user->pay_method);
        free (user->account_status);

        // User
        free ( user );
    }
} 
