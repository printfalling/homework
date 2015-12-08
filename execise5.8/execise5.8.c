//find out all the narcissistic number in range 100 ,10000
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int num = 0;
	int list[3] = {0}, sum = 0, temp = 0;
	int i;
	for (num = 100; num < 10000; ++num)
	{
		sum = 0;
		temp = num;
		for (i = 0; i < 3; ++i)
			{
				list[i] = temp % 10; /* to get each digit of the num */
				temp /= 10;
			}

		for (i = 0; i < 3; ++i)
			{
				sum = sum + list[i]*list[i]*list[i]; /* add them up */
			}


		if (sum == num)
		{
			printf("%d is a narcissistic number\n", num); /* judgement */
		}
	}
		
	
	return 0;
}

