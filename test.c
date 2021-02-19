#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void test()
{
	start();
	char board[row][lin];
	initialize(board);
	display(board);
	while (1)
	{
		int x; int y;
		printf("玩家1回合(棋子为@)\n");
		printf("请输入横坐标:"); scanf("%d", &x);
		printf("请输入纵坐标:"); scanf("%d", &y);
		while (iswrong(board,x,y))
		{
			printf("溢出或已被落子，请重新输入！\n");
			printf("请输入横坐标:"); scanf("%d", &x);
			printf("请输入纵坐标:"); scanf("%d", &y);
		}
		board[x][y] = '@';
		display(board);
		if (iswin(board, x, y) == 1)
		{
			printf("玩家1获胜！！\n\n");
			break;
		}
		printf("玩家2回合(棋子为O)\n");
		printf("请输入横坐标:"); scanf("%d", &x);
		printf("请输入纵坐标:"); scanf("%d", &y);
		while (iswrong(board, x, y))
		{
			printf("溢出或已被落子，请重新输入！\n");
			printf("请输入横坐标:"); scanf("%d", &x);
			printf("请输入纵坐标:"); scanf("%d", &y);
		}
		board[x][y] = 'O';
		display(board);
		if (iswin(board, x, y) == 1)
		{
			printf("玩家2获胜！！\n\n");
			break;
		}
	}
	test();
}

int main()
{
	test();
	return 0;
}
