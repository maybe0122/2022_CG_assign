#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	FILE* fp = NULL;
	char fname[128];
	char buffer[128];
	int word_count = 0;
	int num_count = 0;
	int capital_count = 0;
	bool word_flag = false;
	bool num_flag = false;
	bool capital_flag = false;
	bool char_flag = false;

	scanf("%s", fname);
	printf("input data file name: %s", fname);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("Wrong file name!\n");
		exit(1);
	}

	while (fgets(buffer, 128, fp) != NULL)
	{
		printf("%s", buffer);

		for (int i = 0; i < strlen(buffer); i++)
		{
			if (!isspace(buffer[i]) && !word_flag)						//word count
			{
				word_count++;
				word_flag = true;

				if (!(isdigit(buffer[i])) && isupper(buffer[i]))		//capital count
					capital_count++;
			}

			if (isspace(buffer[i]))
				word_flag = false;
			
			if (!isspace(buffer[i]))									//number count
			{
				if (isdigit(buffer[i]))
					num_flag = true;
				else
					char_flag = true;
			}
			else
			{
				if (num_flag && !(char_flag))
					num_count++;
				char_flag = false;
				num_flag = false;
			}
		}
	}
		
	printf("\n");
	printf("word count: %d\n", word_count - num_count);
	printf("number count: %d\n", num_count);
	printf("Capital count: %d\n", capital_count);

	fclose(fp);
}