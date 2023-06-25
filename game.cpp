#include<iostream>
#include<Windows.h>
#include<thread>
#include<chrono>
#include<ctime>
#include <stdlib.h>
#include <conio.h>
#define MYCONSOLE_H
#define MYGRAPHICS_H
#include <windows.h>
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#define _WIN32_WINNT 1537
#endif
#include <WinCon.h>
#define _WIN32_WINNT 0x0500
#include <fstream>        
#include <stdio.h> 
using namespace std;
char ch;
void score(char ch);
void instructions();
void fileresume();
void credits();
void instructions();
void menu();
int endGame()
{
	cout << "\t\t\t\tGame Over!";
	return 1;
}
void game();
void moves()
{
	int count = 15;
	for (int i = 15; i > 0; i--)
	{
		if (i == 0)
		{
			cout << "OUT OF MOVES!!" << endl;
			cout << "GAME OVER!" << endl;
		}
		else
		{
			cout << "Moves: " << count << endl;
			game();
			i--;
			count--;
		}
	}
}
void myLine(int x1, int y1, int x2, int y2, int color1, int color2, int color3) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	//change the color ay changing the values in RGa (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(color1, color2, color3)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void stripes(int x1, int y1, int x2, int y2, int color1, int color2, int color3) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color ay changing the values in RGa (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(color1, color2, color3)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	return false;
}
void myRect(int x1, int y1, int x2, int y2, COLORREF linecolor, COLORREF fillcolor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color ay changing the values in RGa (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, linecolor);
	SelectObject(device_context, pen);
	HBRUSH arush = ::CreateSolidBrush(fillcolor);
	SelectObject(device_context, arush);

	Rectangle(device_context, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(arush);
	ReleaseDC(console_handle, device_context);
}
void myEllipse(int x1, int y1, int x2, int y2, int linecolor, int fillcolor)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color ay changing the values in RGa (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, linecolor);
	SelectObject(device_context, pen);
	HBRUSH arush = ::CreateSolidBrush(fillcolor);  //Fill color is alack
	SelectObject(device_context, arush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(arush);
}
COLORREF square1 RGB(255, 0, 0); COLORREF  linecolor RGB(0, 0, 0);
COLORREF square2 RGB(0, 255, 0); COLORREF  rectangle RGB(0, 0, 200); COLORREF  circle1 RGB(255, 69, 0);
COLORREF  circle2 RGB(255, 215, 0); COLORREF  green RGB(0, 255, 0); COLORREF yellow RGB(0, 120, 0);
void printaoard(int rs, int cs, int a[8][8]);
void squarecandy1(int r, int c)
{
	myRect(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), linecolor, square1);
}
void squarecandy2(int r, int c)
{
	myRect(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), linecolor, square2);
}
void rectanglecandy(int r, int c)
{
	myRect(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), linecolor, rectangle);
}
void circularcandy1(int r, int c)
{
	myEllipse(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), linecolor, circle1);
}
void circularcandy2(int r, int c)
{
	myEllipse(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), linecolor, circle2);
}
void stripedsquarecandy1(int r, int c)
{
	squarecandy1(r, c);
	//stripes(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), 0, 0, 0);
	//stripes(600 + (c * 80), 220 + 16 + (r * 80), 600 + 40 + (c * 80), 220 + 16 + (r * 80), 0, 0, 0);
	//stripes(600 + (c * 80), 220 + 24 + (r * 80), 600 + 40 + (c * 80), 220 + 24 + (r * 80), 0, 0, 0);
	//stripes(600 + (c * 80), 220 + 31 + (r * 80), 600 + 40 + (c * 80), 220 + 31 + (r * 80), 0, 0, 0);
}
void stripedsquarecandy2(int r, int c)
{
	squarecandy2(r, c);
	stripes(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 16 + (r * 80), 600 + 40 + (c * 80), 220 + 16 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 24 + (r * 80), 600 + 40 + (c * 80), 220 + 24 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 31 + (r * 80), 600 + 40 + (c * 80), 220 + 31 + (r * 80), 0, 0, 0);
}
void stripedrectanglecandy(int r, int c)
{
	rectanglecandy(r, c);
	stripes(600 + (c * 80), 220 + (r * 80), 600 + 40 + (c * 80), 220 + 40 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 16 + (r * 80), 600 + 40 + (c * 80), 220 + 16 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 24 + (r * 80), 600 + 40 + (c * 80), 220 + 24 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 31 + (r * 80), 600 + 40 + (c * 80), 220 + 31 + (r * 80), 0, 0, 0);
}
void stripedcircularcandy1(int r, int c)
{
	circularcandy1(r, c);
	stripes(600 + 4 + (c * 80), 220 + 8 + (r * 80), 600 + 40 - 5 + (c * 80), 220 + 8 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 20 + (r * 80), 600 + 40 + (c * 80), 220 + 20 + (r * 80), 0, 0, 0);
	stripes(600 + 4 + (c * 80), 220 + 40 - 8 + (r * 80), 600 + 40 - 5 + (c * 80), 220 + 40 - 8 + (r * 80), 0, 0, 0);
}
void stripedcircularcandy2(int r, int c)
{
	circularcandy2(r, c);
	stripes(600 + 4 + (c * 80), 220 + 8 + (r * 80), 600 + 40 - 5 + (c * 80), 220 + 8 + (r * 80), 0, 0, 0);
	stripes(600 + (c * 80), 220 + 20 + (r * 80), 600 + 40 + (c * 80), 220 + 20 + (r * 80), 0, 0, 0);
	stripes(600 + 4 + (c * 80), 220 + 40 - 8 + (r * 80), 600 + 40 - 5 + (c * 80), 220 + 40 - 8 + (r * 80), 0, 0, 0);
}
void aomacandy(int r, int c)
{
	myLine(600 + (c * 80), 220 + 4 + (r * 80), 600 + (c * 80), 220 + 16 + (r * 80), 255, 215, 0);

}
bool replaceaoard(int a[8][8])
{
	int flag = 0;
	Sleep(1000);
c:	for (int j = 0; j < 8; j++)
{
	if (a[0][j] == 0)
	{
		a[0][j] = rand() % 5 + 1;
		Sleep(100);
		system("cls");
		printaoard(8, 8, a);
	}
}
for (int i = 1; i < 8; i++)
{
	for (int j = 0; j < 8; j++)
	{
		if (a[i][j] == 0)
		{
			swap(a[i][j], a[i - 1][j]);
			Sleep(100);
			system("cls");
			printaoard(8, 8, a);
			i = 1;
			j = 0;
			flag = 1;
			goto c;
		}
	}
}
return flag;
}
bool checkboard(int b[8][8], int& row, int& column, int& x, int& y, int key, int repetition)
{
	Sleep(400);
	int flag = 0;




	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i < 6 && i > 1 && j < 6 && j > 1)
			{
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j + 1] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}

				if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[i + 1][j] && b[i - 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}
				if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j + 2] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j - 1] = 0;
					b[i][j - 2] = 0;
					flag = 1;
				}

				if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i + 2][j] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i - 1][j] = 0;
					b[i - 2][j] = 0;
					flag = 1;
				}
			}
			else if (i == 0)
			{
				if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i + 2][j] = 0;
					flag = 1;
				}
				if (j < 1)
				{
					if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j - 1] = 0;
						b[i][j - 2] = 0;
						flag = 1;
					}
				}
				if (j < 6)
				{
					if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j + 2] = 0;
						flag = 1;
					}
				}
			}
			else if (i == 1)
			{
				if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i + 2][j] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[i + 1][j] && b[i - 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}
				if (j < 1)
				{
					if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j - 1] = 0;
						b[i][j - 2] = 0;
						flag = 1;
					}
				}
				if (j < 6)
				{
					if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j + 2] = 0;
						flag = 1;
					}
				}
			}
			else if (i == 7)
			{
				if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i - 1][j] = 0;
					b[i - 2][j] = 0;
					flag = 1;
				}
				if (j < 1)
				{
					if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j - 1] = 0;
						b[i][j - 2] = 0;
						flag = 1;
					}
				}
				if (j < 6)
				{
					if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j + 2] = 0;
						flag = 1;
					}
				}
			}
			else if (i == 6)
			{
				if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i - 1][j] = 0;
					b[i - 2][j] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i - 1][j] && b[i + 1][j] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}
				if (j < 1)
				{
					if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j - 1] = 0;
						b[i][j - 2] = 0;
						flag = 1;
					}
				}
				if (j < 6)
				{
					if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i][j + 2] = 0;
						flag = 1;
					}
				}
			}
			else if (j == 0)
			{
				if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j + 2] = 0;
					flag = 1;
				}
				if (i > 1)
				{
					if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i - 1][j] = 0;
						b[i - 2][j] = 0;
						flag = 1;
					}
				}
				if (i < 6)
				{
					if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i + 2][j] = 0;
						flag = 1;
					}
				}
			}
			else if (j == 1)
			{
				if (b[i][j] == b[i][j + 1] + 5 && b[i][j + 1] == b[i][j + 2] && b[i][j + 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j + 2] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j + 1] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}
				if (i > 1)
				{
					if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i - 1][j] = 0;
						b[i - 2][j] = 0;
						flag = 1;
					}
				}
				if (i < 6)
				{
					if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i + 2][j] = 0;
						flag = 1;
					}
				}
			}
			else if (j == 7)
			{
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j - 1] = 0;
					b[i][j - 2] = 0;
					flag = 1;
				}
				if (i > 1)
				{
					if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i - 1][j] = 0;
						b[i - 2][j] = 0;
						flag = 1;
					}
				}
				if (i < 6)
				{
					if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i + 2][j] = 0;
						flag = 1;
					}
				}
			}
			else if (j == 6)
			{
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j - 2] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					b[i][j - 1] = 0;
					b[i][j - 2] = 0;
					flag = 1;
				}
				if (b[i][j] == b[i][j - 1] + 5 && b[i][j - 1] == b[i][j + 1] && b[i][j - 1] != 0)
				{
					b[i][j] = 0;
					b[i][j + 1] = 0;
					b[i][j - 1] = 0;
					b[i + 1][j] = 0;
					b[i - 1][j] = 0;
					b[i + 1][j - 1] = 0;
					b[i + 1][j + 1] = 0;
					b[i - 1][j - 1] = 0;
					b[i - 1][j + 1] = 0;

					flag = 1;
				}
				if (i > 1)
				{
					if (b[i][j] == b[i - 1][j] + 5 && b[i - 1][j] == b[1 - 2][j] && b[i][j - 1] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i - 1][j] = 0;
						b[i - 2][j] = 0;
						flag = 1;
					}
				}
				if (i < 6)
				{
					if (b[i][j] == b[i + 1][j] + 5 && b[i + 1][j] == b[i + 2][j] && b[i + 1][j] != 0)
					{
						b[i][j] = 0;
						b[i][j + 1] = 0;
						b[i][j - 1] = 0;
						b[i + 1][j] = 0;
						b[i - 1][j] = 0;
						b[i + 1][j - 1] = 0;
						b[i + 1][j + 1] = 0;
						b[i - 1][j - 1] = 0;
						b[i - 1][j + 1] = 0;

						b[i + 2][j] = 0;
						flag = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i][j + 3] && b[i][j] == b[i][j + 4] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i][j + 1] = 0;
				b[i][j + 2] += 5;
				b[i][j + 3] = 0;
				b[i][j + 4] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j] && b[i][j] == b[i + 3][j] && b[i][j] == b[i + 4][j] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i + 1][j] = 0;
				b[i + 2][j] += 5;;
				b[i + 3][j] = 0;
				b[i + 4][j] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i][j + 3] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i][j + 1] = 0;
				b[i][j + 2] += 5;
				b[i][j + 3] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j] && b[i][j] == b[i + 3][j] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i + 1][j] += 5;
				b[i + 2][j] = 0;
				b[i + 3][j] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i][j + 1] = 0;
				b[i][j + 2] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j] && b[i][j] != 0)
			{
				b[i][j] = 0;
				b[i + 1][j] = 0;
				b[i + 2][j] = 0;
				i = 0;
				j = 0;
				flag = 1;
			}
		}
	}

	if (flag == 0 && repetition == 0)
	{
		if (key == 1 && column >= 0)
		{
			swap(b[row][column], b[row][column + 1]);
			x = x + 80;
			column = column + 1;
		}
		if (key == 2 && row >= 0)
		{
			swap(b[row][column], b[row + 1][column]);
			y = y + 80;
			row = row + 1;
		}
		if (key == 3 && column <= 7)
		{
			swap(b[row][column], b[row][column - 1]);
			x = x - 80;
			column = column - 1;
		}
		if (key == 4 && row <= 7)
		{
			swap(b[row][column], b[row - 1][column]);
			y = y - 80;
			row = row - 1;
		}
	}

	return flag;
}
void printaoard(int rs, int cs, int a[8][8])
{
	int x1 = 600, y1 = 220;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 1)
			{
				squarecandy1(i, j);
			}
			if (a[i][j] == 2)
			{
				squarecandy2(i, j);
			}
			if (a[i][j] == 3)
			{
				circularcandy1(i, j);
			}
			if (a[i][j] == 4)
			{
				rectanglecandy(i, j);
			}
			if (a[i][j] == 5)
			{
				circularcandy2(i, j);
			}
			if (a[i][j] == 6)
			{
				stripedsquarecandy1(i, j);
			}
			if (a[i][j] == 7)
			{
				stripedsquarecandy2(i, j);
			}
			if (a[i][j] == 8)
			{
				stripedcircularcandy1(i, j);
			}
			if (a[i][j] == 9)
			{
				stripedrectanglecandy(i, j);
			}
			if (a[i][j] == 10)
			{
				stripedcircularcandy2(i, j);
			}
			if (a[i][j] == 11)
			{
				aomacandy(i, j);
			}

		}
		/*int x = 20, y = 20;
		for (int i = 0; i <= 8; i++)
		{
			myLine(x, 20, x, 580, 60, 60 , 60 );
			x = x + 70;
			myLine(20, y, 580, y, 60 , 60 , 60 );
			y = y + 70;
		}*/

	}
}
void selectionControl(int a[8][8])
{
	int key = 0;
	int x = 585;
	int y = 205;
	int i = 0, j = 0;
a:  myRect(x, y, x + 70, y + 70, linecolor, square1);
	printaoard(8, 8, a);
	while (1)
	{
		Sleep(100);
		if (isCursorKeyPressed(key))
		{
			myRect(x, y, x + 70, y + 70, linecolor, linecolor);
			if (key == 1 && j > 0)
			{
				j = j - 1;
				x = x - 80;
			}
			if (key == 2 && i > 0)
			{
				i = i - 1;
				y = y - 80;
			}
			if (key == 3 && j < 7)
			{
				j = j + 1;
				x = x + 80;
			}
			if (key == 4 && i < 7)
			{
				i = i + 1;
				y = y + 80;
			}
			Sleep(10);
			myRect(x, y, x + 70, y + 70, linecolor, green);
			printaoard(8, 8, a);
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			myRect(x, y, x + 70, y + 70, linecolor, yellow);
			printaoard(8, 8, a);
			int flag = 0;
			int repetition = 0;
			while (flag == 0)
			{
				if (isCursorKeyPressed(key))
				{
					if (key == 1 && j > 0)
					{
						swap(a[i][j], a[i][j - 1]);
						j = j - 1;
						x = x - 80;
						myRect(x, y, x + 70, y + 70, linecolor, green);
						printaoard(8, 8, a);
					d:	if (checkboard(a, i, j, x, y, key, repetition))
					{
						if (replaceaoard(a))
						{
							repetition = 1;
							system("cls");
							printaoard(8, 8, a);
							Sleep(500);
							goto d;
						}
					}
					}
					else if (key == 2 && i > 0)
					{
						swap(a[i][j], a[i - 1][j]);
						i = i - 1;
						y = y - 80;
						system("cls");
						myRect(x, y, x + 70, y + 70, linecolor, green);
						printaoard(8, 8, a);
					e:	if (checkboard(a, i, j, x, y, key, repetition))
					{
						if (replaceaoard(a))
						{
							repetition = 1;
							system("cls");
							printaoard(8, 8, a);
							Sleep(500);
							goto e;
						}
					}

					}
					else if (key == 3 && j < 7)
					{
						swap(a[i][j], a[i][j + 1]);
						j = j + 1;
						x = x + 80;
						system("cls");
						myRect(x, y, x + 70, y + 70, linecolor, green);
						printaoard(8, 8, a);

					f:	if (checkboard(a, i, j, x, y, key, repetition))
					{
						if (replaceaoard(a))
						{
							repetition = 1;
							system("cls");
							printaoard(8, 8, a);
							Sleep(500);
							goto f;
						}
					}
					}
					else if (key == 4 && i < 7)
					{

						swap(a[i][j], a[i + 1][j]);
						i = i + 1;
						y = y + 80;
						system("cls");
						myRect(x, y, x + 70, y + 70, linecolor, green);
						printaoard(8, 8, a);

					g:	if (checkboard(a, i, j, x, y, key, repetition))
					{
						if (replaceaoard(a))
						{
							repetition = 1;
							system("cls");
							printaoard(8, 8, a);
							Sleep(200);
							goto g;
						}
					}

					}
					system("cls");
					flag = 1;
					goto a;
				}
			}

		}

	}
}
void game()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	int aoard[8][8];
	int flag = 0;
	srand(time(NULL));
