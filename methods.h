#ifndef _METHODS_H_
#define _METHODS_H_


void const print_board();

void make_move();

void computer_move(); 

int rand_assign();

bool playingGame();

bool computer_won();

bool player_won();

bool check_for_draw();

int get_choice();

bool play_again();

void clear_board(int x = 0, int y = 0);

int counter_player_win();
//void smart_computer_move();

int generate_int();

#endif
