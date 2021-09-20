#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct State{
    char* regs[256];
} State;
#include "decls.h"
void echo_0(State* state) {
    printf("ECHO: \n");
}
void echo_1(State* state, char* arg0) {
    printf("ECHO: %s\n", arg0);
}
void echo_2(State* state, char* arg0, char* arg1) {
    printf("ECHO: %s|%s\n", arg0, arg1);
}
void echo_3(State* state, char* arg0, char* arg1, char* arg2) {
    printf("ECHO: %s|%s|%s\n", arg0, arg1, arg2);
}
void print_1(State* state, char* idx){
    printf("%s\n", state->regs[atoi(idx)]);
}
void printregs_0(State* state){
    for (int i = 0; i<256; i++)
        if (state->regs[i])
            printf("%d = %s\n", i, state->regs[i]);
}
void store_2(State* state, char* idx, char* what){
    char* help = calloc(strlen(what) + 1, sizeof(char));
    free(state->regs[atoi(idx)]);
    strcpy(help, what);
    state->regs[atoi(idx)] = help;
}
void copy_2(State* state, char* dst, char* src){
    store_2(state, dst, state->regs[atoi(src)]);
}
void clear_1(State* state, char* idx){
    free(state->regs[atoi(idx)]);
    state->regs[atoi(idx)] = NULL;
}