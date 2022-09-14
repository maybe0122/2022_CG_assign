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
	char temp[128] = { '\0' };
	char str_temp[10][128] = { '\0' };
	char ch;
	int count = 0;
	int index = 0;
	bool d_flag = false;

	printf("input data file name: ");
	scanf("%s", fname);

	while ((ch = getchar()) != '\n') continue;							//remove buffer

	if ((fp = fopen(fname, "r")) == NULL)
	{
		printf("Wrong file name!\n");
		exit(1);
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if(buffer[strlen(buffer) - 1] == '\n')							//remove \n
			buffer[strlen(buffer) - 1] = '\0';

		strcpy(str_temp[count], buffer);
		printf("%s", str_temp[count]);
		count++;
		/*for (int i = 0; i < sizeof(buffer); i++)
			buffer[i] = '\0';*/
		printf("\n");
	}

	while (1)
	{
		printf("command: ");
		scanf("%c", &ch);

		switch (ch)
		{
		case'd':														//reverse all sentence
			for (int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
			{
				for (int i = 0; i < strlen(str_temp[k]); i++)
				{
					temp[i] = str_temp[k][strlen(str_temp[k]) - (i + 1)];
					printf("%c", temp[i]);
				}
				printf("\n");
			}
			
			break;
		case'e':														//
			break;
		case'f':
			break;
		case'g':
			break;
		case'h':
			break;
		case'q':
			return 0;
			break;
		default:
			printf("Wrong command!\nTry again\n");
			break;
		}

		while ((ch = getchar()) != '\n') continue;						//remove buffer
	}

	fclose(fp);
}