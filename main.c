#include <stdio.h>
#define MAXBUFLEN 1000000
#define STACKLEN 64
extern char source[MAXBUFLEN + 1];
char eax[32], ebx[32], ecx[32], edx[32], esp[32], ebp[32]; // registers
struct Stack * stack;
int memory[256];

/*
    gadgets: show gadgets
    stack: show stack
    execute: execute stack
*/

char command [16];

int mainloop(){

     while(1){
        printf("\n(ropsim)");
        fflush(stdin);
        scanf("%s", &command);
        doCommand(command);
        memset(&command[0], 0, sizeof(command));
    }

}

int doCommand(char * command){

        if (strcmp(command,"stack",5)==0){
            printStack("test_value",7);
        }

        if (strcmp(command,"gadgets",7)==0){
            showGadgets();
        }

        if (strcmp(command,"quit",4)==0){
            printf("you quit");
        }

}

int main (int argc, char * argv[]){

stack = createStack(STACKLEN);

toBuff();
printf("Loading gadgets to buffer...\n"); // put input file in buffer
removeChar(source);
printf("Parsing Buffer...\n") ;//removing new lines and space filth from buffer
toArrayGadget();
printf("Assigning gadgets to array...\n"); // parse language, put every gadget in an array location
//showGadgets(); // show the gadgets that have been configured

//addMem(67,3);
//printMem();

mainloop();



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
