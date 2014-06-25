// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "TicTacToe.h"
#include<fstream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int z,i,j,q;
	TicTacToe t;
	while (true)
	{
		q = 0;
		z = 0;
		t.input1();
		
		t.display();
		
		z=t.hor_check(1);
		
		if (z)
		{
			cout << "\n";
			
			cout << "player 1 wins" << endl;

			break;
		}
		z=t.ver_check(1);
		
		if (z)
		{
			cout << "\n";
			
			cout << "player 1 wins" << endl;
		
			break;
		}

		z=t.diagonal_check(1);
		
		if (z == 0)
			break;
		q=t.gameover_check();
		if (q)
			break;
		
		t.input2();
		t.display();
		z = t.hor_check(2);
		
		if (z )
		{
			cout << "\n";
		
			cout << "player 2 wins" << endl;
		
			break;
		}

		z = t.ver_check(2);
		
		if (z)
		{
			cout << "\n";
			
			cout << "player 2 wins" << endl;
		
			break;
		}

		z = t.diagonal_check(2);
		
		if (z==0)
			break;
		

	}

	return 0;
}

