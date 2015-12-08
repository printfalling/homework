// perfect numbers
#include "stdio.h"
#define MAX_LEN 1001

int main(int argc, char const *argv[])
{
	int num = 3;
	int count[MAX_LEN] = {0}, sum = 0; //"count" used to record the factors
	int i;
	for (num = 6; num < MAX_LEN; ++num) //count from 6
	{
		sum = 0;
		for (i = 1; i < MAX_LEN; ++i) //reset the count
		{
			count[i] = 0;
		}
		for (i = 1; i < MAX_LEN; ++i) //find the factors
		{
			if (num % i == 0)
			{
				count[i] = 1; //get all the factors
			}
		}
		for (i = 1; i < MAX_LEN; ++i) //sum up all facters
		{
			if (count[i] != 0)
			{
				
				sum += i; //get the sum
			}
		}
		sum -= num;
		
		if (sum == num)
		{
			printf("%4d is factors are : ", num);
			for (i = 1; i < MAX_LEN; ++i)
			{
				if (count[i] != 0)
				{
					printf("%d, ", i);
				}
			}
			printf("\n");
		}
		
	}	
	return 0;
}