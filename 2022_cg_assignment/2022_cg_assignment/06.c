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
//int map[10][10] = {0, };
//
//int main() //¹Ì¿Ï ¤Ð¤Ð
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
//			break;
//		case'l':
//			break;
//		case'q':				//left
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
//		if (map[9][9] == count && flag1 && flag2 && flag3 && flag4) break;
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
//				continue;
//			}
//				
//		}
//		else if (rand1 == 2)		//down
//		{
//			if (y < 9)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (y + rand2 > 10)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x][y + i] = count;
//					count++;
//				}
//				y += rand2;
//				flag2 = true;
//			}
//			else
//				continue;
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
//					map[x - i][y] = count;
//					count++;
//				}
//				x -= rand2;
//				flag3 = true;
//			}
//			else
//				continue;
//		}
//		else if (rand1 == 4)								//right
//		{
//			if (x < 9)
//			{
//				while (1)
//				{
//					rand2 = rand() % 7 + 1;
//					if (x + rand2 > 10)
//						continue;
//					else
//						break;
//				}
//				for (int i = 1; i <= rand2; i++)
//				{
//					map[x + i][y] = count;
//					count++;
//				}
//				x += rand2;
//				flag4 = true;
//			}
//			else
//				continue;
//		}
//	}
//	print_map();
//}
//
//void print_map()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//			printf("%d\t", map[i][j]);
//		printf("\n");
//	}
//}
//
//void init_map()
//{
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++)
//			map[i][j] = 0;
//}