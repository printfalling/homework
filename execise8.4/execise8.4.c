#include "stdio.h"
#include "stdlib.h"
#define N 10
int Move(int m);
int Copy(int m);
int numbers[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int main()
{
	int *array, *temp_array;
	int i;
	int m;

	if(array = malloc(sizeof(int) * N));
	for (i = 0; i < N; ++i) // initialize
	{
		array[i] = numbers[i];
	}

	printf("Enter a numbers less than %d\n", N);
	scanf("%d", &m)
	temp_array = malloc(sizeof(int) * m);
	for (i = 0; i < m; ++i)
	{
		temp_array[i] = numbers[i]
	}

	free(array);
	free(temp_array);
	return 0;
}