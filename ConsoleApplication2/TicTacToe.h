#pragma once
class TicTacToe
{
private:
	int a[3][3];
public:
	TicTacToe();
	~TicTacToe();
public:
	int hor_check(int t);
	int ver_check(int t);
	int diagonal_check(int t);
	void input1();
	void input2();
	void display();
	int gameover_check();
	
	
};

