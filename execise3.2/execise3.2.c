
#include <stdio.h>
#include <math.h>

#define ONE_YEAR_INTREST 0.0414
#define TWO_YEAR_INTREST 0.0468
#define THREE_YEAR_INTREST 0.0540
#define FIVE_YEAR_INTREST 0.0585
#define COURENT_INTREST 0.0072
//all the intrests

int main(int argc, char const *argv[])
{
	int choice = 0;
	int i;
	double sum = 1000;
	printf("What's your choice?\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: 
		sum = sum * (1 + 5 * FIVE_YEAR_INTREST); //five years
		break;
		case 2: 
		sum = sum * (1 + 2 * TWO_YEAR_INTREST);
		sum = sum * (1 + 3 * THREE_YEAR_INTREST);
		break;
		case 3: 
		sum = sum * (1 + 3 * THREE_YEAR_INTREST);
		sum = sum * (1 + 2 * TWO_YEAR_INTREST);
		break;
		case 4:
		for(i = 0; i < 5; i++)
		{
			sum = sum * (1 + ONE_YEAR_INTREST);
		}
		break;
		case 5:
		for (i = 0; i < 20; ++i)
		{
			sum = sum * (1 + COURENT_INTREST);
		}

		break;
	}
	printf("The amount of money at last is :%8.2f\n", sum);
	return 0;
}