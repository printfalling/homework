//linklist in execise 8.11.c
//using array
//many people in a row
#include "stdio.h"


int main(int argc, char const *argv[])
{
	int i, count = 1;
	int head = 0, tail = 13;
	int student[128];
	for (i = 0; i < 13; ++i)
	{
		student[i] = i + 1;
	}
	while(tail - head > 1)
	{
		if (count % 3 != 0){
			student[tail] = student[head];
			tail++;
		}
		head++;
		count++;
	}
	printf("%d\n", student[head]);
	return 0;
}