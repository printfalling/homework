#include "stdio.h"



int main(int argc, char const *argv[])
{
	unsigned int m;
	unsigned int k,flag = 0, count = 0;
	int i;
	scanf("%u%u", &k, &m);
	if (m % 19 == 0)
	{
		flag = 1;
	}
	for (i = 0; m != 0; ++i)
	{
		if (m % 10 == k)
		{
			count ++;
		} 
		m /= 10;
	}
	if (flag == 1 && count == 3)
	{
		printf("OK\n");
	}
	else 
	{
		printf("NO\n");
	}
	return 0;
}