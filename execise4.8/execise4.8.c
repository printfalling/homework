//calculate the level of the grades
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int grades = 0;
	printf("Enter the grades: \n");
	scanf("%d", &grades);
	if (grades >= 90)
	{
		printf("Level 'A'\n");
	}
	else if (grades >= 80)
	{
		printf("Level 'B'\n");
	}
	else if (grades >= 70)
	{
		printf("Level 'C'\n");
	}
	else if (grades >= 60)
	{
		printf("Level 'D'\n");
	}
	else if (grades >= 0)
	{
		printf("Level 'E'\n");
	}
	else
	{
		printf("You give me the wrong grades\n");
	}
	return 0;
}