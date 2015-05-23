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
		
		Game.restart(Game);
		for (int i = 0; i < 10; i++)
		{
			Game.move(Game);
			if (i = 9)
			{
				done = false;
			}
		}
	}


	system("PAUSE");
	return 0;
}