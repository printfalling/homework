#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int Swap(char* str1, char* str2);
int main(int argc, char const *argv[])
{
	char *str1, *str2;
	char *a = "asdf", *b = "qwer";
	str1 = malloc(sizeof(char)*11);
	str2 = malloc(sizeof(char)*11);
	// assert(str1 != NULL, str2 != NULL);
	strcpy(str1, a);
	strcpy(str2, b);
	Swap(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	free(str1);
	free(str2);
	return 0;
}

int Swap(char* str1, char* str2)
{
	char* ptemp;
	ptemp = str1;
	str1 = str2;
	str2 = ptemp;
}