#include <stdio.h>
#include <stdlib.h>

int sort(int num[10], int head, int tail);
int swamp(int *a, int *b);
int main()
{
	int numbers[10] = {0};
	int i;
	srand(time(0));
	for(i = 0; i < 10; i++)
	{
		numbers[i] = rand();
	}
	for (i = 0; i < 10; i++)
	{
		printf("%8d", numbers[i]);
	}
	printf("\n\n");
	sort(numbers, 0 ,9); 
	for (i = 0; i < 10; i++)
	{
		printf("%8d", numbers[i]);
	}
}
int sort(int num[10], int head, int tail)
{
	if(head >= tail)	return 0; 
	int i, j;
	j = tail;
	i = head;
	for (; j != i; j--)	//assert (left and right are both devided by middle) || (i != j)
	{
		if (num[j] < num[head])
		{
			for (; i != j; i++)
			{
				if (num[i] < num[head])
				{
					swamp(num + j, num + i);
					break;
				}
			}
		}
	}
	if (i != head)	swamp(num + head, num + i);
	sort(num, head, i -1);
	sort(num, i + 1, tail);
	return 0;
}


int swamp(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}