#define _CRT_SECURE_NO_WARNINGS
#define max_len 10000000
#define SIZE 8
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h> 

typedef unsigned char bitword;

void bitsetZero(bitword* arr, int num) {
	int int_part = num / SIZE;
	memset(arr, 0, int_part);

	arr[int_part] >>= num % SIZE;
	arr[int_part] <<= num % SIZE;
}

int bitsetGet(const bitword* arr, int idx) {
	int value = 1 << (idx % 8);

	return (value & arr[idx / SIZE]) ? 1 : 0;
}

void bitsetSet(bitword* arr, int idx, int newval) {
	int value = 1 << idx % SIZE;

	if (newval == 1) {
		if (!(bitsetGet(arr, idx)))
			arr[idx / SIZE] += value;
	}
	else
		if (bitsetGet(arr, idx))
			arr[idx / SIZE] -= value;
}

int bitsetAny(const bitword* arr, int left, int right) {
	int left_int_part = left / SIZE;
	int left_frac_part = left % SIZE;




	int right_int_part = right / SIZE;
	int right_frac_part = right % SIZE;

	if (right_int_part == left_int_part) {
		for (int i = left_frac_part + SIZE * left_int_part; i < SIZE * left_int_part + right_frac_part; i++)
			if (bitsetGet(arr, i))
				return 1;
		return 0;
	}

	if (left_frac_part > 0) {
		for (int i = left_frac_part + SIZE * left_int_part; i < SIZE*(left_int_part + 1); i++)
			if (bitsetGet(arr, i)) 
				return 1;
				
		left_int_part += 1;
	}

	for (int i = left_int_part; i < right_int_part; i++)
		if (arr[i] > 0) 
			return 1;

	for (int i = right_int_part * SIZE; i < right_frac_part + right_int_part * SIZE; i++)
		if (bitsetGet(arr, i)) 
			return 1;

	return 0;
}

bitword arr[max_len / SIZE] = { 0 };

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d\n", &n);

	int t;
	int idx;
	int num;
	int newval;
	int left;
	int right;

	for (int i = 0; i < n; i++) {
		scanf("%d ", &t);
		if (t == 0) {
			scanf("%d\n", &num);
			bitsetZero(arr, num);
		}
		else if (t == 1) {
			scanf("%d\n", &idx);
			printf("%d\n", bitsetGet(arr, idx));
		}
		else if (t == 2) {
			scanf("%d %d\n", &idx, &newval);
			bitsetSet(arr, idx, newval);
		}
		else {
			scanf("%d %d\n", &left, &right);
			if (bitsetAny(arr, left, right))
				printf("some\n");
			else
				printf("none\n");
		}
	}
	return 0;
}
