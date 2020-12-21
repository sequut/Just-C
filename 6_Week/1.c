#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

typedef struct sList{
	float value;
	int next;
} List;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int first;
	int n;
	
	scanf("%d %d\n", &n, &first);

	List* aa = (List*)calloc(n, sizeof(List));
	
	if (aa == 0)
		return 0;
	double a;

	for (int i = 0; i < n; i ++) {
		scanf("%f %d\n", &aa[i].value, &aa[i].next);
		//printf("%f %d\n", aa[i].value, aa[i].next);
	}
	

	int j = first;// будем двигаться с помощью j по списку

	while (aa[j].next != -1) {
		printf("%0.3lf\n", aa[j].value);
		j = aa[j].next;
	}
	printf("%0.3lf\n", aa[j].value);

	free(aa);

	return 0;
}
