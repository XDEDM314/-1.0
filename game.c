#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void start()
{
	int i; printf("请输入1开始游戏:"); scanf("%d", &i);
	while (1)
	{
		if (i == 1)
		{
			printf("游戏开始！\n\n\n");
			break;
		}
		else
		{
			printf("无法开始，请重新输入:"); scanf("%d", &i);
		}
	}
}
void initialize(char board[row][lin])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			board[i][j] = '+';
		}
	}
}
void display(char board[row][lin])
{
	for (int p = 0; p < 31; p++)
	{
		printf("%2d ", p);
	}
	printf("\n");
	for (int i = 1; i <31; i++)
	{
		printf("%2d ", i);
		for (int j = 1; j < 31; j++)
		{
			printf(" %c ",board[i][j]);
		}
		printf("\n");
	}
}
int iswrong(char board[row][lin], int x, int y)
{
	if (board[x][y]!= '+'||x<1||x>30||y<1||y>30)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int judge(int i, char board[row][lin], int x, int y)
{
	int k1 = 0; int k2 = 0;
	switch (i)
	{
	case 1:
		while (board[x][y] == board[x-k1-1][y])
		{
			k1++;
		}
		while (board[x][y] == board[x+k2+1][y])
		{
			k2++;
		}
		if (k1 + k2 == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case 2:
		while (board[x][y] == board[x][y - k1 - 1])
		{
			k1++;
		}
		while (board[x][y] == board[x][y + k2 + 1])
		{
			k2++;
		}
		if (k1 + k2 == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case 3:
		while (board[x][y] == board[x - k1 - 1][y - k1 - 1])
		{
			k1++;
		}
		while (board[x][y] == board[x + k2 + 1][y + k2 + 1])
		{
			k2++;
		}
		if (k1 + k2 == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	case 4:
		while (board[x][y] == board[x - k1 - 1][y + k1 + 1])
		{
			k1++;
		}
		while (board[x][y] == board[x + k2 + 1][y - k2 - 1])
		{
			k2++;
		}
		if (k1 + k2 == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	}
}
int iswin(char board[row][lin], int x, int y)
{
	for (int i = 1; i < 5; i++)
	{
		if (judge(i,board,x,y) == 1)
		{
			return 1;
			break;
		}
	}
	return 0;
}
