#include <stdio.h>
#include <stdlib.h>

#include "wordlist.h"
#include "file.h"
#include "morse.h"

void
usage(void)
{
    puts("morseread - reads morse code");
    puts("Usage: morseread <file>");
    exit(1);
}

int
main(int argc, char **argv)
{
    if(argc < 2)
        usage();

    if(!read_file(argv[1]))
        return 1;

    for(struct word *selword = wordlist_begin(); selword != NULL; selword = selword->next)
        printf("%c", morse_lookup_by_morse(selword->text));

    putchar('\n');
    wordlist_free();
    return 0;
}
