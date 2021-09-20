#define WALL -1
#define BLANK -2
#include <stdio.h>
#include <stdbool.h>

int len;
int H, W;
int grid[100][100];

int find_path(int ax, int ay, int bx, int by){
    if (grid[ay][ax] == WALL || grid[by][bx] == WALL)
        return -1;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int d, x, y, k;
    bool stop;

    d = 0;
    grid[ay][ax] = 0;
    do {
        stop = true;
        for (y = 0; y < H; y++)
            for (x = 0; x < W; x++)
                if (grid[y][x] == d){
                    for (k = 0; k < 4; k++){
                        int iy = y + dy[k];
                        int ix = x + dx[k];
                        if (iy >= 0 && iy < H && ix >= 0 && ix < W && grid[iy][ix] == BLANK){
                            stop = false;
                            grid[iy][ix] = d + 1;
                        }
                    }
                }
        d++;
    } while (!stop && grid[by][bx] == BLANK);

    if (grid[by][bx] == BLANK)
        return -1;

    len = grid[by][bx];
    return len;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d\n", &H, &W);

    int finish_j, finish_i, start_i, start_j;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char help;
            int what;
            scanf("%c", &help);
            if (help == 'S') {
                start_i = i;
                start_j = j;
            }
            else if (help == 'F') {
                finish_i = i;
                finish_j = j;
            }

            what = help == 'X' ? WALL : BLANK;
            grid[i][j] = what;
        }
        scanf("\n");
    }
    printf("%d", find_path(start_j, start_i, finish_j, finish_i));
    return 0;
}