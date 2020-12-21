#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime_s {
	int year, month, day;
	int hours, minutes, seconds;
} Datetime;


void perenazn(const Datetime* aa, int i, int* ma_year, int* ma_month, int* ma_day, int* ma_hours, int* ma_minutes, int* ma_seconds) {
	*ma_year = aa[i].year;
	*ma_month = aa[i].month;
	*ma_day = aa[i].day;
	*ma_hours = aa[i].hours;
	*ma_minutes = aa[i].minutes;
	*ma_seconds = aa[i].seconds;
}

//DateTime  min(const  DateTime* arr, int cnt);

Datetime min(const Datetime* arr, int cnt) {
	int ma_year = 3000;
	int ma_month = 3000;
	int ma_day = 3000;
	int ma_hours = 3000;
	int ma_minutes = 3000;
	int ma_seconds = 3000;

	int ind = 0;
	for (int i = 0; i < cnt; i++) {

		if (arr[i].year <= ma_year) {
			if (arr[i].year < ma_year) {
				perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
				ind = i;
			}


			if (arr[i].month <= ma_month) {
				if (arr[i].month < ma_month) {
					perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
					ind = i;
				}

				if (arr[i].day <= ma_day) {
					if (arr[i].day < ma_day) {
						perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
						ind = i;
					}

					if (arr[i].hours <= ma_hours) {
						if (arr[i].hours < ma_hours) {
							perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
							ind = i;
						}

						if (arr[i].minutes <= ma_minutes) {
							if (arr[i].minutes < ma_minutes) {
								perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
								ind = i;
							}

							if (arr[i].seconds <= ma_seconds)
								if (arr[i].seconds < ma_seconds) {
									perenazn(arr, i, &ma_year, &ma_month, &ma_day, &ma_hours, &ma_minutes, &ma_seconds);
									ind = i;
								}
						}
					}
				}
			}
		}
	}
	return arr[ind];
}


int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int year;
	int month;
	int day;

	int hours;
	int minutes;
	int seconds;

	Datetime* aa = (Datetime*)malloc(n * sizeof(Datetime));

	if (aa == 0) {
		printf("NE_V_ETOT_RAZ");
		return 0;
	}

	for (struct DateTime_s* i = aa; i < aa + n; i++) {
		scanf("%d %d %d %d %d %d", &i->year, &i->month, &i->day, &i->hours, &i->minutes, &i->seconds);
	}

	*aa = min(aa, n);
	printf("%d %d %d %d %d %d", aa[0].year, aa[0].month, aa[0].day, aa[0].hours, aa[0].minutes, aa[0].seconds);

	free(aa);
	return 0;
}
