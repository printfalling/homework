//monkey and peaches
#include "stdio.h"
#ifndef DAY
#define DAY 10
#endif
int main(int argc, char const *argv[])
{
	int num = 1;
	int i;
	for (i = DAY - 1; i > 0; --i)
	{
		num = (num + 1) * 2;
	}
	printf("The num of peaches is : %d\n", num);
	return 0;
}

