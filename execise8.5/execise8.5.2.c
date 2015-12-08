#include "stdio.h"
#include "stdlib.h"

#define NUM 13
int main(int argc, char const *argv[])
{
	
	int head = 0, tail = NUM, count = 1, i;
	int *students = malloc(sizeof(int)*1024);
	if (students == NULL)	return -1;

	for (i = 0; i < NUM; ++i)
	{
		students[i] = i + 1;	//set datas
	}

	while(tail - head > 1){								/* (1) 2 3 4 5 6 "      */
		if (count % 3 != 0 ){							/* 1 (2) 3 4 5 6 1 "    */
			students[tail] = students[head];			/* 1 2 (3) 4 5 6 1 2 "  */
			tail ++;									/* 1 2 3 (4) 5 6 1 2 "  */ 
		}
		head++;
		count++;
	}
	printf("%d\n", students[head]);
	free(students);
	return 0;
}