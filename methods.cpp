#include <iostream>
#include "methods.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>


using namespace std;

vector<int>spaces_used{};
char player_letter{};
char computer_letter{};
int choice{};
int pc_choice{};
int row, column{};
bool draw;
bool _play_again = false;


char board[3][3] = { { '1', '2', '3' },
					 { '4', '5', '6' },
					 { '7', '8', '9' } };
/*
==============Board Index Locations===============
			 { '0-0', '0-1', '0-2' },
			 { '1-0', '1-1', '1-2' },
			 { '2-0', '2-1', '2-2' }
==================================================
*/

//void computer_move() {
//	cout << "Computers turn..." << endl;
//	cout << "\n";
//	Sleep(750);
//	int rand_int{};
//	if (spaces_used.size() > 0) {
//		for (int x = 0; x < 3; x++) {
//			for (int y = 0; y < 3; y++) {
//					if (board[x][y] != 'X' && board[x][y] != 'O') {
//						if (x == 0 && y == 0) { choice = 1; goto choice_label; }
//						if (x == 0 && y == 1) { choice = 2; goto choice_label; }
//						if (x == 0 && y == 2) { choice = 3; goto choice_label; }
//						if (x == 1 && y == 0) { choice = 4; goto choice_label; }
//						if (x == 1 && y == 1) { choice = 5; goto choice_label; }
//						if (x == 1 && y == 2) { choice = 6; goto choice_label; }
//						if (x == 2 && y == 0) { choice = 7; goto choice_label; }
//						if (x == 2 && y == 1) { choice = 8; goto choice_label; }
//						if (x == 2 && y == 2) { choice = 9; goto choice_label; }
//						break;
//					}
//					else if (spaces_used.size() == 9 ){ playingGame(); }
//			}
//		}
//	}

