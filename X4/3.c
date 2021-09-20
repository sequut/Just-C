#include "sol.h"
#include <stdlib.h>

typedef struct Vertice_s{
    int number;
    Edge* ed;
} Vertice;

static int num;
static Vertice* answ = {0};

void push_vert(Edge what){
    if (!answ[what.from].ed)
        answ[what.from].ed = (Edge*)malloc(answ[what.from].number * sizeof(Edge));
    else
        answ[what.from].ed = (Edge*)realloc(answ[what.from].ed, answ[what.from].number * sizeof(Edge));
    answ[what.from].ed[answ[what.from].number - 1] = what;
}

void init() {
    num = getVerticesCount();
    answ = (Vertice*)calloc(num, sizeof(Vertice));

    Edge tek;
    int help;
    while(readEdge(&tek)){
        answ[tek.from].number += 1;
        push_vert(tek);

        answ[tek.to].number += 1;
        help = tek.to;
        tek.to = tek.from;
        tek.from = help;
        push_vert(tek);
    }
}

int getEdgesCount(int iVertex){
    return answ[iVertex].number;
}

Edge getIncidentEdge (int iVertex, int iIndex){
    return answ[iVertex].ed[iIndex];
}