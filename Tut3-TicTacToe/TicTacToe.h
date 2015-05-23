#pragma once
class TicTacToe
{
private:
	
	int xPos;
	int yPos;
	int player;
	char decision;

public:
	
	TicTacToe();
	TicTacToe(int x, int y, int p, char dec);

	void welcome();
	void restart(TicTacToe game);
	void move();
	void print();
	void isWon();


	~TicTacToe();
};

