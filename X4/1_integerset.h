#ifndef INTEGERSET_H
    #define INTEGERSET_H
    #ifdef _WIN32
        #ifdef DLL_BUILD
            #define SUFF __declspec(dllexport)
        #else
            #define SUFF
        #endif
    #else
        #define SUFF
    #endif

typedef struct IntegerSet_s {
    int length;
    int* arr;
}IntegerSet;

SUFF  IntegerSet *CreateSet(int* aa, int n);
SUFF  int IsInSet(IntegerSet* aa, int chto);

#endif