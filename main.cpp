#include <iostream>
#include "methods.h"

using namespace std;

bool in_game = true;

int counter = 0;

int player{};

bool playing_Game = true; 


int main() {
	cout << "\t     =======================";
	cout << "\n\t      Welcome to Tic-Tac-Toe" << endl;
	cout << "\t     =======================" << endl;
	cout << "\t         -Created by Eric" << endl;
	cout << "\t             02/25/2020" << endl;
	print_board();
	//clear board but not print
	while (in_game) {
		if (counter > 0) // true when player starts a new game, prints the blank board.
			print_board();
		if (counter >= 0) //true at the beginning of the game and after starting a new one. Assigns random character to player(s)
			player = rand_assign();
		while (playing_Game) //playing_game is a bool value that is intialized as true..duh
		{
			if (player == 1) { //if rand_assign() returns 0 to the int player variable, then human goes first. 
				make_move(); //human makes move.
				if (!(playingGame())) //playingGame() checks for wins & tie games. if any, then returns false 
				{  
					playing_Game = false; //inner while loop doesnt run anymore
					break;
				}
				computer_move(); // if playingGame() is true then game continues with computer move
				if (!(playingGame())) //playingGame() checks for wins & tie games. if any, then returns false 
				{
					playing_Game = false; //inner while loop doesnt run anymore
					break;
				}
			}
			else if (player == 0) {//same logic as above, 
				computer_move();
				if (!(playingGame()))
				{
					playing_Game = false;
					break;
				}
				make_move();
				if (!(playingGame())) //playingGame() checks for wins & tie games. if any, then returns false 
				{
					playing_Game = false; //inner while loop doesnt run anymore
					break;
				}
			}
			
		}

		if (play_again()) //after breaking out of inner while loop, then play_again() func runs and checks to play again or quit
		{
			playing_Game = true;
			clear_board();
			counter += 1; 
		}

		else {
			cout << "\nGoodbye!" << endl;
			in_game = false;
		}
	}




	return 0;
}