//sort
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int nums[4] = {0};
	int i, k;
	int temp;
	printf("Plase enter 4 numbers: \n");
	for (i = 0; i < 4; ++i)
	{
		scanf("%d", &nums[i]);
	}
	for (i = 3; i > 0; --i)
	{
		for ( k = 0; k < i; ++k) //bubble sort
		{
			if (nums[k] > nums[k + 1])
			{
				temp = nums[k];
				nums[k] = nums[k + 1];
				nums[k + 1] = temp;
			}
		}
	}
	for (i = 0; i < 4; ++i)
	{
		printf("%8d", nums[i]);
	}
	
	return 0;
}