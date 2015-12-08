#include "stdio.h"
#include "string.h"
#define NUM 10
#define STR_LRN 20

char stuff[NUM][STR_LRN] = {"\0"};
int stuff_num[NUM] = {0};

int Input();
int Sort();
int Find(int num);

int main(int argc, char const *argv[])
{
	int num;
	Input();
	Sort();
	printf("Enter the number of the stuff you want to find : \n");
	scanf("%d", &num);
	if(!Find(num))  printf("unfinded\n");
	return 0;
}

int Input()
{
	int i;
	for (i = 0; i < NUM; ++i)
	{
		printf("Please enter the name of No.%d stuff and number\n", i+1);
		scanf("%s", stuff[i]);
		scanf("%d", &stuff_num[i]);
	}
}

int Sort()	//choosing
{
	int i, j, k;
	int temp;								//temp num
	char temp_str[STR_LRN] = "\0";			//temp name
	for (i = 0; i < NUM - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < NUM; ++j)
		{
			if (stuff_num[j] < stuff_num[k]) //the smallest
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp = stuff_num[i];
			stuff_num[i] = stuff_num[k];	//switch num
			stuff_num[k] = temp;

			strcpy(temp_str, stuff[i]);
			strcpy(stuff[i], stuff[k]);		//switch name
			strcpy(stuff[k], temp_str);
		}
	}
	return 0;
}

int Find(int num)
{
	int head = 0, tail =  sizeof(stuff_num)/sizeof(int) - 1;
	int mid = 0;
	while(tail - head >= 0)
	{
		mid = (head + tail)/2;
		if (stuff_num[mid] == num) 
		{
			printf("%s\n", stuff[mid]);
			return 1;
		}
		else if (stuff_num[mid] < num) // small -> mid -> large
		{
			head = mid + 1;
		}
		else if(stuff_num[mid] > num)
		{
			tail = mid - 1;
		}
	}
	return 0;
}