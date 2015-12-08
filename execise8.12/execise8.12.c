#include "stdio.h"
#include "stdlib.h"


int Sort(char* strs[]);
int Swap(char** pstr1, char **pstr2);
int main(int argc, char const *argv[])
{
	int i, k;
	char* strings[10];
	int length;
	srand(time(0));
	for (i = 0; i < 10; ++i)
	{
		/*strings[i] = malloc(sizeof(char)*(length + 1));
		for (k = 0; k < length; ++k)
		{
			strings[i][k] = rand()%64 + 64;
		}
		strings[i][k] = '\0';*/
		printf("Enter length\n");
		scanf("%d", &length);
		strings[i] = (char*)malloc(sizeof(char)*(length + 1));
		scanf("%s", strings[i]);
		strings[i][length] = '\0';
	}
	for (i = 0; i < 10; ++i)
	{
		printf("%s\n", strings[i]);
	}
	printf("\n\n");
	Sort(strings);
	for (i = 0; i < 10; ++i)
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
	for (i = 0; i < 10; ++i)
	{
		k = i;
		for (j = i + 1; j < 10; ++j)
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