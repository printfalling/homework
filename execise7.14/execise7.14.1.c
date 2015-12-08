#include "stdio.h"
#include "stdlib.h"
#define STU_NUM 10
#define CLS_NUM 5
char class_list[CLS_NUM][20] = {
	"Chinese\0", "English\0", "Physics\0", "Biology\0", "Math\0",
};

char student_list[STU_NUM][20];
float student_score_list[STU_NUM][CLS_NUM];
float class_score_list[CLS_NUM][STU_NUM];

float Average(float *list, int num)
{
	int i;
	float sum = 0;
	for (i = 0; i < num; ++i)
	{
		sum += list[i];
	}
	return sum/num;
}

float Variance(float *list, int num)
{
	int i, j;
	float sum1 = 0, sum2 = 0, V = 0;
	float average = Average(list, num);
	for (i = 0; i < STU_NUM; ++i)
	{
		sum1 += list[i] * list[i];
		sum2 += list[i];
	}
	V = sum1/STU_NUM - (sum2/STU_NUM)*(sum2/STU_NUM);
	return V/STU_NUM;
}

int Find()
{
	int i, j;
	int temp_i = 0, temp_j = 0;
	for (i = 0; i < STU_NUM; ++i)
	{
		for (j = 0; j < CLS_NUM; ++j)
		{
			if (student_score_list[i][j] > student_score_list[temp_i][temp_j])
			{
				temp_i = i;
				temp_j = j;
			}
		}
	}
	printf("the highest score\n");
	printf("student_name : %s class_name : %s\n", student_list[temp_i], class_list[temp_j]);
	return 0;
}

int Input()
{
	int i, j;
	float temp;
	printf("Enter the datas(student_name):\n");
	 for (i = 0; i < STU_NUM; ++i)
	 {
		printf("thre name of No.%d student\n",i+1);
		scanf("%s", student_list[i]);
	 }
	 for (i = 0; i < STU_NUM; ++i)
	 {
		for (j = 0; j < CLS_NUM; ++j)
		{
			printf("The %s scores of %s\n", class_list[j], student_list[i]);
			scanf("%f", &temp);
			student_score_list[i][j] = temp;
			class_score_list[j][i] = temp;
		}
	 }    //input datas
}

int main(int argc, char const *argv[])
{
	int i, j;
	int temp_i = 0, temp_j = 0;
	float average_list[STU_NUM] = {0};
	Input();
	for (i = 0; i < STU_NUM; ++i)
	{
		printf("The average score of %s is :", student_list[i]);
		printf("%4.2f\n", Average(student_score_list[i], CLS_NUM));
		average_list[i] = Average(student_score_list[i], CLS_NUM);
	} //averages of each students
	for (i = 0; i < CLS_NUM; ++i)
	{
		printf("%4.2f\n", Average(class_score_list[i], STU_NUM));
	}
	Find();
	printf("The Variance is : %4.2f\n", Variance(average_list, STU_NUM));

	return 0;
}
