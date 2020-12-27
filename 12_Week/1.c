#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int k = 0;
int heap[SIZE];

void swap(int* a, int* b) {
	int help = *a;
	*a = *b;
	*b = help;
}

void Siftup(int* heap, int a) {
	if (heap[a] < heap[(a - 1) / 2] && (a - 1 >= 0)) {
		swap(&heap[a], &heap[(a - 1) / 2]);
		Siftup(heap, (a - 1) / 2);
	}
}

void SiftDown(int* heap, int a) {
	if ((2 * a + 2 >= k) && (2 * a + 1 == k-1)) {
		if (heap[a] > heap[2 * a + 1]) {
			swap(&heap[a], &heap[2 * a + 1]);
			SiftDown(heap, 2 * a + 1);
		}
	}
	else if (2 * a + 1 > k-1) {
		return;
	}
	else {
		int mi;
		int what = 1;
		if (heap[2 * a + 1] < heap[2 * a + 2]) {
			mi = heap[2 * a + 1];
			what = 0;
		}

		else
			mi = heap[2 * a + 2];

		if (heap[a] > mi) {
			if (what == 1) {
				swap(&heap[a], &heap[2 * a + 2]);
				SiftDown(heap, 2 * a + 2);
			}
			else {
				swap(&heap[a], &heap[2 * a + 1]);
				SiftDown(heap, 2 * a + 1);
			}
		}
	}
}

void add_heap(int* heap, int x) {
	heap[k] = x;
	k += 1;
	Siftup(heap, k - 1);
}

int Extract_min_heap(int* heap) {
	int res = heap[0];
	swap(&heap[0], &heap[k - 1]);
	k -= 1;
	SiftDown(heap, 0);
	return res;
	
}



int main() {

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	int n;
	fread(&n, sizeof(int), 1, input);

	int* aa = (int*)calloc(n, sizeof(int));

	if (aa == 0)
		exit(666);


	for (int i = 0; i < n; i++) {
		fread(&aa[i], sizeof(int), 1, input);
		add_heap(heap, aa[i]);
	}

	int answer;

	for (int i = 0; i < n; i++) {
		answer = Extract_min_heap(heap);
		fwrite(&answer, sizeof(int), 1, output);
	}


	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
