#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct Label_s {
	char name[16];
	int age;
} Label;

typedef struct NameStats_s {
	int cntTotal;
	int cntLong;
} NameStats;

typedef struct AgeStats_s {
	int cntTotal;
	int cntAdults;
	int cntKids;
} AgeStats;

//////////////////////////////////////
//////////////////////////////////////

int proverka(char* s) {
	return 1 ? ((s[0] == 'l') && (s[1] == 'e') && (s[2] == 't')) : 0;
}

void calcStats(const Label* aa, int cnt, NameStats* oNames, AgeStats* oAges) {

	for (int i = 0; i < cnt; i++) {
		if (aa[i].age >= 18)
			oAges->cntAdults += 1;
		else if (aa[i].age < 14)
			oAges->cntKids += 1;
		
		if (strlen(aa[i].name) > 10)
			oNames->cntLong += 1;

		oNames->cntTotal += 1;
		oAges->cntTotal += 1;

	}
}

void vvod(const Label* aa, char* s, int i) {
	scanf("%s %d %s", &aa[i].name, &aa[i].age, s);
}

void vivod(NameStats* oNames, AgeStats* oAges) {
	printf("names: total = %d\n", oNames->cntTotal);
	printf("names: long = %d\n", oNames->cntLong);

	printf("ages: total = %d\n", oAges->cntTotal);
	printf("ages: adult = %d\n", oAges->cntAdults);
	printf("ages: kid = %d\n", oAges->cntKids);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	char str[80];
	char s[4];
	NameStats Name = { 0 };
	AgeStats Age = { 0 };

	scanf("%d\n", &n);

	Label* aa = (Label*)malloc(n * sizeof(Label));
        if (aa==0){
            printf(":((");
            return 0;
        }

	for (int i = 0; i < n; i++){
		vvod(aa, s, i);
		if (proverka(s) == 0)
			break;
	}

	if (proverka(s) == 0) {
		printf("problems s vvodom :((");
free(aa);
		return 0;
	}

	calcStats(aa, n, &Name, &Age);

	vivod(&Name, &Age);
        free(aa);
	return 0;
}
