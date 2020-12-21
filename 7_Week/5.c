#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

void poisk(int* aa, int chto, int n) {
	int zap = -1;
	int up = n-1;
	int down = 0;
	int tek;
	int kod = 0;
	while (up != down) {
		tek = ((up - down) / 2) + down;

		if (aa[tek] <= chto)
			down = tek;
		//up = up;

		else
			up = tek;
		//down = down;

		if (up - down == 1) {
			if (aa[down] == chto) {
				printf("%d %d\n", down, 0);
				kod = 1;
				break;
			}
			else if (aa[up] == chto) {
				printf("%d %d\n", up, 0);
				kod = 1;
				break;
			}

			else {
				if ((aa[up] - chto) > (chto - aa[down])) {
					printf("%d %d\n", down, abs(aa[down] - chto));
					kod = 1;
					break;
				}
				else {
					printf("%d %d\n", up, abs(aa[up] - chto));
					kod = 1;
					break;
				}
			}
		}
	}
	if (kod==0)
		printf("%d %d\n", up, abs(aa[up] - chto));
}


int main() {

	int n;
	int q;
	int chto;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	int* aa = (int*)calloc((n), sizeof(n));
	if (aa == 0)
		return 0;

	for (int i = 0; i < n; i++)
		scanf("%d ", &aa[i]);

	scanf("\n%d", &q);

	for (int i = 0; i < q; i++) {
		scanf("%d\n", &chto);
		poisk(aa, chto, n);
	}

	free(aa);
	return 0;
}
