//find out all the narcissistic number in range (100 ,10000)
#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	int num, temp, a;
	int sum = 0;

	for ( num = 100; num < 10000; ++num)
	{
		sum = 0;
		temp = num;

		do
		{
			a = temp % 10;
			sum += a*a*a; /* sum up */
			temp = temp / 10;
		} while (temp != 0);

		if (num == sum) /* judgement */
		{
			printf("%d is a narcissistic number\n", num); 
		}
	}
	return 0;
}

