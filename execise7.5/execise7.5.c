//reversing

#include "stdio.h"
#include "string.h"
int function(char str[]);
int main(int argc, char const *argv[])
{
	char string[124];//max length 124 including '\0'
	printf("Enter your string:\n");
	scanf("%s", string);
	function(string);
	printf("%s\n", string);
	return 0;
}

int function(char* str)
{
	
	char temp;
	int i, len;
	len = strlen(str);
	for (i = 0; i < len/2; ++i)		//form the 1st one and the last one.
	{
		temp = str[i];   			//switch
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	return 0;
}