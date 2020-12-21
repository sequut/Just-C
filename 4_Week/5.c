#define _CRT_SECURE_NO_WARNINGS
#define kol_razd 4
#include <stdio.h>
#include <ctype.h>

void calcLetters(char* iStr, char* razd, int kol) {
	int i = 0;
	int sch_hi = 0;
	int l = 0;
	int idet = 0;
	char aa[1000001];
	int znak;

	int nach_sl = 1000001;
	while (iStr[i] != '\0') {
		znak = 0;
		for (int j = 0; j < kol; j++) 
			if (iStr[i] == razd[j])
				znak = 1;

		if (znak==0) {
			if (isupper(iStr[i]))
				sch_hi += 1;

			if (i < nach_sl)
				nach_sl = i;

			l += 1;
			idet = 1;
		}

		else if (idet == 1) {
			idet = 0;
			printf("%d/%d ", sch_hi, l);
			for (int j = nach_sl; j < i; j++)
				printf("%c", iStr[j]);

			nach_sl = 1000001;
			printf("\n");
			l = 0;
			sch_hi = 0;
		}


		i += 1;
	}

	if (idet == 1) {
		printf("%d/%d ", sch_hi, l);
		for (int j = nach_sl; j < i; j++)
			printf("%c", iStr[j]);
	}


}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    
    //int kol_razd = 4;
    
	char razd[kol_razd] = { ',', '.', ':', ';'};
	char aa[1000001];
	gets(aa);
	calcLetters(aa, razd, kol_razd);

	return 0;
}
