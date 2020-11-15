//the virtual memory sep from the stack
#include <stdio.h>
#include <stdlib.h>
#define MAXCAP 256

extern int memory[256];

int addrToInt(char * addr){
    char * p = addr;
    *p++; *p++;
    return atoi(p);
}

char * addrToString(int addr){ //need to look at this
    char str[16];
    char res[16];
    char * l = "0x";
    char * m = "0x0";
    char * s = "0x00";
    itoa(addr, str, 10);
    if (addr > 100){
        strcat(res,l);
        strcat(res,str);
    }
    if (addr <= 99 && addr >= 10){
        strcat(res,m);
        strcat(res,str);
    }

    if (addr < 10){
        strcat(res,s);
        strcat(res,str);
    }
     return str;

}

void clearMem(){
    memset(&memory[0], 0, sizeof(memory));
}

void printMem(){
    int i = 0;
    for (i = 0; i <= 256; i++){
        if(memory[i] != NULL)
            printf("%d at memory location: 0x%x", memory[i], i);
    }

}

void addMem(int val, int loc){
    memory[loc] = val;
}


