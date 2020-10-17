#include <stdio.h>
#define MAXBUFLEN 1000000

extern char source[MAXBUFLEN + 1];
char eax[32], ebx[32], ecx[32], edx[32], esp[32], ebp[32]; // registers

int main (int argc, char * argv[]){

toBuff(); // put input file in buffer
removeChar(source); //removing new lines and space filth from buffer

toArrayGadget(); // parse language, put every gadget in an array location

showGadgets(); // show the gadgets that have been configured



return 0;
}

void printStack(char * args, int n){ // simple graphical representation of a stack
    for(int i = 0; i < n; i++){
    printf("-------");
}
    printf("\n\n");

    printf("string entered: %s\n\n\n", args);

    for(int i = 0; i < n; i++){
    printf("-------");
}

    printf("\n");
    printf("eax: %s\nebx: %s\necx: %s\nedx: %s\nesp: %s\nebp: %s\n",eax,ebx,ecx,edx,esp,ebp);


}