int counter_player_win() {
	if (board[0][0] == player_letter && board[0][1] == player_letter && board[0][2] != computer_letter) { return 3; } //Top Row
	if (board[0][1] == player_letter && board[0][2] == player_letter && board[0][0] != computer_letter) { return 1; } //Top Row
	if (board[0][0] == player_letter && board[0][2] == player_letter && board[0][1] != computer_letter) { return 2; } //Top Row
	if (board[1][0] == player_letter && board[1][1] == player_letter && board[1][2] != computer_letter) { return 6; } //Middle Row
	if (board[1][1] == player_letter && board[1][2] == player_letter && board[1][0] != computer_letter) { return 4; } //Middle Row
	if (board[1][0] == player_letter && board[1][2] == player_letter && board[1][1] != computer_letter) { return 5; } //Middle Row
	if (board[2][0] == player_letter && board[2][1] == player_letter && board[2][2] != computer_letter) { return 9; } //Bottom Row
	if (board[2][1] == player_letter && board[2][2] == player_letter && board[2][0] != computer_letter) { return 7; } //Bottom Row
	if (board[2][0] == player_letter && board[2][2] == player_letter && board[2][1] != computer_letter) { return 8; } //Bottom Row
	if (board[0][0] == player_letter && board[1][0] == player_letter && board[2][0] != computer_letter) { return 7; } //Left Column
	if (board[1][0] == player_letter && board[2][0] == player_letter && board[0][0] != computer_letter) { return 1; } //Left Column
	if (board[0][0] == player_letter && board[2][0] == player_letter && board[1][0] != computer_letter) { return 4; } //Left Column
	if (board[0][1] == player_letter && board[1][1] == player_letter && board[2][1] != computer_letter) { return 8; } //Middle Column
	if (board[1][1] == player_letter && board[2][1] == player_letter && board[0][1] != computer_letter) { return 2; } //Middle Column
	if (board[0][1] == player_letter && board[2][1] == player_letter && board[1][1] != computer_letter) { return 5; } //Middle Column
	if (board[0][2] == player_letter && board[1][2] == player_letter && board[2][2] != computer_letter) { return 9; } //Right Column
	if (board[1][2] == player_letter && board[2][2] == player_letter && board[0][2] != computer_letter) { return 3; } //Right Column
	if (board[0][2] == player_letter && board[2][2] == player_letter && board[1][2] != computer_letter) { return 6; } //Right Column
	if (board[0][0] == player_letter && board[1][1] == player_letter && board[2][2] != computer_letter) { return 9; } //Vertical Decline
	if (board[1][1] == player_letter && board[2][2] == player_letter && board[0][0] != computer_letter) { return 1; } //Vertical Decline
	if (board[0][0] == player_letter && board[2][2] == player_letter && board[1][1] != computer_letter) { return 5; } //Vertical Decline
	if (board[2][0] == player_letter && board[1][1] == player_letter && board[0][2] != computer_letter) { return 3; } //Vertical Incline
	if (board[0][2] == player_letter && board[1][1] == player_letter && board[2][0] != computer_letter) { return 7; } //Vertical Incline
	if (board[0][2] == player_letter && board[2][0] == player_letter && board[1][1] != computer_letter) { return 5; } //Vertical Incline
	else return 0; 
}
int computer_win() {
	if (board[0][0] == computer_letter && board[0][1] == computer_letter && board[0][2] != computer_letter && board[0][2] != player_letter) { return 3; } //Top Row
	if (board[0][1] == computer_letter && board[0][2] == computer_letter && board[0][0] != computer_letter && board[0][0] != player_letter) { return 1; } //Top Row
	if (board[0][0] == computer_letter && board[0][2] == computer_letter && board[0][1] != computer_letter && board[0][1] != player_letter) { return 2; } //Top Row
	if (board[1][0] == computer_letter && board[1][1] == computer_letter && board[1][2] != computer_letter && board[1][2] != player_letter) { return 6; } //Middle Row
	if (board[1][1] == computer_letter && board[1][2] == computer_letter && board[1][0] != computer_letter && board[1][0] != player_letter) { return 4; } //Middle Row
	if (board[1][0] == computer_letter && board[1][2] == computer_letter && board[1][1] != computer_letter && board[1][1] != player_letter) { return 5; } //Middle Row
	if (board[2][0] == computer_letter && board[2][1] == computer_letter && board[2][2] != computer_letter && board[2][2] != player_letter) { return 9; } //Bottom Row
	if (board[2][1] == computer_letter && board[2][2] == computer_letter && board[2][0] != computer_letter && board[2][0] != player_letter) { return 7; } //Bottom Row
	if (board[2][0] == computer_letter && board[2][2] == computer_letter && board[2][1] != computer_letter && board[2][1] != player_letter) { return 8; } //Bottom Row
	if (board[0][0] == computer_letter && board[1][0] == computer_letter && board[2][0] != computer_letter && board[2][0] != player_letter) { return 7; } //Left Column
	if (board[1][0] == computer_letter && board[2][0] == computer_letter && board[0][0] != computer_letter && board[0][0] != player_letter) { return 1; } //Left Column
	if (board[0][0] == computer_letter && board[2][0] == computer_letter && board[1][0] != computer_letter && board[1][0] != player_letter) { return 4; } //Left Column
	if (board[0][1] == computer_letter && board[1][1] == computer_letter && board[2][1] != computer_letter && board[2][1] != player_letter) { return 8; } //Middle Column
	if (board[1][1] == computer_letter && board[2][1] == computer_letter && board[0][1] != computer_letter && board[0][1] != player_letter) { return 2; } //Middle Column
	if (board[0][1] == computer_letter && board[2][1] == computer_letter && board[1][1] != computer_letter && board[1][1] != player_letter) { return 5; } //Middle Column
	if (board[0][2] == computer_letter && board[1][2] == computer_letter && board[2][2] != computer_letter && board[2][2] != player_letter) { return 9; } //Right Column
	if (board[1][2] == computer_letter && board[2][2] == computer_letter && board[0][2] != computer_letter && board[0][2] != player_letter) { return 3; } //Right Column
	if (board[0][2] == computer_letter && board[2][2] == computer_letter && board[1][2] != computer_letter && board[1][2] != player_letter) { return 6; } //Right Column
	if (board[0][0] == computer_letter && board[1][1] == computer_letter && board[2][2] != computer_letter && board[2][2] != player_letter) { return 9; } //Vertical Decline
	if (board[1][1] == computer_letter && board[2][2] == computer_letter && board[0][0] != computer_letter && board[0][0] != player_letter) { return 1; } //Vertical Decline
	if (board[0][0] == computer_letter && board[2][2] == computer_letter && board[1][1] != computer_letter && board[1][1] != player_letter) { return 5; } //Vertical Decline
	if (board[2][0] == computer_letter && board[1][1] == computer_letter && board[0][2] != computer_letter && board[0][2] != player_letter) { return 3; } //Vertical Incline
	if (board[0][2] == computer_letter && board[1][1] == computer_letter && board[2][0] != computer_letter && board[2][0] != player_letter) { return 7; } //Vertical Incline
	if (board[0][2] == computer_letter && board[2][0] == computer_letter && board[1][1] != computer_letter && board[1][1] != player_letter) { return 5; } //Vertical Incline
	else return 0;
}

