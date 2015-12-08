#include "stdio.h"
#include "stdlib.h"
#define SCORE_NUM 3

typedef struct Student
{
	char name[128];
	char schoolNUM[128];
	float scores[SCORE_NUM];
} tStudent;

float Average(float *list, int length) //checked
{
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i)
	{
		sum += list[i];
	}
	return sum/length;
}

float Get_std_avr(tStudent *list,int num)
{
	int i;
	float sums[num];
	for (i = 0; i < num; ++i)
	{
		sums[i] = Average(list[i].scores, SCORE_NUM);
	}
	return Average(sums, num);
}



int main(int argc, char const *argv[])
{
	int i, k;
	FILE *f;
	f = fopen("stud.txt", "w");
	if(f == NULL)
	{
		printf("ERROR:FILE open error!!\n");
		return -1;
	}
	tStudent students[5];
	
	printf("Enter the datas \n");
	for (i = 0; i < 5; ++i)
	{
		printf("Student No.%d\n", i + 1);
		printf("School numbers : \n");
		scanf("%s", &students[i].schoolNUM);
		printf("Name : \n");
		scanf("%s", &students[i].name);
		for (k = 0; k < SCORE_NUM; ++k)
		{
			printf("the %d%s class scores : \n", k+1, (k == 0)? "st" : (k == 1)? "nd" : "rd");
			scanf("%f", students[i].scores + k);
		}
	}
	fprintf(f, "%s\n", "It works!!");
	fprintf(f, "%.2f\n", Get_std_avr(students, 5));
	fclose(f);
	return 0;
}
