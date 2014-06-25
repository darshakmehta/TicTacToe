#include "stdafx.h"
#include "TicTacToe.h"
#include<iostream>
using namespace std;

TicTacToe::TicTacToe()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = 0;
		}
	}
}


TicTacToe::~TicTacToe()
{
}

int TicTacToe::hor_check(int t)
{
	int i, j, flag = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{

			if (a[i][j] == t)
				flag = 1;
			else
				flag = 0;
					break;
		}
		if (flag)
			break;
	}
	if (flag)
		return 1;
	else
		return 0;
}
int TicTacToe::gameover_check()
{
	int i, j,flag;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] != 0)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag==0)
			break;
	}
	if (flag)
	{
		cout << "Match Drawn!" << endl;
	}
	return flag;
	
}
int TicTacToe::ver_check(int t)
{
	int i, j, flag;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			if (a[i][j] == t)
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			break;
	}
	if (flag)
		return 1;
	else
		return 0;
}

int TicTacToe::diagonal_check(int t)
{
	
	if ((a[0][0] == t && a[1][1] == t && a[2][2] == t) || (a[0][2] == t &&a[1][1] == t&&a[2][0] == t))
	{

		if (a[1][1] == 1)
			cout << "player 1 wins" << endl;
		else
			cout << "player 2 wins" << endl;
		return 0;
	}
	return 1;
}
void TicTacToe::input1()
{
	int x, y;
	cout << "Enter the position first player (x,y)" << endl;
	cin >> x;
	cin >> y;
	if (x > 3 || y > 3 || x < 1 || y < 1 || a[x - 1][y - 1] != 0)
	{
		if (x == 0 || y == 0)
		{
			cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
			goto there2;
		}
		else if (a[x - 1][y - 1] != 0 &&( x < 4 ||y<4 ||x>0 ||y>0 ))
		{
			cout << "Already occupied " << endl;
			goto there2;
		}
		else
		{
			cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
			there2:
				cin >> x;
				cin >> y;
				if (x > 3 || y > 3 || x < 1 || y < 1 || a[x - 1][y - 1] != 0)
				{
					if (a[x - 1][y - 1] != 0 && !(x>3 || y>3 || x<1 || y<1))
					{
						cout << "Already occupied " << endl;
					}
					else
					{	
						cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
					}
					goto there2;
				}	
			}
		}
				a[x - 1][y - 1] = 1;
}
void TicTacToe::input2()
{
	int x, y;
		cout << "\nEnter the position second player(x,y)" << endl;
		cin >> x;
		cin >> y;

	if (x > 3 || y > 3 || x < 1 || y < 1 || a[x - 1][y - 1] != 0)
	{
		if (x == 0 || y == 0)
		{
			cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
			goto there2;

		}
		else if (a[x - 1][y - 1] != 0 && !(x>3 || y>3 ||x<1 ||y<1))
		{
			cout << "Already occupied " << endl;
			goto there2;
		}
		else
		{

			cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
			there2:
			cin >> x;
			cin >> y;
			if (x > 3 || y > 3 || x < 1 || y < 1 || a[x - 1][y - 1] != 0)
			{
				if (a[x - 1][y - 1] != 0)
				{
					cout << "Already occupied " << endl;
				}
				else
				{
					cout << "Incorrect input.Enter between 1 & 3 inclusive " << endl;
				}
				goto there2;
			}
		}

	}
	a[x - 1][y - 1] = 2;
}

std::string getStrFor(int value)
{
	switch (value)
	{
	case 0: return "   ";
	case 1: return " X ";
	case 2: return " O ";
	default:
		break;
	}
	return "   ";
}

void TicTacToe::display()
{
	int i, j;
	cout << "\n";
	
	cout << "-------------" << std::endl;
	
	for (i = 0; i < 3; i++)
	{
		std::cout << "|";
		for (j = 0; j < 3; j++)
		{
			const std::string val = getStrFor(a[i][j]);
			std::cout << val.c_str() << "|";
		}
		cout << std::endl << "-------------" << std::endl;
	}
}
