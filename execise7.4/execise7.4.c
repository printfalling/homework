
//change the row and of a table
#include "stdio.h"
int nums[3][3] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

int Change();
int Show();
int Switch(int *a, int *b);
int main(int argc, char const *argv[])
{
	int i, k;
	Change();	
	Show();
	
	return 0;
}

int Change()
{
	int i, k;
	for (i = 0; i < 3; ++i)						//  * *  //line
	{											//    *	 //row
		for (k = i + 1; k < 3; ++k)
		{
			Switch(&nums[i][k], &nums[k][i]);
		}
	}
	return 0;
}

int Switch(int* a, int* b)    //   use pointer
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
int Show()
{
	int i, k;
	for (i = 0; i < 3; ++i) //line
		{
			for (k = 0; k < 3; ++k)// row
			{
				printf("%4d", nums[i][k]);
			}
		printf("\n");
		}
}