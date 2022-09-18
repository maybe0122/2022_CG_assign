//#define _CRT_SECURE_NO_WARNINGS
//#define MOVE 50
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdbool.h>
//#include <time.h>
//
//#define SWAP(a, b, type) do { \
//    type temp; \
//    temp = a;  \
//    a = b;     \
//    b = temp;  \
//} while (0)
//
//
//void coord_xy(int *x, int *y);
//void move_rect(int *x, int *y, char ch, bool flag);
//bool collide(int* x, int* y);
//void print_rect(int *x, int *y);
//bool out_of_range(int* x, int* y, bool flag);
//
//int main()
//{
//	char command;
//	int x[4] = { 0, };
//	int y[4] = { 0, };
//	bool rect_flag = true;						//true일때 1번 rect이동
//	int count = 0;
//
//	coord_xy(x, y);
//
//	while (1)
//	{
//		fseek(stdin, 0, SEEK_END);
//		printf("Command: ");
//		scanf("%c", &command);
//
//		if (count % 2 == 0) rect_flag = true;
//		else rect_flag = false;
//
//		switch (command)
//		{
//		case 'w':							//up
//			move_rect(x, y, 'w', rect_flag);
//			break;		
//		case 'a':							//left
//			move_rect(x, y, 'a', rect_flag);
//			break;	
//		case 's':							//down
//			move_rect(x, y, 's', rect_flag);
//			break;
//		case 'd':							//right
//			move_rect(x, y, 'd', rect_flag);
//			break;
//		default:
//			printf("Wrong command!\nTry again\n");
//			continue;
//			break;
//		}
//		count++;
//	}
//
//
//}
//
//void coord_xy(int* x, int* y)  //init rect
//{
//	srand((unsigned int)time(NULL));
//	while (1)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			x[i] = rand() % 800;
//			if (((i == 2) && x[0] == x[1]) || ((i == 3) && x[2] == x[3])) i--;
//
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			y[i] = rand() % 600;
//			if (((i == 2) && y[0] == y[1]) || ((i == 3) && y[2] == y[3])) i--;
//		}
//
//		if (x[0] > x[1]) SWAP(x[0], x[1], int);			//생성된 좌표 정렬
//		if (x[2] > x[3]) SWAP(x[2], x[3], int);
//		if (y[0] > y[1]) SWAP(y[0], y[1], int);
//		if (y[2] > y[3]) SWAP(y[2], y[3], int);
//
//		if (!collide(x, y)) break;						//처음 생성시 충돌하면 다시 생성
//	}
//	print_rect(x, y);
//}
//
//void move_rect(int* x, int* y, char ch, bool flag)		//move rect
//{
//	if (flag == true)								//rect1 move
//	{
//		switch (ch)
//		{
//		case 'w':							//up
//			y[0] += MOVE, y[1] += MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				y[0] -= MOVE, y[1] -= MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 'a':							//left
//			x[0] += MOVE, x[1] += MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				x[0] -= MOVE, x[1] -= MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 's':							//down
//			y[0] -= MOVE, y[1] -= MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				y[0] += MOVE, y[1] += MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 'd':							//right
//			x[0] -= MOVE, x[1] -= MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				x[0] += MOVE, x[1] += MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		default:
//			break;
//		}
//	}
//	else if (flag == false)									//rect2 move
//	{
//		switch (ch)
//		{
//		case 'w':							//up
//			y[2] += MOVE, y[3] += MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				y[2] -= MOVE, y[3] -= MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 'a':							//left
//			x[2] += MOVE, x[3] += MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				x[2] -= MOVE, x[3] -= MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 's':							//down
//			y[2] -= MOVE, y[3] -= MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				y[2] += MOVE, y[3] += MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		case 'd':							//right
//			x[2] -= MOVE, x[3] -= MOVE;
//			if (out_of_range(x, y, flag))
//			{
//				printf("Out of Range!\n");
//				x[2] += MOVE, x[3] += MOVE;
//			}
//			else
//			{
//				if (collide(x, y))
//				{
//					printf("Rectangle 1 & Rectangle 2 Collide!!\n");
//					exit(1);
//				}
//				print_rect(x, y);
//			}
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//bool collide(int* x, int* y)								//collide check true col / false not
//{
//	if (x[1] < x[2] || x[3] < x[0])
//		return false;
//	else
//	{
//		if (y[2] > y[1] || y[0] > y[3])
//			return false;
//		else
//			return true;
//	}
//}
//
//void print_rect(int* x, int* y)
//{
//	printf("Rect 1: (%d, %d) (%d, %d)\n", x[0], y[0], x[1], y[1]);
//	printf("Rect 2: (%d, %d) (%d, %d)\n", x[2], y[2], x[3], y[3]);
//}
//
//bool out_of_range(int* x, int* y, bool flag)			//true oor false not oor
//{
//	if (flag)	//r1
//		if (x[0] < 0 || x[1] > 800 || y[0] < 0 || y[1] > 600) return true;
//		else return false;
//	else		//r2
//		if (x[2] < 0 || x[3] > 800 || y[2] < 0 || y[3] > 600) return true;
//		else return false;
//}