void computer_move() {
	cout << "Computers turn..." << endl;
	cout << "\n";
	Sleep(750);
	if (computer_win() >= 1)
	{
		pc_choice = computer_win();
		goto choice_label;
	}
	else if (counter_player_win() >= 1)
	{
		pc_choice = counter_player_win();
		goto choice_label;
	}
	else if (spaces_used.size() > 0) 
	{
		int rand_int{};
		srand(time(0));
		rand_int = generate_int();
		//use vector searching algorithm to save your sorry ass on this logic
		vector<int>::iterator y = find(spaces_used.begin(), spaces_used.end(), rand_int);
		while (y != spaces_used.end()) 
		{
			rand_int = generate_int();
			y = find(spaces_used.begin(), spaces_used.end(), rand_int);
		}
		pc_choice = rand_int;
		goto choice_label;
	}
	else if (spaces_used.size() == 0)
	{
		int rand_int{};
		srand(time(0));
		rand_int = rand() % 10 + 1;
		while (rand_int > 9 || rand_int < 1) 
		{
			rand_int = rand() % 10 + 1;
		}
		pc_choice = rand_int;
		goto choice_label;
	}
choice_label:
	switch (pc_choice) {
	case 1: {row = 0; column = 0; break; }
	case 2: {row = 0; column = 1; break; }
	case 3: {row = 0; column = 2; break; }
	case 4: {row = 1; column = 0; break; }
	case 5: {row = 1; column = 1; break; }
	case 6: {row = 1; column = 2; break; }
	case 7: {row = 2; column = 0; break; }
	case 8: {row = 2; column = 1; break; }
	case 9: {row = 2; column = 2; break; }
	default: {cout << "Invalid Choice!" << endl; }
	}
	if (board[row][column] != 'X' && board[row][column] != 'O') {
		board[row][column] = computer_letter;
		spaces_used.push_back(pc_choice);
		print_board();
	}
	else if (board[row][column] == player_letter || board[row][column] == computer_letter)
	{
	cout << "Position: " << row << "-" << column << " - is taken by Player " << board[row][column] << "!" << endl;
	cout << "Choose another position." << endl;
	computer_move();
	}
}

void const print_board()
{
	cout << "		_________________" << endl;
	for (int i = 0; i < 3; i++) {

		cout << "		     |     |		" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "		  " << board[i][j] << "  |  " << board[i][j + 1] << "  |  " << board[i][j + 2] << "\n";
			break;
		}
		cout << "		_____|_____|_____" << endl;
	}

};

int rand_assign() {
	srand(time(0));
	int rand_int = rand() % 2;
	if (rand_int == 0) {
		player_letter = 'O';
		computer_letter = 'X';
		return 1; 
	}
	else {
		computer_letter = 'O';
		player_letter = 'X';
		return 0;
	}
}



