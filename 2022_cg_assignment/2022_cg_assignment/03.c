//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdbool.h>
//
//#define SWAP(a, b, type) do { \
//    type temp; \
//    temp = a;  \
//    a = b;     \
//    b = temp;  \
//} while (0)
//
//int main()
//{
//	FILE* fp = NULL;
//	char fname[128];
//	char buffer[128];
//	char temp[128] = {	'\0', };
//	char str_temp[10][128] = { '\0', };
//	char ch, c1, c2;
//	int count = 0;
//	int same = 0;
//	int n = 1;
//	bool same_flag = true;
//	bool e_flag = true;
//
//	printf("input data file name: ");
//	scanf("%s", fname);
//
//	while ((ch = getchar()) != '\n') continue;							//remove buffer
//
//	if ((fp = fopen(fname, "r")) == NULL)
//	{
//		printf("Wrong file name!\n");
//		exit(1);
//	}
//
//	while (fgets(buffer, sizeof(buffer), fp) != NULL)
//	{
//		if(buffer[strlen(buffer) - 1] == '\n')							//remove \n
//			buffer[strlen(buffer) - 1] = '\0';
//
//		strcpy(str_temp[count], buffer);
//		printf("%s", str_temp[count]);
//		count++;
//		printf("\n");
//	}
//
//	while (1)
//	{
//		printf("command: ");
//		fseek(stdin, 0, SEEK_END);
//		scanf("%c", &ch);
//
//		switch (ch)
//		{
//		case'd':														//reverse all sentence
//			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//			{
//				for (unsigned int i = 0; i < strlen(str_temp[k]) / 2; i++)
//					SWAP(str_temp[k][i], str_temp[k][strlen(str_temp[k]) - (i+1)], char);
//				for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//					printf("%c", str_temp[k][j]);
//				printf("\n");
//			}
//			break;
//		case'e':														
//			if (e_flag) 
//			{
//				for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//				{
//					char new_temp[128] = { '\0', };
//					char save_temp[128] = { '\0', };
//					memmove(new_temp, str_temp[k], sizeof(str_temp));
//
//					for (unsigned int i = 0; i < 128; i++)
//					{
//						int limit = 0;
//						if (strlen(new_temp) % 3 == 0)
//							limit = strlen(new_temp) / 3 - 1;
//						else
//							limit = strlen(new_temp) / 3;
//
//						if (i == 5 * n - 2 && !(limit == n - 1))
//						{
//							save_temp[i] = '@';
//							save_temp[i + 1] = '@';
//							n++;
//							i++;
//						}
//						else
//							save_temp[i] = new_temp[i - ((n - 1) * 2)];
//					}
//					memmove(str_temp[k], save_temp, strlen(save_temp));
//					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//						printf("%c", str_temp[k][j]);
//					printf("\n");
//					n = 1;
//				}
//				e_flag = false;
//			}
//			else 
//			{
//				for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//				{
//					for (unsigned int i = 0; str_temp[k][i] != '\0'; i++)
//					{
//						if ((str_temp[k][i] == '@'))
//						{
//							for (int m = i; str_temp[k][m] != '\0'; m++)
//								str_temp[k][m] = str_temp[k][m+1];
//							i--;
//						}
//					}
//					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//						printf("%c", str_temp[k][j]);
//					printf("\n");
//				}
//				e_flag = true;
//				
//			}
//			break;
//		case'f':
//			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//			{
//				int count1 = -1;
//				if (!e_flag) // @ trun
//				{
//					for (int m = 0; str_temp[k][m] != '\0'; m++)
//					{
//						count1++;
//						if ((str_temp[k][m] == '@' && str_temp[k][m + 1] == '@'))
//						{
//							count1--;
//							SWAP(str_temp[k][m - (count1 + 1)], str_temp[k][m - 1], char);
//							m += 1;
//							count1 = -1;
//						}
//						else if (m == strlen(str_temp[k])- 1)
//							SWAP(str_temp[k][m - count1], str_temp[k][m], char);
//					}
//					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//						printf("%c", str_temp[k][j]);
//					printf("\n");
//				}
//				else		// space turn 
//				{
//					int space_count = 0;
//					for (int m = 0; str_temp[k][m] != '\0'; m++)
//					{
//						count1++;
//						if (str_temp[k][m] == ' ')
//						{
//							space_count++;
//							count1--;
//							for(int i = 0; i < (count1+1) / 2; i++)
//								SWAP(str_temp[k][m - (count1 - i + 1)], str_temp[k][m - (i+1)], char);
//							count1 = -1;
//						}
//						else if (m == strlen(str_temp[k]) - 1)
//						{
//							if (space_count == 0) break;
//							for (int i = 0; i < (count1+1) / 2; i++)
//								SWAP(str_temp[k][m - count1 + i], str_temp[k][m - i], char);
//						}
//					}
//					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//						printf("%c", str_temp[k][j]);
//					printf("\n");
//				}
//			}
//			break;
//		case'g':
//			printf("Enter c1 c2: ");
//			fseek(stdin, 0, SEEK_END);
//			scanf("%c %c", &c1, &c2);
//			for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//			{
//				for (unsigned int i = 0; i < strlen(str_temp[k]); i++)
//				{
//					if (str_temp[k][i] == c1)
//						str_temp[k][i] = c2;
//				}
//				for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//					printf("%c", str_temp[k][j]);
//				printf("\n");
//			}
//			break;
//		case'h':
//			while (same_flag) 
//			{
//				for (unsigned int k = 0; k < sizeof(str_temp) / sizeof(str_temp[0]); k++)
//				{
//					char same_str[128] = { '\n' };
//					for (unsigned int i = 0; i < strlen(str_temp[k]) / 2; i++)
//					{
//						if (str_temp[k][i] == str_temp[k][strlen(str_temp[k]) - (i + 1)])
//						{
//							same_str[i] = str_temp[k][i];
//							same++;
//						}
//						else
//						{
//							same_flag = false;
//							same += same;
//							break;
//						}
//					}
//
//					for (unsigned int j = 0; j < strlen(str_temp[k]); j++)
//						printf("%c", str_temp[k][j]);
//					printf(": ");
//
//					if (same == 0)
//						printf("%d\n", same);
//					else {
//						for (unsigned int n = 0; n < strlen(same_str); n++)
//						{
//							if (same_str[n] == ' ')
//								continue;
//							else
//								printf("%c", same_str[n]);
//						}
//						printf("\n");
//					}
//					same = 0;
//				}
//			}
//			same_flag = true;
//			break;
//		case'q':
//			exit(1);
//			break;
//		default:
//			printf("Wrong command!\nTry again\n");
//			break;
//		}
//	}
//
//	fclose(fp);
//}