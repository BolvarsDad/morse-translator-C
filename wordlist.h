#ifndef WORDLIST_H
#define WORDLIST_H

struct word {
    char *text;
    struct word *next;
};

struct wordlist {
    struct word *head;
    struct word *tail;
};

struct word * wordlist_begin  (void);
void          wordlist_free   (void);
void          wordlist_push   (char *buffer, size_t len);

#endif
