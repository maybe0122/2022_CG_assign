//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <time.h>
//
//void textcolor(int color);
//void init_top();
//void print_board(char b[4][4]);
//void init_bottom();
//void rand_bottom();
//void init_temp();
//void choose_board(char b[4][4], char row, char col);
//void check_board(char row, int col, char row2, int col2, char b1[4][4], char b2[4][4], int* score);
//void copy_board(char board[4][4], char temp[4][4]);
//
//char top_board[4][4] = {0, };
//char top_temp[4][4] = {0, };
//char bottom_board[4][4] = {0, };
//
//int main()
//{ 
//	char row, row2;
//	int col, col2;
//	int score = 100;
//	int limit = 15;
//	init_top();
//	init_temp();
//	rand_bottom();
//
//	while (limit != 0)
//	{
//		print_board(bottom_board);
//		print_board(top_board);
//		printf("score: %d | remaining attempts: %d\n", score, limit);
//		printf("input card 1: ");
//		fseek(stdin, 0, SEEK_END);
//		scanf("%c %d", &row, &col);
//
//		if (row == 'r')
//		{
//			printf("restart game..");
//			Sleep(1000);
//			system("cls");
//			init_temp();
//			init_top();
//			init_bottom();
//			rand_bottom();
//			continue;
//		}
//		else if (row < 'a' || row > 'd' || col < 1 || col > 4)
//		{
//			printf("Enter right input!");
//			Sleep(1300);
//			init_top(top_board);
//			system("cls");
//			continue;
//		}
//		else 
//		{
//			choose_board(top_temp, row, col);
//			print_board(top_temp);
//		}
//
//		printf("input card 2: ");
//		fseek(stdin, 0, SEEK_END);
//		scanf("%c %d", &row2, &col2);
//
//		if (row2 == 'r')
//		{
//			printf("restart game..");
//			Sleep(1000);
//			system("cls");
//			init_temp();
//			init_top();
//			init_bottom();
//			rand_bottom();
//			continue;
//		}
//		else if (row2 < 'a' || row2 > 'd' || col2 < 1 || col2 > 4)
//		{
//			printf("Enter right input!");
//			Sleep(1000);
//			system("cls");
//			continue;
//		}
//		else
//		{
//			check_board(row, col, row2, col2, bottom_board, top_temp, &score);
//			Sleep(1000);
//			system("cls");
//		}
//		limit--;
//	}
//}
//
//
//void init_top()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			top_board[i][j] = '*';
//		}
//	}
//}
//
//void init_temp()
//{
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			top_temp[i][j] = '*';
//}
//
//void init_bottom()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			bottom_board[i][j] = '\0';
//		}
//	}
//}
//
//void print_board(char b[4][4])
//{
//	textcolor(15);
//	printf("  a b c d\n");
//	for (int i = 0; i < 4; i++)
//	{
//		textcolor(15);
//		printf("%d ", i+1);
//		for (int j = 0; j < 4; j++)
//		{
//			if (b[i][j] == 'A')
//				textcolor(1);
//			else if (b[i][j] == 'B')
//				textcolor(2);
//			else if (b[i][j] == 'C')
//				textcolor(3);
//			else if (b[i][j] == 'D')
//				textcolor(4);
//			else if (b[i][j] == 'E')
//				textcolor(5);
//			else if (b[i][j] == 'F')
//				textcolor(6);
//			else if (b[i][j] == 'G')
//				textcolor(7);
//			else if (b[i][j] == 'H')
//				textcolor(8);
//			else
//				textcolor(15);
//			printf("%c ", b[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void rand_bottom()
//{
//	char ch = 'A';
//	int rand1 = 0, rand2 = 0;
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			rand1 = rand() % 4;
//			rand2 = rand() % 4;
//			if (bottom_board[rand1][rand2] == '\0')
//			{
//				bottom_board[rand1][rand2] = ch;
//			}
//			else {
//				j--;
//			}
//		}
//		ch += 1;
//	}
//}
//
//void textcolor(int color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
//
//void choose_board(char b[4][4], char row, char col)
//{
//	if (row == 'a')
//		b[col - 1][0] = 'O';
//	else if (row == 'b')
//		b[col - 1][1] = 'O';
//	else if (row == 'c')
//		b[col - 1][2] = 'O';
//	else
//		b[col - 1][3] = 'O';
//
//}
//
//void check_board(char row, int col, char row2, int col2, char b1[4][4], char b2[4][4], int* score)
//{
//	int num, num2;
//	if (row == 'a')
//		num = 0;
//	else if (row == 'b')
//		num = 1;
//	else if (row == 'c')
//		num = 2;
//	else
//		num = 3;
//
//	if (row2 == 'a')
//		num2 = 0;
//	else if (row2 == 'b')
//		num2 = 1;
//	else if (row2 == 'c')
//		num2 = 2;
//	else
//		num2 = 3;
//		
//	if (b1[col-1][num] == b1[col2-1][num2])
//	{
//		(*score) += 10;
//		b2[col-1][num] = b1[col-1][num];
//		b2[col2-1][num2] = b1[col2-1][num2];
//		copy_board(top_board, top_temp);
//		print_board(top_board);
//	}
//	else
//	{
//		(*score) -= 10;
//
//		b2[col - 1][num] = b1[col - 1][num];
//		b2[col2 - 1][num2] = b1[col2 - 1][num2];
//		print_board(top_temp);
//
//		if (b2[col - 1][num] != '*')
//			top_temp[col2 - 1][num2] = '*';
//		else if (b2[col2 - 1][num2] != '*')
//			top_temp[col - 1][num] = '*';
//		else
//			init_top();
//	}
//	
//}
//
//void copy_board(char board[4][4], char temp[4][4])
//{
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			board[i][j] = temp[i][j];
//}