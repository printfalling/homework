// a function in math
#include <stdio.h>

double Y(double x);
int main(int argc, char const *argv[])
{
	double x = 0.0;
	double y;
	scanf("%lf", &x);
	y = Y(x);
	printf("%.0lf\n", y);
	return 0;
}

double Y(double x)
{
	if (x < 1.0)
	{
		return x;
	}
	else if (x >= 10)
	{
		return 3 * x - 11;
	}
	else
	{
		return 2 * x - 1;
	}

}