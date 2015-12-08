

#include "stdio.h"
#include "student.h"



tStudent students[5] = {
	{"Jack", "PB15111098", {90, 78, 89}, 0.0f},
	{"John", "PB15111987", {86, 97, 55}, 0.0f},
	{"Mary", "PB15111345", {98, 78, 88}, 0.0f},
	{"Maja", "PB15111666", {87, 67, 56}, 0.0f},
	{"Jerry","PB15111223", {90, 95, 88}, 0.0f}
};


int Set_std_avg(tStudent *list, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		list[i].average_score = Average(list[i].scores, SCORE_NUM);

	}
	return 0;
}

int Stu_sort(tStudent list[], int n)
{
	int i, j, k;
	tStudent temp;
	for (i = 0; i < n - 1; ++i) //choosing
	{
		k = i;
		for (j = i+1; j < n ; ++j)
		{
			if (list[j].average_score > list[k].average_score)
			{
				k = j; 	
			} 
		}
		temp = list[i];
		list[i] = list[k];
		list[k] = temp;
	}
	return 0;
}



int main(int argc, char const *argv[])
{
	int i, k;
	FILE *f1, *f2;
	f1 = fopen("stu_sort.txt", "w");
	f2 = fopen("stu_sort", "w");
	if(f1 == NULL || f2 == NULL)
	{
		printf("ERROR:FILE open error!!\n");
		return -1;
	}
	Set_std_avg(students, 5);
	Stu_sort(students, 5);
	for (i = 0; i < 5; ++i)
	{
		fwrite(&students[i], sizeof(tStudent), 1, f2);
		fprintf(f1, "name : %s\nschoolNUM : %s\n", students[i].name, students[i].schoolNUM);
		fprintf(f1, "scores : ");
		for (k = 0; k < SCORE_NUM; ++k)
		{
			fprintf(f1, "%6.1f", students[i].scores[k]);
		}
		fprintf(f1, "\naverage_score : %.1f\n", students[i].average_score);
		fprintf(f1, "\n\n");
	}
	fclose(f2);
	fclose(f1);
	return 0;
}



int submain()
{
	int i;
	float list[5];
	srand(time(0));
	for (i = 0; i < 5; ++i)
	{
		list[i] = (float)(rand() % 10 + 1);
		printf("%f\n", list[i]);
	}
	printf("%f\n", Average(list, 5));
	return 0;
}
