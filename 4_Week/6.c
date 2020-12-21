#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>
int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds) {

    int a;
    int Minutes;
    int Seconds;
    int Hours;
    int ret = 1;
    
    a = sscanf(iStr, "%d:%d:%d", &Hours, &Minutes, &Seconds);

    int i = 0;
    int uk = 0;
    while (iStr[i] != '\0') {
        if ((iStr[i] != ':') && (iStr[i] < '0' || iStr[i]>'9')) {
            uk = 1;
            break;
        }
        i += 1;
    }
    if (uk == 1) {
        ret = 0;
        //return 0;
    }

    if ((Hours >= 0 && Hours < 24) && (Minutes >= 0 && Minutes < 60) && a >= 2) {
        if ((a == 3) && (Seconds < 60 && Seconds >= 0)) {
            ret = 1;
            //return 1;
        }

        else if (a == 2) {
            Seconds = 0;
            ret = 1;
            //return 1;
        }
        else {
            ret = 0;
            Hours = -1;
            Minutes = -1;
            Seconds = -1;
            //return 0;
        }
    }
    else {
        ret = 0;
        Hours = -1;
        Minutes = -1;
        Seconds = -1;
        //return 0;
    }


    if ((oSeconds == NULL) && (oMinutes == NULL)){
        *oHours = Hours;
    }
         
        
     else if (oSeconds == NULL) {
         *oHours = Hours;
         *oMinutes = Minutes;
     }
    else{
        *oHours = Hours;
        *oMinutes = Minutes;
        *oSeconds = Seconds;
    }
    return ret;

}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h = 0;
    int m = 0;
    int s = 0;
    char* sost;
    char aa[100];
    int a;
    
    sost = gets(aa);
    a = readTime(aa, &h, &m, &s);
    printf("%d %d %d %d\n", a, h, m, s);
    a = readTime(aa, &h, &m, NULL);
    printf("%d %d %d\n", a, h, m);
    a = readTime(aa, &h, NULL, NULL);
    printf("%d %d\n", a, h);
    return 0;
}
