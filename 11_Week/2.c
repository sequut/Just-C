#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct List_s {
	int head;
	int value;
	struct List_s* next;
}List;

typedef void (*callback)(void* ctx, int* value);

void something(void* ctx, int* value) {
	if (*value % 2 == 0)
		*(int*)ctx += *value;
}

void arrayForeach(void* ctx, callback func, int* arr, int n) {
	for (int i = 0; i < n; i++)
		func(ctx, &arr[i]);

	
}

void listForeach(void* ctx, callback func, List* aa, int n) {

	int i = aa[0].head;
	List* tek = &aa[aa[0].head];
	while ((*tek).next!=0) {
		func(ctx, &(*tek).value);
		tek = (*tek).next;
	}
	func(ctx, &(*tek).value);

	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);

	int* bb = (int*)calloc(n, sizeof(bb));
	List* aa = (List*)calloc(n, sizeof(List));
	if (bb == 0 || aa == 0)
		exit(666);

	int sum = 0;
	aa[0].head = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &bb[i]);
		if (i == n - 1) {
			aa[i].value = bb[i];
			aa[i].next = 0;
		}
		else {
			aa[i].value = bb[i];
			aa[i].next = &aa[i + 1];
		}
	}
	aa[n - 1].next = 0;
	
	arrayForeach(&sum, something, bb, n);
printf("%d ", sum);
	sum = 0;
	listForeach(&sum, something, aa, n);
printf("%d\n", sum);

	free(bb);
	free(aa);
	return 0;
}
