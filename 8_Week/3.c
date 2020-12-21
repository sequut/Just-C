#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#pragma pack(push,1)
typedef struct file_s {
	char name[21];
	long long int size;
	unsigned char dir;
	long long int time_creat;
	long long int last_time_edit;
	unsigned char hid_or_no;
}file;
#pragma pack(pop)

int opr_bolsh(char* aa, char* bb) {
	for (int i = 0; i < 21; i++) {
		if (aa[i] > bb[i])
			return 1;
		else if (aa[i] < bb[i])
			return 0;
	}
	return 0;
}

void sort(file* aa, int n) {

	file hp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {


			if (opr_bolsh(aa[j].name, aa[j + 1].name) == 1) {
				hp = aa[j];
				aa[j] = aa[j + 1];
				aa[j + 1] = hp;
			}
		}
	}
}
int main() {
	

	//FILE* input = fopen("1.in", "rb");
	//FILE* output = fopen("2.out", "wb");

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	int n;
	long long int a;
	long long int b;

	fread(&n, sizeof(int), 1, input);
	fread(&a, sizeof(long long int), 1, input);
	fread(&b, sizeof(long long int), 1, input);

	file* aa = (file*)calloc((n), sizeof(file));

	if (aa == 0)
		return 0;

	file bb;

	int cur_in_aa = 0;

	for (int i = 0; i < n; i++) {
		
		fread(&bb, sizeof(file), 1, input);

		if ((bb.dir != 1) && (a <= bb.time_creat) && (bb.hid_or_no != 1) && (b >= bb.last_time_edit)) {
			aa[cur_in_aa] = bb;
			cur_in_aa += 1;
		}
	}

	sort(aa, cur_in_aa);

	for (int i = 0; i < cur_in_aa; i++)
		fwrite(&aa[i], sizeof(file), 1, output);


	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
