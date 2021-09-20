
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Bitness(){
	#ifdef _WIN64
		return 64;
		//printf("Bitness: 64\n");
	#else
		return 32;
		//printf("Bitness: 32\n");
	#endif
}

const char* Compiler(){
	#ifdef __clang__
		return "clang";
		//printf("Compiler: clang\n");
	#elif _MSC_VER
		return "MSVC";
		//printf("Compiler: MSVC\n");
	#elif __GNUC__
		return "GCC";
		//printf("Compiler: GCC\n");
	#elif __TINYC__
		return "TCC";
		//printf("Compiler: TCC\n");
	#endif
}

const char* _asserts(){
	#ifdef NDEBUG
		return "disabled";		
//printf("Asserts: disabled\n");
	#else
		return "enabled";
		//printf("Asserts: enabled\n");
	#endif
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	const char* c;

	c = Compiler();
	printf("Compiler: %s\n", c);
	printf("Bitness: %d\n", Bitness());
	const char* a;
	a = _asserts();
	printf("Asserts: %s\n", a);
	

	return 0;
}