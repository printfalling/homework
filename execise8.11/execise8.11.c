#include "stdio.h"
#include "stdlib.h"
#ifndef NUM
#define NUM 2
#endif

//产生字符串并排序
int Sort(char* strs[]);
int Swap(char** pstr1, char **pstr2);
int main(int argc, char const *argv[])
{
	int i, k;
	char* strings[NUM];
	const int length = 128;
	srand(time(0));
	for (i = 0; i < NUM; ++i)
	{
		// length = rand()%128;	//随机控制长度
		strings[i] = malloc(sizeof(char)*(length + 1));
		// for (k = 0; k < length; ++k)
		// {
		// 	strings[i][k] = rand()%64 + 64;		//随机生成字符串
		// }
		//strings[i][k] = '\0';	//二维数组存字符串
		scanf("%s", strings[i]);
	}

	for (i = 0; i < NUM; ++i)
	{
		printf("(%d)  %s\n", i+1, strings[i]);
	}
	printf("\n\n");
	Sort(strings);
	for (i = 0; i < NUM; ++i)
	{
		printf("(%d)  %d\n", i+1, strings[i][0]);
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
			if(Compare(strs[k], strs[j]) > 0)//选择排序
			{
				k = j;
			}
		}
		if (k != i)	Swap(&strs[i], &strs[k]);
	}
}

int Swap(char** pstr1, char** pstr2) //交换指针值
{
	char* ptemp;
	ptemp = *pstr1;
	*pstr1 = *pstr2;
	*pstr2 = ptemp;
}

int Compare(char* str1, char* str2)
{
	int i;
	for (i = 0; i < 128; ++i)	//遍历每一位，分别比较
	{
		if (str1[i] > str2[i]){
			return 1;
		}
		else if (str1[i] == str2[i]){
			if (str1[i] == '\0')
			{
				return 0;
			}
		}
		else{
			return -1;
		}
	}
}