//strcpy
#define STR_LEN 1024

int main(int argc, char const *argv[])
{
	char str1[STR_LEN] = "argvasdadddasdasdasds\0das    56 8879 8756da";
	char str2[STR_LEN] = "arg      \0  11@@//*-*~~     c     *";
	int i;
	for (i = 0; str2[i] != '\0', i < STR_LEN; ++i)
	{
		str1[i] = str2[i];
	}
	str1[i] = '\0';
	printf("%s\n", str1);
	return 0;
}