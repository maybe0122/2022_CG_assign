//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <windows.h>
//#include <time.h>
//
//void roadmap();
//void print_map();
//void init_map();
//
//#define SWAP(a, b, type) do { \
//    type temp; \
//    temp = a;  \
//    a = b;     \
//    b = temp;  \
//} while (0)
//
//int map[30][30] = {0, };
//
//int main() //
//{
//	roadmap();
//	while (1)
//	{
//		char command;
//		fseek(stdin, 0, SEEK_END);
//		printf("Command: ");
//		scanf("%c", &command);
//
//		switch (command)
//		{
//		case'R':				//reset
//			system("cls");
//			init_map();
//			roadmap();
//			break;
//		case'r':				//right
//			for (int i = 0; i < 30; i++)
//			{
//				for (int j = 0; j < 29; j++)
//				{
//					SWAP(map[i][j], map[i][j+1], int);
//				}
//			}
//			break;
//		case'l':
//			for (int i = 0; i < 30; i++)
//			{
//				for (int j = 29; j > 0; j--)
//				{
//					SWAP(map[i][j], map[i][j - 1], int);
//				}
//			}
//			break;
//		case'q':				
//			return 0;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void roadmap()
//{
//	int x = 0, y = 0, d_count = 0;
//	int count = 1;
//	int rand1;
//	map[0][0] = count;
//	count++;
//	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, d_flag = false;
//	while (1)
//	{
//		if (map[29][29] == count && flag1 && flag2 && flag3 && flag4) break;
//		srand((unsigned int)time(NULL));
//		if (d_count == 0)					//dirction
//		{
//			rand1 = rand() % 4 + 1;
//			d_count = rand1;
//		}			
//		else if (d_count >= 3)
//		{
//			rand1 = rand() % 2 + 1;
//			d_count = rand1;
//		}
//		else if (d_count <= 2)
//		{
//			rand1 = rand() % 2 + 3;
//			d_count = rand1;
//		}
//
//		int rand2;							//move
//
//		if (rand1 == 1)						//up
//		{
//			if (y > 0)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (y - rand2 < 0)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x][y - i] = count;
//					count++;
//				}
//				y += rand2;
//				flag1 = true;
//			}
//			else {
//				d_count = 0;
//				continue;
//			}
//				
//		}
//		else if (rand1 == 2)		//down
//		{
//			if (y < 29)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (y + rand2 > 30)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x][y + i - 1] = count;
//					count++;
//				}
//				y += rand2;
//				flag2 = true;
//			}
//			else
//			{
//				d_count = 0;
//				continue;
//			}
//		}
//		else if (rand1 == 3)				//left
//		{
//			if (x > 0)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (x - rand2 < 0)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x - i + 1][y] = count;
//					count++;
//				}
//				x -= rand2;
//				flag3 = true;
//			}
//			else
//			{
//				continue;
//				d_count = 0;
//			}
//		}
//		else if (rand1 == 4)								//right
//		{
//			if (x < 29)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (x + rand2 > 30)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x + i - 1][y] = count;
//					count++;
//				}
//				x += rand2;
//				flag4 = true;
//			}
//			else
//			{
//				d_count = 0;
//				continue;
//			}
//		}
//	}
//	print_map();
//}
//
//void print_map()
//{
//	for (int i = 0; i < 30; i++)
//	{
//		for (int j = 0; j < 30; j++)
//			printf("%d\t", map[i][j]);
//		printf("\n");
//	}
//}
//
//void init_map()
//{
//	for (int i = 0; i < 30; i++)
//		for (int j = 0; j < 30; j++)
//			map[i][j] = 0;
//}