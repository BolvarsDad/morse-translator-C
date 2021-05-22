#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "morse.h"

void
usage(void)
{
    puts("morsewrite - writes morse code");
    puts("Usage: morseread <msg>");
    exit(1);
}

int
main(int argc, char **argv)
{
    if(argc < 2)
        usage();

    for(char *argp = argv[1]; *argp; ++argp)
        printf("%s%s", morse_lookup_by_char(toupper(*argp)), (*argp == ' ') ? ("/ ") : (" ") );

    putchar('\n');
    return 0;
}
