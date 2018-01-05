#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s_buf[255],s_get[255],File_[100];
	FILE *p;

	puts("Enter name of file:");
	gets_s(File_, 100);
	puts("Enter string:");
	gets_s(s_buf, 255);
	if (fopen_s(&p,File_,"r") != NULL)
	{
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	while (fgets(s_get, 255, p))
	{
		if (strstr(s_get, s_buf))
		{
			puts(s_get);
		}
	}
	fclose(p);
	return 0;
}