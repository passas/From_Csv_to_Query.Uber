#include "Array.h"


#ifndef _USER_CATALOG_H_
#define _USER_CATALOG_H_


typedef Array UserCatalog;


Array *new_users_catalog (int initial_size);

void load_users_catalog (Array *);

struct user *get_user (Array, int pos);

int total_users_catalog (Array);

void free_users_catalog (Array *);


#endif