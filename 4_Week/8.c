#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int kolvo_ci(int a) {
    int n = 0;
    while (a > 0){
        n += 1;
        a/=10;
    }
    return n;
}

void format_ch(int id, int ma_id, int kol, int ma_kol, int dl, int ma_dl) {
    
    printf("| ");
    int n = kolvo_ci(id);
    
    for (int i = 0; i < ma_id-n; i++) 
        printf(" ");
    
    printf("%d ", id);
 
    
    
    printf("| ");
    n = kolvo_ci(kol);

    for (int i = 0; i < ma_kol - n; i++) 
        printf(" ");
    
    printf("%d ", kol);   
    

    printf("| ");
    n = kolvo_ci(dl);

    for (int i = 0; i < ma_dl - n; i++) 
        printf(" ");
        
    printf("%d |\n", dl);
   
    
}

void format_line(int ma_id, int ma_kol, int ma_dl) {
    
    printf("+");
    for (int i = 0; i < ma_id + 2; i++)
        printf("-");
    printf("+");

    for (int i = 0; i < ma_kol + 2; i++)
        printf("-");
    printf("+");

    for (int i = 0; i < ma_dl + 2; i++)
        printf("-");
    printf("+\n");

}


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    int dl_kus[1001] = { 0 };
    int kol_kus[1001] = { 0 };
    int id;
    int dl;

    int max_id = 0;
    int max_kol = 0;
    int max_dl = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &dl);
        
        dl_kus[id] += dl;
        kol_kus[id] += 1;
        
        if (kol_kus[id] > max_kol)
            max_kol = kol_kus[id];

        if (dl_kus[id] > max_dl)
            max_dl = dl_kus[id];

        if (id > max_id)
            max_id = id;
    }
    max_id = kolvo_ci(max_id);
    max_dl = kolvo_ci(max_dl);
    max_kol = kolvo_ci(max_kol);

    
    for (int i = 0; i < 1001; i++) {
        if (kol_kus[i] > 0) {
            format_line(max_id, max_kol, max_dl);
            format_ch(i, max_id, kol_kus[i], max_kol, dl_kus[i], max_dl);
        }
    }
    
    format_line(max_id, max_kol, max_dl);


    return 0;
}
