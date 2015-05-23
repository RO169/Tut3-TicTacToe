#include "TicTacToe.h"
#include<iostream>
using namespace std;

TicTacToe::TicTacToe(){}

TicTacToe::TicTacToe(int x = 0, int y = 0, int p = 1, char dec = 'n')
{
	xPos = x;
	yPos = y;
	player = p;
	decision = dec;
}

void TicTacToe::welcome()
{
	cout << "\n************************************************************"<< endl;
	cout << "\n Welcome to the 2 player game Tic Tac Toe! Player 1 is ";
	cout << "\n represented by 'x' and Player 2 by 'o'. ";
   	cout << "\n Each player will be prompted to place their letter";
	cout << "\n in a row and collumn. The first 1 to create 3 adjacent";
	cout << "\n plays wins! Goodluck!" << endl;
	cout << "\n************************************************************" << endl;
}

void TicTacToe::restart(TicTacToe game)
{
	cout << "\n\n\n";
	cout << "\n************************************************************" << endl;
	cout << "Do you wish to start a new game (y/n) ?" << endl;
	cin >> game.decision;
	
	if (game.decision == 'y')
	{
		cout << "\n\n\t\tCollumns\n" << endl;
		cout << "          0\t|1\t|2" << endl << endl; 
		cout << "        0  \t|\t|\t" << endl;
		cout << "Rows    1  \t|\t|\t" << endl;
		cout << "        2  \t|\t|\t" << endl;
		cout << "\n\n" << endl;
	}
	else if (game.decision == 'n')
	{
		cout << "\n************************************************************" << endl;
		cout << "Thank You For Playing" << endl;
		cout << "\n\n Rungiah Games ltd\n" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		cout << "\n\n Invalid Entry. \n\n\n\n ";
		system("PAUSE");
		exit(0);
	}

	game.move();
}

TicTacToe::~TicTacToe()
{
}
