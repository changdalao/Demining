#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10


void InitBoard(char arr[ROWS][COLS], int row, int col);
void DisplayShow(char arr[ROWS][COLS], int row, int col);
void Set(char arr[ROWS][COLS], int count, int row, int col);
int Getmine(char arr[ROWS][COLS], int x, int y);
void Extend(char mine[COLS][ROWS], int x, int y, int* win, char show[COLS][ROWS]);


#endif //__GAME_H__