void make_move() {
	cout << "Player Go!:";
	choice = get_choice();
	cout << "\n";

	switch (choice) {
	case 1: {row = 0; column = 0; break; }
	case 2: {row = 0; column = 1; break; }
	case 3: {row = 0; column = 2; break; }
	case 4: {row = 1; column = 0; break; }
	case 5: {row = 1; column = 1; break; }
	case 6: {row = 1; column = 2; break; }
	case 7: {row = 2; column = 0; break; }
	case 8: {row = 2; column = 1; break; }
	case 9: {row = 2; column = 2; break; }
	default: {cout << "Invalid Choice!" << endl; }
	}

	if (board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = player_letter;
		spaces_used.push_back(choice);
		print_board();
	}
	else if (board[row][column] == 'X' || board[row][column] == 'O')
	{
		cout << "Position is taken by Player " << board[row][column] << "!" << endl;
		cout << "Choose another position." << endl;
		make_move();
	}

}
bool playingGame() {
	//Check for Win
	if (_play_again) {
		_play_again = false;
		return true;
	}
	else if (computer_won()) {
		cout << "\t     =======================";
		cout << "\n\t\t   Computer Won!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else if (player_won()) {
		cout << "\t     =======================";
		cout << "\n\t\t   Player Won!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else if (check_for_draw()) {
		cout << "\t     =======================";
		cout << "\n\t\t   It is a TIE!\n";
		cout << "\t     =======================" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool computer_won() {
	if (board[0][0] == computer_letter && board[0][1] == computer_letter && board[0][2] == computer_letter) //Top Row
		return true;
	if (board[1][0] == computer_letter && board[1][1] == computer_letter && board[1][2] == computer_letter) //Middle Row
		return true;
	if (board[2][0] == computer_letter && board[2][1] == computer_letter && board[2][2] == computer_letter) //Bottom Row
		return true;
	if (board[0][0] == computer_letter && board[1][0] == computer_letter && board[2][0] == computer_letter) //Left Column
		return true;
	if (board[0][1] == computer_letter && board[1][1] == computer_letter && board[2][1] == computer_letter) //Middle Column
		return true;
	if (board[0][2] == computer_letter && board[1][2] == computer_letter && board[2][2] == computer_letter) //Right Column
		return true;
	if (board[0][0] == computer_letter && board[1][1] == computer_letter && board[2][2] == computer_letter) //Vertical Decline
		return true;
	if (board[2][0] == computer_letter && board[1][1] == computer_letter && board[0][2] == computer_letter) //Vertical Incline
		return true;
	else
		return false;
}

bool player_won() {
	if (board[0][0] == player_letter && board[0][1] == player_letter && board[0][2] == player_letter) //Top Row
		return true;
	if (board[1][0] == player_letter && board[1][1] == player_letter && board[1][2] == player_letter) //Middle Row
		return true;
	if (board[2][0] == player_letter && board[2][1] == player_letter && board[2][2] == player_letter) //Bottom Row
		return true;
	if (board[0][0] == player_letter && board[1][0] == player_letter && board[2][0] == player_letter) //Left Column
		return true;
	if (board[0][1] == player_letter && board[1][1] == player_letter && board[2][1] == player_letter) //Middle Column
		return true;
	if (board[0][2] == player_letter && board[1][2] == player_letter && board[2][2] == player_letter) //Right Column
		return true;
	if (board[0][0] == player_letter && board[1][1] == player_letter && board[2][2] == player_letter) //Vertical Decline
		return true;
	if (board[2][0] == player_letter && board[1][1] == player_letter && board[0][2] == player_letter) //Vertical Incline
		return true;
	else
		return false;
}

bool check_for_draw() {
	if (spaces_used.size() == 9)
		return true;
	else
		return false;
}

int get_choice() {
	int i;
	cin >> i;
	while (cin.fail() || i == 0 || i > 9) {
		cout << "Choose a number on the board!: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}

bool play_again() {
	char user_choice{};
	cout << "Would you like to play again? (Y/N): " << endl;
	cin >> user_choice;
	if (tolower(user_choice) == 'y') {
		_play_again = true;
		spaces_used.clear();
		return _play_again;
	}
	else {
		return false;
	}
}
void clear_board(int x, int y)
{
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			board[x][y] = ' ';
			board[x][y + 1] = ' ';
			board[x][y + 2] = ' ';
			break;
		}
	}

};

int generate_int() {
	int x{};
	x = rand() % 10 + 1;
	while (x > 9 || x < 1)
	{
		x = rand() % 10 + 1;
	}
	return x;
}