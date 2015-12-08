#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	double loan = 300000, rate = 0.01;
	double repayment = 6000;
	double month = 0;
	month = log10(repayment/(repayment - loan * rate))/log10(1 + rate);
	printf("%.1lf\n", month);
	return 0;
}