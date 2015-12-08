#include "stdio.h"
#include "string.h"
char* Find(char* str, char* word);

int main(int argc, char const *argv[])
{
	char word[512] = "\0", string[512] = "\0";
	printf("Enter a sentense:\n");
	gets(string);
	Find(string, word);
	printf("The longest word in the sentense is : %s\n", word);
	
	return 0;
}

char* Find(char* str, char* word)		//word is a pointer
{
	char words[64][64] = {"\0"};		//store the words
	char signs[10] = ",.?! <>\" ";		//sings to divide words
	int i, k, j = -1, l = 0, flag = 0;	//flag is used to store hoe many charather in a word
	int temp = 0;
	for (i = 0; str[i] != '\0'; ++i) //my strtok
	{
		for (k = 0; signs[k] != '\0'; ++k) // Check whether str[i] is a sign
		{
			if (str[i] == signs[k])
			{
				flag = 0;
				break;
			}
			if (signs[k + 1] == '\0')
			{
				flag++;
			}
		}

		if (flag != 0)
		{
			if (flag == 1)			//a new word?
			{
				j++;
			}
			words[j][l] = str[i];
			l++;
		}
		else if(flag == 0 & l != 0)	//set the end of the word
		{
			if (words[j][l] != '\0')//don't repeat
			{
				words[j][l] = '\0';
			}
			l = 0;					//reset l
		}
	}

						/* initial the first word*/
	for (j = 1, temp = strlen(words[0]), strcpy(word, words[0]); words[j][0] != '\0'; ++j)
	{
		if (strlen(words[j]) > temp)
		{
			strcpy(word, words[j]);//compare and copy the word
		}
	}
	return 0;
}