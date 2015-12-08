//find out the primes

#include "stdio.h"

int main(int argc, char const *argv[])
{
	int primes[4] = {2, 3, 5, 7};
	int nums[101] = {1, 1, 1, 0};
	int i, k;
	for (i = 0; i < 4; ++i)
	{
	 	for (k = 0; k < 101; ++k)
	 	{
	 		if(nums[k] == 0 && k % primes[i] == 0)
	 		{
	 			nums[k] = 1;
	 		}
	 	}
	}
	for (i = 0; i < 4; ++i)
	{
		nums[primes[i]] = 0;
	}
	for (i = 1; i < 101; ++i)
	{
		if (nums[i] == 0)
		{
			printf("%8d", i);
		}
	}
	printf("\n");
	return 0;
}
