#include "stdio.h"


// mach the opponent

int main(int argc, char const *argv[])
{
	char a, b, c;
	char list[3] = "XYZ"; //A B C ---- X Y Z
	int i, j, k;
	for ( i = 0; i < 3; ++i)  // i -- A
	{
		for (j = 0; j < 3; ++j) // j -- B
		{
			for (k = 0; k < 3; ++k) //try all possibilities
			{
				if(i != j && j != k && i != k) // k -- C

				{
					a = list[i];
					b = list[j];
					c = list[k];
					if (a != 'X' && c != 'X' && c != 'Z')
					{
						printf("A --- %c\n", a);
						printf("B --- %c\n", b);
						printf("C --- %c\n", c);
					}
				}
			}
		}
	}
	return 0;
}