#define MAXBUFLEN
#include <stdio.h>
extern char *g[256];
extern char source[MAXBUFLEN + 1];
extern int total;
char oper [16];

void memOper(char * arg){ // now compare to all of the words pop push return etc....
    if(strcmp(oper,"pop")){
    // pop arg
    }
  if(strcmp(oper,"push")){
    // push arg
    }
}

void showGadgets(){
    printf("Retrieving Gadgets:\n");
    int i = 0;
    for (i = 0; g[i] != NULL; ++i){
        printf("G%d:%s\n",i, g[i]);
    }
}

void doToken(char * token){
    if(strcmp(token,"pop")){ // need to get the argument
    //save operation pop
    strncpy(oper, "pop",5);
    }
    if(strcmp(token,"push")){
    //push the stack
    strncpy(oper, "push",5);
    }
    if(strcmp(token,"return")){ // no operation required, this is the end of the gadget
    memset(&oper[0], 0, sizeof(oper));
    }
    else{
        if (oper != NULL){
            memOper(token);// do the function stored in oper with the new value here
        }

        else {
            printf("Invalid syntax for a gadget.");
        }

    }
}

char * execGadget(char * gadget){
    char * p = strtok(gadget, " ");
    while (p != NULL)
    {
        printf("%s ",p); //this is where we are looking for the x86 language words. We will use a function to check if it is a viable instruction
        doToken(p);
        p = strtok (NULL, " ");
    }
    return p;

}

int doInstr(){

    execGadget(g[3]);

    return 0;
}



