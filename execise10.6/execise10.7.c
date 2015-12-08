#include "stdio.h"
#include "stdlib.h"
#include "student.h"



int main(int argc, char const *argv[])
{
	FILE *f;
	int i, k;
	tStudent student_list[5];
	f = fopen("stu_sort", "r");
	if(f == NULL){printf("ERROR:FILE open error!!\n");	return -1;}
	for (i = 0; i < 5; ++i)
	{
		fread(&student_list[i], sizeof(tStudent), 1, f);
		printf("name : %s\nschoolNUM : %s\n", student_list[i].name, student_list[i].schoolNUM);
		printf("scores : ");
		for (k = 0; k < SCORE_NUM; ++k)
		{
			printf("%6.1f", student_list[i].scores[k]);
		}
		printf("\naverage_score : %.1f\n", student_list[i].average_score);
		printf("\n\n");
	}
	fclose(f);
	return 0;
}