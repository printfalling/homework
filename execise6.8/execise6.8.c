//saddle
#include "stdio.h"
#define SIZE 5

int main(int argc, char const *argv[])
{
	int datas[SIZE][SIZE] = {
		{0, 0, 0, 2, 0,},
		{0, 0, 0, 1, 0,},
		{0, 0, 0, 2, 0,},
		{0, 0, 0, 1, 0,},
		{0, 0, 0, 2, 0,},
	};
	int tags[SIZE][SIZE] = {0}, tag = 0;
	int temp = 0, i, k, j;
	for (i = 0; i < SIZE; ++i)
	{	
		temp = datas[i][0];
		j = 0;
		for (k = 1; k < SIZE; ++k)
		{
			if (datas[i][k] > temp)
			{
				temp = datas[i][k];
			}
		}
		for (k = 0; k < SIZE; ++k)
		{
			if (datas[i][k] < temp)
			{
				tags[i][k] = 1;
			}
		}
	}
	for (i = 0; i < SIZE; ++i)
	{	
		temp = datas[0][i];
		j = 0;
		for (k = 1; k < SIZE; ++k)
		{
			if (datas[k][i] < temp)
			{
				temp = datas[k][i];
			}
		}
		for (k = 0; k < SIZE; ++k)
		{
			if (datas[k][i] > temp)
			{
				tags[k][i] = 1;
			}
		}
	}

	for (i = 0; i < SIZE; ++i)
	{
		for (k = 0; k < SIZE; ++k)
		{
			if (tags[i][k] == 0)
			{
				printf("%d -- %d%8d\n", i+1, k+1, datas[i][k]);
				tag = 1;
			}
		}
	}
	if (tag == 0)
	{
		printf("Can't find a saddle\n");
	}
	return 0;
}
