#pragma comment(linker, "/STACK:50000000" )

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tek = 0;
char token[20];
char where[1000000];

double Monome();
double Parse();
double Atom();

int findchar(char what, char* where) {
    int pos = 0;
    while (where[pos]){
        if (what == where[pos])
            return 1;
        pos += 1;
    }
    return 0;
}

int vazhno(char a){
    char* help = "/*()-+";
    for (int i = 0; i < strlen(help); i+=1)
        if (a==help[i])
            return 1;
    return 0;
}

char* findnext() {
    while (isspace(where[tek]))
        tek++;

    if (where[tek] == 0 || where[tek] == '\n') {
        token[0] = 0;
        return token;
    }

    if (vazhno(where[tek])) {
        token[0] = where[tek];
        tek += 1;
        token[1] = 0;
        return token;
    }

    int nach = tek;
    while (isdigit(where[tek]))
        tek++;

    strncpy(token, where + nach, tek - nach);
    token[tek - nach] = 0;
    return token;
}

char* Token() {
    int nach = tek;
    findnext();
    tek = nach;
    return token;
}

double Monome() {
    double atom = Atom();
    while (findchar(*(Token()), "/*")) {
        char what = *(findnext());
        double next = Atom();
        if (what == '*')
            atom = atom * next;
        else if (what == '/')
            atom = atom / next;
    }
    return atom;
}

double Parse() {
    int sign = 1;
    if (*(Token()) == '-') {
        findnext();
        sign = -1;
    }
    double res = Monome();
    res *= sign;
    while (findchar(*(Token()), "+-")) {
        char oper = *(findnext());
        double next = Monome();
        if (oper == '+')
            res += next;
        else if (oper == '-')
            res -= next;
    }
    return res;
}

double Atom() {
    if (*(Token()) == '(') {
        findnext();
        double x = Parse();
        findnext();
        return x;
    }
    return atoi(findnext());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(where);
    printf("%.20lf", Parse());
    return 0;
}