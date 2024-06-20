#ifndef _USER_H_
#define _USER_H_


struct user
{
    char *username;
    char *name;
    char *gender;
    char *birth_date;
    char *account_creation;
    char *pay_method;
    char *account_status;
};


struct user *new_user ( char username[],
                        char name[],
                        char gender[],
                        char birth_date[],
                        char account_creation[],
                        char pay_method[],
                        char account_status[]
                    );

void printf_user (struct user);

void free_user (struct user *);

#endif
