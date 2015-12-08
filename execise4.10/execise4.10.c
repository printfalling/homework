#include <stdio.h>

int main(int argc, char const *argv[])
{
	double base1 = 100000 * 0.1,
		base2 = base1 + 100000 * 0.075,
		base3 = base2 + 200000 * 0.05,
		base4 = base3 + 200000 * 0.03,
		base5 = base4 + 400000 * 0.015; //set all the basises of each level
	double profiles = 0.0;
	double award = 0.0;
	printf("Enter the profiles : ");
	scanf("%lf", &profiles);
	if (profiles > 0 && profiles <= 100000)
	{
		award = profiles * 0.1;
	}
	else if (profiles <= 200000)
	{
		award = (profiles - 100000) *0.075 + base1;
	}
	else if (profiles <= 400000)
	{
		award = (profiles - 200000) * 0.05 + base2;
	}
	else if (profiles <= 600000)
	{
		award = (profiles - 400000) * 0.03 + base3;
	}
	else if (profiles <= 1000000)
	{
		award = (profiles - 600000) * 0.015 + base4;
	}
	else if (profiles > 1000000)
	{
		award = (profiles - 100000) * 0.010 + base5;
	}
	printf("The award is : %lf\n", award);
	return 0;
}