#include<iostream>
#include"TicTacToe.h"
using namespace std;

int main()
{
	bool done = false;
	TicTacToe Game;
		
	Game.welcome();
	
	while (!done)
	{
		Game.restart(Game, done);
	}


	system("PAUSE");
	return 0;
}