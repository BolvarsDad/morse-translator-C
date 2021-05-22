#include <string.h>
#include <stdlib.h>

#include "wordlist.h"

static struct wordlist wlist;

struct word *
wordlist_begin(void)
{
    return wlist.head;
}

void
wordlist_free(void)
{
    struct word *selword = wlist.head;
    struct word *nxword;

    if(wlist.head == NULL)
        return;

    while(selword != NULL){
        nxword = selword->next;
        free(selword->text);
        free(selword);
        selword = nxword;
    }
}

void
wordlist_push(char *buffer, size_t len)
{
    struct word *nword = malloc(sizeof *nword);

    nword->text = strndup(buffer, len);
    nword->next = NULL;

    if(wlist.head == NULL){
        wlist.head = wlist.tail = nword;
    } else {
        wlist.tail->next = nword;
        wlist.tail = nword;
    }
}
