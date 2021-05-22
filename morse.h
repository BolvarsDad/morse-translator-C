#ifndef MORSE_H
#define MORSE_H

#include <stddef.h>

struct morse_map {
    char    ch;
    char *  morse;
    size_t  len;
    int     end;
};

char    morse_lookup_by_morse  (char *);
char *  morse_lookup_by_char   (char);

#endif
