#ifndef FILE_H
#define FILE_H

#include <stdio.h>

ssize_t  token_get_length(FILE *);
void     token_seek(FILE *);
int      read_file(char *fname);

#endif
