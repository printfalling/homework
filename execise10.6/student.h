#define MAX_NAME_LEN 128
#define MAX_SCHOOLNUM_LEN 128
#define SCORE_NUM 3

typedef struct Student
{
	char name[MAX_NAME_LEN];
	char schoolNUM[MAX_SCHOOLNUM_LEN];
	float scores[SCORE_NUM];
	float average_score;
} tStudent;


float Average(float list[], int length)
{
	int i;
	float sum = 0.0f;
	for (i = 0; i < length ; ++i)
	{
		sum += list[i];
	}
	return sum/length;
}