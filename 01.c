#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix3(int matrix[3][3]);
void print_matrix4(int matrix[4][4]);
int determinant(int matrix[3][3]);

int main()
{
	int matrix1[3][3] = { 0 };
	int matrix2[3][3] = { 0 };
	int matrix3[4][4] = { 0 };
	int matrix4[4][4] = { 0 };
	int temp[3][3] = { 0 };

	char command = 0;
	//int det = 0;

	srand((unsigned int)time(NULL));					//�迭 �����ϰ� ����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			matrix1[i][j] = rand() % 3;
	}

	for (int i = 0; i < 3; i++)							
	{
		for (int j = 0; j < 3; j++)
			matrix2[i][j] = rand() % 3;
	}

	/*print_matrix3(matrix1);
	printf("\n");
	print_matrix3(matrix2);*/

	while (1)
	{
		scanf("%c", &command);

		switch (command)
		{
		case 'm':												//����� ����
			print_matrix3(matrix1);
			printf("    *\n");
			print_matrix3(matrix2);
			printf("    =\n");
			
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
					{
						temp[i][j] += matrix1[i][k] * matrix2[k][j];
					}

			print_matrix3(temp);
			break;
		case 'a':												//����� ����
			print_matrix3(matrix1);
			printf("    +\n");
			print_matrix3(matrix2);
			printf("    =\n");

			for(int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					temp[i][j] = matrix1[i][j] + matrix2[i][j];
				}

			print_matrix3(temp);
			break;
		case 'd':												//����� ����
			print_matrix3(matrix1);
			printf("    -\n");
			print_matrix3(matrix2);
			printf("    =\n");

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					temp[i][j] = matrix1[i][j] - matrix2[i][j];
				}

			print_matrix3(temp);
			break;
		case 'r':												//��Ľ��� ��
			print_matrix3(matrix1);
			printf("    =\n");
			printf("    %d\n\n",determinant(matrix1));
			
			print_matrix3(matrix2);
			printf("    =\n");
			printf("    %d\n", determinant(matrix2));
			break;
		case 't':												//��ġ��İ� �� ��Ľ��� ��
			print_matrix3(matrix1);
			printf("    ->\n");

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = matrix1[j][i];
			}
			print_matrix3(temp);
			printf("    =\n");
			printf("    %d\n\n", determinant(temp));

			print_matrix3(matrix2);
			printf("    ->\n");

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = matrix2[j][i];
			}
			print_matrix3(temp);
			printf("    =\n");
			printf("    %d\n", determinant(temp));
			break;
		case 'h':												//33�� 44��ķ� �ٲٰ� ��Ľ��� ����� 4���� 0 4���� 0 44�� 1�� ��ȯ + ��Ľ��� �� ���
			print_matrix3(matrix1);
			printf("    ->\n");
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					if (i == 3 || j == 3) 
					{
						if (i == 3 && j == 3)
							matrix3[i][j] = 1;
						else 
							matrix3[i][j] = 0;
					}
					else
						matrix3[i][j] = matrix1[i][j];
				}
			print_matrix4(matrix3);
			printf("     =\n");
			
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = matrix1[j][i];
			}

			printf("    %d\n\n", determinant(temp));

			print_matrix3(matrix2);
			printf("    ->\n");
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					if (i == 3 || j == 3)
					{
						if (i == 3 && j == 3)
							matrix4[i][j] = 1;
						else
							matrix4[i][j] = 0;
					}
					else
						matrix4[i][j] = matrix2[i][j];
				}
			print_matrix4(matrix4);
			printf("     =\n");

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					temp[i][j] = matrix2[j][i];
			}

			printf("    %d\n", determinant(temp));

			break;
		case 's':												//��İ� �����ϰ� ��ȯ
			srand((unsigned int)time(NULL));
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					matrix1[i][j] = rand() % 3;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					matrix2[i][j] = rand() % 3;
			}
			print_matrix3(matrix1);
			printf("\n");
			print_matrix3(matrix2);
			break;
		case 'q':							//���α׷� ����
			return 0;
			break;
		default:
			printf("enter accurate command\n");
			break;
		}
		while ((command = getchar() != '\n')) continue; // ��������
	}

	return 0;
}

void print_matrix3(int matrix[3][3])
{
	int row = 3, column = 3;
	for (int i = 0; i < row; i++)
	{
		printf("| ");
		for (int j = 0; j < column; j++)
			printf("%d ", matrix[i][j]);
		printf("|\n");
	}
}

void print_matrix4(int matrix[4][4])
{
	int row = 4, column = 4;
	for (int i = 0; i < row; i++)
	{
		printf("| ");
		for (int j = 0; j < column; j++)
			printf("%d ", matrix[i][j]);
		printf("|\n");
	}
}

int determinant(int matrix[3][3])
{
	int det = 0;
	det = (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[2][1] * matrix[1][0])
		- (matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[1][2] * matrix[2][1] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][1]);

	return det;
}