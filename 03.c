#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)

int main()
{
	FILE* fp = NULL;
	char fname[128];
	char buffer[128];
	char temp[128] = { '\0' };
	char str_temp[10][128] = { '\0' };
	char ch, c1, c2;
	int count = 0;
	int index = 0;
	int same = 0;
	bool same_flag = true;

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
		printf("\n");
	}

	while (1)
	{
		printf("command: ");
		scanf("%c", &ch);

		switch (ch)
		{
		case'd':														//reverse all sentence
			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
			{
				for (unsigned int i = 0; i < strlen(str_temp[k]) / 2; i++)
					SWAP(str_temp[k][i], str_temp[k][strlen(str_temp[k]) - (i+1)], char);
				for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
					printf("%c", str_temp[k][j]);
				printf("\n");
			}
			break;
		case'e':														//
			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
			{
				for (unsigned int i = 0; i < strlen(str_temp[k]); i++)
					SWAP(str_temp[k][i], str_temp[k][strlen(str_temp[k]) - (i + 1)], char);
				for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
					printf("%c", str_temp[k][j]);
				printf("\n");
			}
			break;
		case'f':
			break;
		case'g':
			while ((ch = getchar()) != '\n') continue;
			scanf("%c %c", &c1, &c2);
			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
			{
				for (unsigned int i = 0; i < strlen(str_temp[k]); i++)
				{
					if (str_temp[k][i] == c1)
						SWAP(c1, c2, char);
				}
				for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
					printf("%c", str_temp[k][j]);
				printf("\n");
			}


			break;
		case'h':
			while (same_flag) 
			{
				for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
				{
					char same_str[128] = { '\n' };
					for (unsigned int i = 0; i < strlen(str_temp[k]) / 2; i++)
					{
						if (str_temp[k][i] == str_temp[k][strlen(str_temp[k]) - (i + 1)])
						{
							same_str[i] = str_temp[k][i];
							same++;
						}
						else
						{
							same_flag = false;
							same += same;
							break;
						}
					}

					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
						printf("%c", str_temp[k][j]);
					printf(": ");

					if (same == 0)
						printf("%d\n", same);
					else {
						for (unsigned int n = 0; n < strlen(same_str); n++)
						{
							if (same_str[n] == ' ')
								continue;
							else
								printf("%c", same_str[n]);
						}
						printf("\n");
					}
					same = 0;
				}
				//마지막에 same_str을 초기화를 해줘야하나?
			}
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