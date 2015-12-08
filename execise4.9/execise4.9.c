// enter a five digtit number then...
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int num = 0, digits = 0;
	int temp = 0, dig = 1;
	int i, k;
	int flag = 1;
	scanf("%d", &num);
	temp = num;
	printf("print the num from end to head :");
	while(flag)
	{
		digits++;
		
 		printf("%d", temp%10);
		
		temp /= 10;
		if (temp == 0)
		{
			flag = 0;
		}
	}
	printf("\n");
	temp = 0;
	for (i = digits; i > 0; --i)
	{
	 	
	 	dig = 1;
	 	for (k = 0; k < i - 1; ++k)
	 	{
	 		
	 		dig *= 10;
	 	}
	 	printf("The %d digit of the num: %d\n", 6 - i, num/dig - temp * 10);
	 	temp = num/dig;
	}
	printf("%d\n", digits);
	return 0;
}