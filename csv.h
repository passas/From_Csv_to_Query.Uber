#include <stdio.h>
#include <regex.h>


#ifndef _CSV_H_
#define _CSV_H_


struct buffer_csv
{
    char from_file[75];

    // Read
    FILE *file_pointer;
    size_t line_length;
    char *line_content;
    
    // Handle
    char delim[2];
    int total_columns;
    regex_t *token_regex; //REG_EXTENDED | REG_ICASE
    
    // Suit
    char **line_token;
    int *flag_invalid_token;
};


struct buffer_csv *new_buffer_csv (char filename[], int columns, char *regex[], char delim[2]);

void init_buffer_csv (struct buffer_csv *);

int tokenize_csv_line (struct buffer_csv *);

void end_buffer_csv (struct buffer_csv *);

void free_buffer_csv (struct buffer_csv *);


#endif