a:	for (int i = 0; i < 8; i++)
{
	for (int j = 0; j < 8; j++)
	{
		aoard[i][j] = rand() % 5 + 1;
	}
}
for (int i = 0; i < 8; i++)
{
	for (int j = 0; j < 6; j++)
	{
		if (aoard[i][j] == aoard[i][j + 1] && aoard[i][j] == aoard[i][j + 2])
		{
			flag = 1;
		}
	}
}
for (int i = 0; i < 6; i++)
{
	for (int j = 0; j < 8; j++)
	{
		if (aoard[i][j] == aoard[i + 1][j] && aoard[i][j] == aoard[i + 2][j])
		{
			flag = 1;
		}
	}

}
if (flag == 1)
{
	flag = 0;
	goto a;
}
//thread t1{ timer };
printaoard(8, 8, aoard);
selectionControl(aoard);
cout << endl;
getchar();
}
void score(char ch)
{
	cout << "Player name : " << ch << " score : " << 150;
}
void menu()
{

	int choice;

	cout << "\tWelcome to Candy Crush Game in C++\n";
	cout << "Enter your name \n";
	cin >> ch;
	do {
		cout << "Press 1. To start the game\n";
		cout << "Press 2. To view credis\n";
		cout << "Press 3. To view scores\n";
		cout << "Press 4. To view instructions\n";
		cout << "Press 5. To Load a previous game\n";
		cout << "Press 6. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			game();
			break;
		case 2:
			credits();
			break;
		case 3:
			score(ch);
			break;
		case 4:
			instructions();
			break;
		case 5:
			fileresume();
			break;
		case 6:
			cout << "Thank you for playing Candy Crush\n";
			break;
		default:
			cout << "Wrong output enter again\n";
			cin >> choice;
			break;
		}
	} while (choice != 6);
}
void credits()
{
	cout << "\tTHIS GAME HAS BEEN DEVELOPED USING C++\n";
	cout << "Our group members\n";
	cout << "\t________________________________________\n";
	cout << "\t|\tIbrahim Asif     21L-6110      |\n";
	cout << "\t|\tFaiq Ali         21L-5842      |\n";
	cout << "\t|\tRahim Abbas      21L-5772      |\n";
	cout << "\t|\tMujtaba Ahmad    21L-6058      |\n";
	cout << "\t|______________________________________|\n";
	cout << "*************************\n";
}
void fileresume()
{
	int choice;
	do {
		cout << "Press 1. To load the previous game\n";
		cout << "Press 2. To save the current progress\n";
		cin >> choice;
		if (choice == 1)
		{
			ifstream file1;
			file1.open("Save1.txt");
		}
		else if (choice == 2) {
			int stage = 1, score = 0;
			ofstream file1("Save1.txt");
			file1 << "Stage = " << stage << endl;
			file1 << "Score = " << score << endl;
			file1.close();
			cout << "Game saved to Save1.txt\n";
		}
		else
			cout << "Error! Invalid Value. Input again\n";
	} while (choice == 1 || choice == 2);
}
void instructions()
{
	cout << "\t\t\t\t\t|-----------|" << endl;
	cout << "\t\t\t\t\t|   RULES   |" << endl;
	cout << "\t\t\t\t\t|-----------|" << endl << endl << endl;
	cout << "                                         _________ " << endl;
	cout << " _______________________________________|EASY MODE|_____________________________________" << endl;
	cout << "|1: GRID VIEW=  8/8.\t\t\t\t\t\t\t\t\t|" << endl;
	cout << "|2: There are total 64 candies in a board.\t\t\t\t\t\t|" << endl;
	cout << "|3: There are total 8 types of candies \t|" << endl;
	cout << "|_______________________________________________________________________________________|" << endl << endl << endl;
}
int main()
{
	menu();
	return 0;
}
