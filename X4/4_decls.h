#ifndef AAA_DECLS_H
#define AAA_DECLS_H

#ifdef DLL_BUILD
#define SUFF __declspec(dllexport)
#else
#define SUFF
#endif

SUFF void echo_0(State* state);
SUFF void echo_1(State* state, char* arg0);
SUFF void echo_2(State* state, char* arg0, char* arg1);
SUFF void echo_3(State* state, char* arg0, char* arg1, char* arg2);
SUFF void print_1(State* state, char* idx);
SUFF void printregs_0(State* state);
SUFF void store_2(State* state, char* idx, char* what);
SUFF void copy_2(State* state, char* dst, char* src);
SUFF void clear_1(State* state, char* idx);

#endif //AAA_DECLS_H