#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct help_s {
	long long a;
	long long b;
	long long m;
	char oper;
}help;

long long calculate(help aa) {
	long long result;
	if (aa.oper == 'a') 
		result = (aa.a + aa.b);
	else if (aa.oper == 's') 
		result = (aa.a - aa.b);
	else
		result = (aa.a * aa.b);
	if (aa.m == -99)
		return result;
	else
		return ((result) % aa.m + aa.m) % aa.m;	
}

help parse(int argc, char** argv) {
	help stroka = {0};
	argc -= 1;
	if (argc > 3) {
		int m;
		if (strcmp(argv[1], "-m") == 0) {
			stroka.m = atoi(argv[2]);
			stroka.a = atoi(argv[4]);
			stroka.b = atoi(argv[5]);
			stroka.oper = argv[3][0];
		}
		else {
			stroka.m = atoi(argv[5]);
			stroka.a = atoi(argv[2]);
			stroka.b = atoi(argv[3]);
			stroka.oper = argv[1][0];
		}
	}
	else {
		stroka.m = -99;
		stroka.a = atoi(argv[2]);
		stroka.b = atoi(argv[3]);
		stroka.oper = argv[1][0];
	}
	return stroka;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		fprintf(stderr, "No parameters specified.");
		return 13;
	}
	else {
		help stroka = parse(argc, argv);
		printf("%lld", calculate(stroka));
	}	
	return 0;
}