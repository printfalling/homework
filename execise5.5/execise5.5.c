//created by wjn
//date 2015/10/9
// 2 + 22 + 222 + 2222 + ...... = ?
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int A = 1, S = 0;  // A is a temp storage
	int a = A;
	int n = 0;
	int i;
	printf("Please Enter the number \'n\' : \n");
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		S += A;
		A = 10 * A + a;
	}
	printf("The number 'a' is : %d\n", a);
	printf("The number 'n' is : %d\n", n);
	printf("The sum is : %d\n", S);
	return 0;
}