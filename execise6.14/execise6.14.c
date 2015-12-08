//strcmp
#include "stdio.h"
#define STR_LEN 1024
int main(int argc, char const *argv[])
{
	char str1[STR_LEN] = "\0", str2[STR_LEN] = "\0";
	int tag = 0;
	int i;
	printf("Please enter two strings\n");
	gets(str1);
	gets(str2);
	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; ++i)
	{
		if (str1[i] != str2[i])
		{
			tag = str1[i] - str2[i];
			break;
		}

	}
	printf("%d\n", tag);
	return 0;
}