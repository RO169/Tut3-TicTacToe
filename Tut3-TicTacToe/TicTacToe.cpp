#include "TicTacToe.h"
#include<iostream>
using namespace std;
char posArr[3][3];

TicTacToe::TicTacToe(){}

TicTacToe::TicTacToe(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int p = 1, char dec = 'n')
{
	//default constructor
	xPos1 = x1;
	yPos1 = y1;
	xPos2 = x2;
	yPos2 = y2;
	player = p;
	decision = dec;
}

void TicTacToe::welcome()
{
    //function provides a brief welcome/introduction to the game 
	cout << "\n************************************************************"<< endl;
	cout << "\n Welcome to the 2 player game Tic Tac Toe! Player 1 is ";
	cout << "\n represented by 'x' and Player 2 by 'o'. ";
   	cout << "\n Each player will be prompted to place their letter";
	cout << "\n in a row and collumn. The first 1 to create 3 adjacent";
	cout << "\n plays wins! Goodluck!" << endl;
	cout << "\n************************************************************" << endl << endl;
}

void TicTacToe::restart(TicTacToe game, bool &done)
{
	cout << "Do you wish to start a new game (y/n) ?" << endl;
	cin >> game.decision;                                //check if user wants to start a new game 
	                                                     //draw board if yes--shows how rows and collumns are numbered
	cout << "\n************************************************************" << endl;
	if (game.decision == 'y')
	{
		cout << "\n\n\t\tCollumns\n" << endl;
		cout << "          0  |1 | 2" << endl << endl; 
		cout << "        0  __|__|__" << endl;
		cout << "Rows    1  __|__|__" << endl;
		cout << "        2    |  |  " << endl;
		cout << "\n\n" << endl;
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				posArr[i][j] = '_';
			}
		}
		
		game.player = 1;
		game.move(game, posArr);
	}
	else if (game.decision == 'n')                     //exit if no -- with goodbye message
	{
		
		cout << " \n Thank You For Playing" << endl;
		cout << "\n\n Rungiah Games ltd\n\n\n" << endl;
		done = true;
	}
	else
	{                                                 //check for invalid inputs
		cout << "\n\n Invalid Entry. \n\n\n\n ";             
		done = true;
	}

	
}

void TicTacToe::move(TicTacToe Player, char posArr[][3])
{
	cout << "\n************************************************************" << endl;
	cout << "\n\nPlayer " << Player.player << "'s turn\n" << endl;
	cout << "\nPlease enter a Row <enter> and Collumn <enter> to play in" << endl;
	cin >> Player.xPos1 >> Player.yPos1;

	if (Player.xPos1 < 3 && Player.yPos1 < 3)         //check if within array bounds
	{
		if (posArr[Player.xPos1][Player.yPos1] == '_')     //check if any player has played in this position
		{
			Player.xPos2 = Player.xPos1;
			Player.yPos2 = Player.yPos1;
		}
		else
		{
			cout << "\n************************************************************" << endl;
			cout << "\n\nInvalid Entry" << endl;
			Player.move(Player, posArr);
		}
	}
	else
	{
		cout << "\n************************************************************" << endl;
		cout << "\n\nInvalid Entry\n" << endl;
		Player.move(Player, posArr);
	}


	if (Player.player == 1)
		posArr[Player.xPos2][Player.yPos2] = 'x';
	else
		posArr[Player.xPos2][Player.yPos2] = 'o';

	Player.player++;
		if (Player.player >= 3)
			Player.player = 1;
	
		Player.print(Player);
}

void TicTacToe::print(TicTacToe Board)
{
	cout << "\n************************************************************" << endl;
	cout << " _ _ _ _ _ _ _ _ _" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << "_ " << posArr[i][j] << " _|";
		}
		cout << endl;
	}
	cout << "\n************************************************************\n\n" << endl;

	bool fun = true;
	Board.isWon(Board,fun, fun);
}

void TicTacToe::isWon(TicTacToe Status, bool move, bool win)
{
	move = true;
	win = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (posArr[i][j] == '_')
				move = false;
			if (posArr[0][j] == posArr[1][j] && posArr[1][j] == posArr[2][j] && posArr[2][j] != '_')
				win = true;
			if (posArr[j][0] == posArr[j][1] && posArr[j][2] == posArr[j][1] && posArr[j][1] != '_')
				win = true;
			if (posArr[0][0] == posArr[1][1] && posArr[1][1] == posArr[2][2] && posArr[2][2] != '_')
				win = true;
			if (posArr[2][0] == posArr[1][1] && posArr[1][1] == posArr[0][2] && posArr[0][2] != '_')
				win = true;
		}
	}

	

	if (win) 
	{
		if (Status.player == 2)
			Status.player = 1;
		else
			Status.player = 2;
		cout << "Player " << Status.player << " has won. Congratulations!" << endl;
		cout << "\n************************************************************\n" << endl;
		Status.restart(Status, win);
	}
	else if (!move)
		Status.move(Status, posArr);
	else
	{
		cout << "Unfortunately the match has ended in a draw, Please play again!" << endl;
		cout << "\n************************************************************\n" << endl;
		Status.restart(Status, win);
	}
}

TicTacToe::~TicTacToe(){}
