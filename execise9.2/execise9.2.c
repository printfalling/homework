#include "stdio.h"
#include "stdlib.h"

typedef struct Date
{
	int year;
	int month;
	int date;
	int num;
} tDate;

enum Year{Jan, Febr, Mar, Apr, May, Jun, July, Aug, Sept, Oct, Nov, Dec};

int Is_leap(int year)
{
	int flag = 0;
	if (year % 4 == 0 && year % 400 != 0)
	{
		flag = 1;
	}
	return flag;
}

int Count(tDate a)
{
	int num;
	num = a.date;
	switch (a.month - 1)
	{
		case Dec:	num += 30;	//the days of the fore month
		case Nov:	num += 31;
		case Oct:	num += 30;
		case Sept:	num += 31;
		case Aug:	num += 31;
		case July:	num += 30;
		case Jun:	num += 31;
		case May: 	num += 30;
		case Apr:	num += 31;
		case Mar:	num += Is_leap(a.year)? 29 : 28; 
		case Febr:	num += 31;
		case Jan:	break;
	}
	return num;
}

int main(int argc, char const *argv[])
{
	tDate data;
	printf("Ehter the date :\n");
	printf("Year :\n");
	scanf("%d", &data.year);
	printf("Month :\n");
	scanf("%d", &data.month);
	printf("Date :\n");
	scanf("%d", &data.date);
	data.num = Count(data);
	printf("%d\n", data.num);
	return 0;
}