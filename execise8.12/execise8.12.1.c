#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#ifndef NUM
#define NUM 10
#endif

int Sort(char* strs[]);
int Swap(char** pstr1, char **pstr2);
int main(int argc, char const *argv[])
{
	int i, k, j, flag;
	char* strings[NUM];
	char* temp_str;
	int length = NUM;
	srand(time(0));

	for (i = 0, flag = 0; i < NUM; ++i)
	{
		strings[i] = (char*)malloc(sizeof(char)*(length + 1));
		for (k = 0; flag != 1; ++k)
		{
			if (k >= length)
			{
				temp_str = (char*)malloc(sizeof(char)*(k/length + 1)*length + 1);
				strncpy(temp_str, strings[i], k);
				free(strings[i]);
				strings[i] = temp_str; 
			}
			strings[i][k] = getchar();
			printf("%c\n", strings[i][k]);
			if (strings[i][k] == '\n')
			{
				strings[i][k] = '\0';
				flag = 1;
			}
		}
	}

	for (i = 0; i < NUM; ++i)
	{
		printf("%s\n", strings[i]);
	}
	printf("\n\n");
	Sort(strings);
	for (i = 0; i < NUM; ++i)
	{
		printf("%d\n", strings[i][0]);
		printf("%s\n", strings[i]);
		free(strings[i]);
	}
	return 0;
}

int Sort(char* strs[])
{
	int i, j, k;
	for (i = 0; i < NUM; ++i)
	{
		k = i;
		for (j = i + 1; j < NUM; ++j)
		{
			if(Compare(strs[k], strs[j]) > 0)
			{
				k = j;
			}
		}
		if (k != i)	Swap(&strs[i], &strs[k]);
	}
}

int Swap(char** pstr1, char** pstr2)
{
	char* ptemp;
	ptemp = *pstr1;
	*pstr1 = *pstr2;
	*pstr2 = ptemp;
}

int Compare(char* str1, char* str2)
{
	int i;
	for (i = 0; str2[i] != '\0' && str1 != '\0'; ++i)
	{
		if (str1[i] > str2[i]){
			return 1;
		}
		else if (str1[i] == str2[i]){
			return 0;
		}
		else{
			return -1;
		}
	}
	if (str1[i] == '\0')
	{
		return -1;
	}
	else
	{
		return 1;
	}
}