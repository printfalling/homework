//calculate the number of different chars

#include "stdio.h"
#include "string.h"
#ifndef MAX_STR_LEN
#define MAX_STR_LEN 124
#endif

int main(int argc, char const *argv[])
{
	char string[MAX_STR_LEN];
	int alphaNum = 0, spaceNum = 0,
		digitNum = 0, otherNum = 0;
	int i;
	printf("Please enter a string(len < %d) : \n", MAX_STR_LEN);
	gets(string);
	for (i = 0; string[i] != '\0'; ++i)
	{
		if (isalpha(string[i]))
		{
			alphaNum++; /* count alphas */
		}
		else if (isspace(string[i]))
		{
			spaceNum++; /* count spaces */
		}
		else if (isdigit(string[i]))
		{
			digitNum++; /* count digtis */
		}
		else
		{
			otherNum++; /* count others */
		}
	}
	printf("alphaNum = %d\nspaceNum = %d\ndigitNum = %d\notherNum = %d\n", 
		alphaNum, spaceNum, digitNum, otherNum);
	return 0;
}