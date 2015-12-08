#include "stdio.h"

int main(int argc, char const *argv[])
{
	int num, factors[100] = {0}, sum = 0;
	int i, j, k = 0, flag = 0;
	for (num = 1; num <= 1000; ++num)
	{
		for (i = 1; i < num; ++i)
		{
			if (num % i == 0) //find all factors
			{
				for (j = 0; j < k; ++j)	if(factors[j] == i) flag = 1; // check whether i in factors
				if (flag == 0)
				{
					factors[k] = i;
					k += 1;
				}
			}
		}
		for ( j = 0; j < k; ++j) //sum up
		{
			sum += factors[j];
		}
		if (sum == num) //check and print
		{
			printf("%4d is factors are : ", num);
			for ( j = 0; j < k; ++j)
			{
				printf("%d", factors[j]);
				if (j != k - 1)
				{
					printf(", ");
				}
			}
			printf("\n");
		}
		for ( j = 0; j < k; ++j) //reset
		{
			factors[j] = 0;
		}
		k = 0;
		flag = 0;
		sum = 0;
	}
	return 0;
}