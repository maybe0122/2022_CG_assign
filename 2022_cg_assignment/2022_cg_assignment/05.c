//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <math.h>
//
//typedef struct POINT
//{
//	int check;
//	int x;
//	int y;
//	int z;
//	float len;
//}point;
//
//#define SWAP(a, b, type) do { \
//    type temp; \
//    temp = a;  \
//    a = b;     \
//    b = temp;  \
//} while (0)
//
//void init(point list[], int* index);
//void plus(point list[], int a, int b, int c, int* index);
//void minus(point list[], int* index);
//void print_list(point list[]);
//int point_num(point list[]);
//void len_max(point list[]);
//void len_min(point list[]);
//void len_sort(point list[], int* sflag);
//void d(point list[]);
//void e(point list[], int a, int b, int c, int* index);
//
//int main()
//{
//	char command;
//	int a, b, c;
//	int index = 0;
//	int sflag = 1;
//
//	point list[10];
//	init(list, &index);
//
//	while (1)
//	{
//		fseek(stdin, 0, SEEK_END);
//		printf("Command: ");
//		scanf("%c", &command);
//
//		switch (command)
//		{
//		case'+':
//			fseek(stdin, 0, SEEK_END);
//			scanf("%d %d %d", &a, &b, &c);
//			plus(list, a, b, c, &index);
//			break;
//		case'-':
//			minus(list, &index);
//			break;
//		case'e':
//			fseek(stdin, 0, SEEK_END);
//			scanf("%d %d %d", &a, &b, &c);
//			e(list, a, b, c, &index);
//			break;
//		case'd':
//			d(list);
//			break;
//		case'l':
//			printf("list length: %d\n", point_num(list));
//			break;
//		case'c':
//			init(list, &index);
//			index = 0;
//			break;
//		case'm':
//			len_max(list);
//			break;
//		case'n':
//			len_min(list);
//			break;
//		case's':
//			len_sort(list, &sflag);
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
//void init(point list[], int* index)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		list[i].x = 0;
//		list[i].y = 0;
//		list[i].z = 0;
//		list[i].len = 0;
//		list[i].check = 0;
//	}
//	*index = 0;
//
//	print_list(list);
//}
//
//void plus(point list[], int a, int b, int c, int* index)
//{
//	if (*index == 10)
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			if (list[i].check == 0)
//			{
//				list[i].x = a;
//				list[i].y = b;
//				list[i].z = c;
//				list[i].check = 1;
//				list[i].len = sqrt(a * a + b * b + c * c);
//				break;
//			}
//		}
//	}
//	else
//	{
//		list[*index].x = a;
//		list[*index].y = b;
//		list[*index].z = c;
//		list[*index].check = 1;
//		list[*index].len = sqrt(a * a + b * b + c * c);
//		(*index)++;
//	}
//	print_list(list);
//}
//
//void minus(point list[], int* index)
//{
//	if (*index == 0) *index = *index;
//	else
//		(*index)--;
//
//	list[*index].x = 0;
//	list[*index].y = 0;
//	list[*index].z = 0;
//	list[*index].check = 0;
//	list[*index].len = 0;
//	
//	print_list(list);
//}
//
//void print_list(point list[])
//{
//	for (int i = 9; i >= 0; i--) {
//		printf("-----------\n");
//		if(list[i].check == 0)
//			printf("|%d|\t  |\n", i);
//		else
//			printf("|%d| %d %d %d | %f\n", i, list[i].x, list[i].y, list[i].z, list[i].len);
//	}
//	printf("-----------\n");
//}
//
//int point_num(point list[])
//{
//	int result = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (list[i].check == 1)
//			result++;
//	}
//	return result;
//}
//
//void len_max(point list[])
//{
//	float temp = list[0].len;
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (list[i].check == 1)
//		{
//			if (list[i].len > temp)
//			{
//				SWAP(list[i].len, temp, float);
//				count = i;
//			}
//		}
//	}
//	printf("(%d, %d, %d)\n", list[count].x, list[count].y, list[count].z);
//
//}
//
//void len_min(point list[])
//{
//	float temp = list[0].len;
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (list[i].check == 1)
//		{
//			if (list[i].len < temp)
//			{
//				SWAP(list[i].len, temp, float);
//				count = i;
//			}
//		}
//	}
//	printf("(%d, %d, %d)\n", list[count].x, list[count].y, list[count].z);
//}
//
//void len_sort(point list[], int* sflag)
//{
//	point save[10];
//	int count = 0;
//	
//	for (int i = 0; i < 10; i++)
//	{
//		save[i].check = list[i].check;
//		save[i].len = list[i].len;
//		save[i].x = list[i].x;
//		save[i].y = list[i].y;
//		save[i].z = list[i].z;
//	}
//
//	for (int j = 0; j < 9; j++)
//	{
//		if (save[j].check == 0)
//		{
//			for(int k = j; k < 9; k++)
//				SWAP(save[k], save[k+1], point);
//		}
//	}
//
//	for (int l = 0; l < point_num(save); l++) {					//sort
//		for (int m = 0; m < (point_num(save) - 1) - l; m++) {
//			if (save[m].len > save[m + 1].len) {
//				SWAP(save[m], save[m+1], point);
//			}
//		}
//	}
//
//
//	if (*sflag == 1)	//
//	{
//		print_list(save);
//		*sflag = 0;
//	}
//	else		//
//	{
//		print_list(list);
//		*sflag = 1;
//	}
//}
//
//void d(point list[])
//{
//	list[0].x = 0;
//	list[0].y = 0;
//	list[0].z = 0;
//	list[0].check = 0;
//	list[0].len = 0;
//	print_list(list);
//}
//
//void e(point list[], int a, int b, int c, int* index)
//{
//	if (list[0].check == 0)
//	{
//		list[0].x = a;
//		list[0].y = b;
//		list[0].z = c;
//		list[0].check = 1;
//		list[0].len = sqrt(a * a + b * b + c * c);
//	}
//	else
//	{
//		for (int i = *index; i >= 0; i--)
//			SWAP(list[i+1], list[i], point);
//		
//		list[0].x = a;
//		list[0].y = b;
//		list[0].z = c;
//		list[0].check = 1;
//		list[0].len = sqrt(a * a + b * b + c * c);
//		(*index)++;
//	}
//	
//	print_list(list);
//}