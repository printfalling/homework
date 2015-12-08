// strstr

#include "stdio.h"
#define STR_LEN 1024

int main(int argc, char const *argv[])
{
	char dest[STR_LEN] = "jklj";
	char src[STR_LEN] = "*argc*";
	int i, k;
	for (i = 0; dest[i] != '\0'; ++i);// count
	for (k = 0; src[k] != '\0'; ++k, ++i)
	{
		dest[i] = src[k];
	}
	dest[i] = '\0';
 	printf("%s\n", dest);
 	return 0;
}