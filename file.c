#include <string.h>

#include "file.h"
#include "wordlist.h"

ssize_t
token_get_length(FILE *fp)
{
    long pos = ftell(fp);
    int ch;
    ssize_t out = 0;

    while((ch = fgetc(fp)) != EOF && strchr(".-", ch) != NULL)
        ++out;

    fseek(fp, pos, SEEK_SET);

    if(out > 5)
        return 0;

    if(ch == EOF)
        return -1;

    return out;
}

void
token_seek(FILE *fp)
{
    int ch;

    while((ch = fgetc(fp)) != EOF && strchr(".-", ch) == NULL)
        ;

    ungetc(ch, fp);
}

int
read_file(char *fname)
{
    char buffer[5];
    FILE *fp;
    ssize_t nread;
    ssize_t nexpect;

    if(fname == NULL || (fp = fopen(fname, "r")) == NULL)
        return 0;

    while(token_seek(fp), (nexpect = token_get_length(fp)) > 0){
        if((nread = fread(buffer, 1, nexpect, fp)) != nexpect)
            break;

        wordlist_push(buffer, nread);
    }

    fclose(fp);
    return 1;
}
