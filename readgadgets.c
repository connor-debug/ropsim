#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define MAXBUFLEN 1000000

char *g[256];
char source[MAXBUFLEN + 1];
int total;

int toArrayGadget(){ // this is attaching all of the instructions to an array, then finding the amount of them
    int i = 0;
    char *p = strtok(source, ";");

    while (p != NULL)
    {
        g[i++] = p;
        p = strtok (NULL, ";");
    }

    for (i = 0; g[i] != NULL; ++i){ //count the gadgets
       // printf("%s\n", g[i]);
        total++;
    }
    return 0;
}

int toBuff(){ // lets read the file into a buffer
    FILE *fp = fopen("gadget.txt", "r");
    if (fp != NULL) {
        size_t newLen = fread(source, sizeof(char), MAXBUFLEN, fp);
        if ( ferror( fp ) != 0 ) {
            fputs("Error reading file", stderr);
        }   else {
            source[newLen++] = '\0'; // for safety
        }
        fclose(fp);
    }
    return 0;
}

void removeChar(char *s) { //pointer magic, take away those newlines and tabs, also get rid of spaces
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\n' && *s != '\t') {
            *p2++ = *s++;
        } else if (*s = '\n'){
            *p2 = ' ';
        } else{
        ++s;
        }
    }
    *p2 = '\0';
}

void printBuff(){
    printf("%s", source);
    printf("the number of gadgets: %d", total);
}


