
#include "string.h"
#include "stdio.h"
int mystrstr(char desc[], char scr[]);
int main(int argc, char const *argv[])
{
	char string1[124], string2[124], *string;
	printf("Enter two strings:\n");
	scanf("%s", string1);
	scanf("%s", string2);
	mystrstr(string1, string2);
	printf("%s\n", string1);
	return 0;
}


int mystrstr(char desc[], char scr[])
{
	int i;
	size_t len_desc = strlen(desc);
	for (i = 0; i <= strlen(scr); ++i) // <= for '\0'
	{
		desc[i + len_desc] = scr[i];
	}
	return 0;
}