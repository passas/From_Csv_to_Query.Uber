#include "csv.h"
#include "user.h"
#include "Array.h"
#include "user_catalog.h"

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define USERS_CSV "users.csv"
#define USERS_DELIM ";"
#define USERS_COLUMNS 7

static char *COLUMNS_REGEX[USERS_COLUMNS] = { 
                                              "^.+$", //username

                                              "^.+$", //name

                                              "^[fFmM]$", //gender

                                              "^[0-9]{2}/[0-9]{2}/[0-9]{4}$", //birth

                                              "^[0-9]{2}/[0-9]{2}/[0-9]{4}$", //account creation

                                              "^.+$", //pay method

                                              "^active|inactive$" //account state
                                          };


// Further encapsulation


Array *new_users_catalog (int initial_size)
{
    Array *users;

    users = NULL;
    users = new_array (initial_size);

    return users;
}

void load_users_catalog (Array *users)
{   
    // Parser
    struct buffer_csv *buffer;

    // Set parser
    buffer = new_buffer_csv (USERS_CSV, USERS_COLUMNS, COLUMNS_REGEX, USERS_DELIM);
    init_buffer_csv (buffer);

    // Parse activity
    int total_tokens;
    while ( (total_tokens = tokenize_csv_line (buffer)) != -1 ) // !EoF
    {
        if (total_tokens!=USERS_COLUMNS)
        {
            //to-do: error-handling
        }
        else
        {
            struct user *user;

            // Create user
            user = new_user ( buffer->line_token[0], //char[]
                            buffer->line_token[1], //char[]
                            buffer->line_token[2], //char[]
                            buffer->line_token[3], //char[]
                            buffer->line_token[4], //char[]
                            buffer->line_token[5], //char[]
                            buffer->line_token[6]  //char[]
                        );

            // Collect user
            add_array (users, (void *)user);
        }

    } end_buffer_csv ( buffer );
    free_buffer_csv ( buffer );

}

struct user *get_user (Array users, int pos)
{
    struct user *u;

    if (pos < length_array (users))
        u = (struct user *) get_array (users, pos);
    else
        u = NULL;

    return ( u );
}

int total_users_catalog (Array users)
{
    return length_array (users);    
}

void free_users_catalog (Array *us)
{
    if (us)
        free_array (us);
}
