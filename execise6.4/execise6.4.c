//insert
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int list[1000] = {1, 2, 3, 4, 6, 7, 10};
	int tail = 7, i, k, flag;
	int num;
	while(flag)
	{
		printf("Please enter a num: \n", num);
		scanf("%d", &num);
		for (i = 0; i < tail; ++i)
		{
			if (num < list[i])  //compare
			{
				break;
			}
		}
		if (i == tail)
		{
			list[tail] = num;
		}
		else
		{
			for (k = tail; k > i; k--)
			{
				list[k] = list[k - 1];
			}
			list[i] = num;	
		}
		tail++;
		for (i = 0; i < tail; ++i)
			{
				printf("%4d   ", list[i]);
			}
		printf("\nMore numbers?(1/0)\n");
		scanf("%d", &flag);
	}
		
	return 0;
}