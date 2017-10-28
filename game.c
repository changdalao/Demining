#include"game.h"
void InitBoard(char arr[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = set;
		}
	}
}
void DisplayShow(char arr[ROWS][COLS], int row, int col)		//打印雷盘
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("   ---------------------\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d| ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void Set(char arr[ROWS][COLS], int count, int row, int col)   //布雷
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
int Getmine(char arr[ROWS][COLS], int x, int y)		//统计雷的个数
{
	return arr[x - 1][y - 1] +
		arr[x - 1][y] +
		arr[x - 1][y + 1] +
		arr[x][y + 1] +
		arr[x + 1][y + 1] +
		arr[x + 1][y] +
		arr[x + 1][y - 1] +
		arr[x][y - 1] - 8 * '0';
}
void Extend(char mine[COLS][ROWS], int x, int y, int* win, char show[COLS][ROWS]) 
{
	int i = -1;
	int j = -1;
	for (i = -1; i < 2; ++i)
	{
		for (j = -1; j < 2; ++j)
		{
			if ((i != 0) || (j != 0))
			{
				if (x + i >= 1 && x + i <= COLS - 2 && y + j >= 1 && y + j <= ROWS - 2)
				{
					if (show[x + i][y + j] == '*')
					{
						int count = Getmine(mine, x + i, y + j);
						if (count != 0)
						{
							show[x + i][y + j] = count + '0';
							(*win)++;
						}
						else if (0 == count)
						{
							show[x + i][y + j] = ' ';
							(*win)++;
							Extend(mine, x + i, y + j, win, show);
						}
					}
				}
			}
		}
	}
}