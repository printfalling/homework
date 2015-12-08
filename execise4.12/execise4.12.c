// the heghth of the position
#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	double x, y;
	double towerX = 2, towerY = 2;
	printf("Please enter the position(x /n y) : \n");
	scanf("%lf", &x);
	scanf("%lf", &y);
	x = fabs(x);
	y = fabs(y);
	if ((x - 2) * (x - 2) + (y - 2) * (y - 2) < 1)
	{
		printf("The height is : 10 m\n");
	}
	else
	{
		printf("The height is : 0 m\n");
	}
	return 0;
}