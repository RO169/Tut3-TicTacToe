#include<iostream>
#include"TicTacToe.h"
using namespace std;

int main()
{
	TicTacToe Game;

	Game.welcome();
	Game.restart(Game);

	system("PAUSE");
	return 0;
}