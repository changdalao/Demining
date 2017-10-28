#include"game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int x = 0;
	int y = 0;
	int win = 0;
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	DisplayShow(show, ROW, COL);
	Set(mine,COUNT,ROW,COL);
	while (win<ROW*COL-COUNT)
	{
		
		printf("«Î ‰»Î◊¯±Í>");
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("ƒ„±ª’®À¿¡À£°\n");
			DisplayShow(mine, ROW, COL);
			break;
		}
		else
		{
			int count = Getmine(mine, x, y);
			show[x][y] = count+'0';
			win++;
			Extend(mine, x, y, &win, show);
			DisplayShow(show, ROW, COL);
			
		}
	}
	if (win >= ROW*COL - COUNT)
		printf("win!\n");
}
void menu()
{
	printf("********************************\n");
	printf("*********1.piay   2.exit********\n");
	printf("********************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("«Î—°‘Ò£∫>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("exit game!\n");
			return 0;
		default:
			printf(" ‰»Î¥ÌŒÛ£°");
		}
	} while (input);
	return 0;

}
