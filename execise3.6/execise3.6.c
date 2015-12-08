#include "stdio.h"
#define STR_LEN 124

int main(int argc, char const *argv[])
{
	char str[STR_LEN] = "China";

	int i;
	for(i = 0;str[i] != '\0'; i++)
	{
		if (str[i] >= 87 && str[i] <= 90)
		{
			str[i] += 10;
		}
		else if (str[i] >= 119 && str[i] <= 122)
		{
			str[i] -= 54;
		}
		else
		{
			str[i] += 4;
		}
	}
	printf("%s\n", str);
	return 0;
}