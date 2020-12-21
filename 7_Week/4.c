#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int poisk(int* aa, int chto, int n) {
	int zap = -1;
	int up = n;
	int down = 0;
	int tek = (n-1) / 2;

	while (up != down) {

		tek = ((up - down) / 2) + down;

		if (aa[tek] <= chto) {
			down = tek;
			//up = up;
		}
		else {
			up = tek;
			//down = down;
		}
//		if ((aa[tek + 1] > chto) && (aa[tek - 1] < chto) && (aa[tek] != chto))
//			return -1;

		if (up - down == 1) {
			if (aa[up] == chto)
				return up;
			else if (aa[down] == chto)
				return down;
			else
				return -1;
		}

		//printf("%d %d %d %d\n", down, up, chto, aa[tek]);
	}
	return up;
}

int main() {

	int n;
	int q;
	int last_ind = 0;
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
		last_ind = poisk(aa, (chto+last_ind), n);

		printf("%d\n", last_ind);
	}
	free(aa);
	return 0;
}
