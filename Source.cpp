#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

int main() {
	std::string display[] = {"                                      ",
		                     "                                      ",
							 "                                      ",
							 "                                      ",
							 "______________________________________",
							 "                                      "};
	int player_y = 4;
	int jump_frame = 0;
	bool j = false;
	int spike_x = 40;
	int score = 0;

	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 'e':
					return 0;
					break;
				case ' ':
					j = true;
					break;
			}
		}
		if (j) {
			switch (jump_frame) {
				case 0:
					jump_frame++;
					break;
				case 1:
					player_y--;
					jump_frame++;
					break;
				case 2:
					player_y--;
					jump_frame++;
					break;
				case 3:
					player_y++;
					jump_frame++;
					break;
				case 4:
					player_y++;
					jump_frame = 0;
					j = false;
			}
		}

		display[player_y][5] = 'O';
		if (display[player_y - 1][5] == 'O') {
			display[player_y - 1][5] = ' ';
		} else if (display[player_y + 1][5] == 'O') {
			display[player_y + 1][5] = ' ';
		}

		if (player_y != 4) {
			display[4][5] = '_';
		}
		if (spike_x < 39 && spike_x > -1) {
			display[4][spike_x] = '^';
		}
		display[4][spike_x + 1] = '_';

		spike_x--;
		if (spike_x < -2) {
			spike_x = 45;
		}

		if (player_y == 4 && spike_x == 5) {
			score = 0;
		} else if (player_y != 4 && spike_x == 5) {
			score++;
		}

		for (int y = 0; y < 5; y++) {
			std::cout << display[y] << std::endl;
		}
		std::cout << "Score:" << score << std::endl;
		Sleep(75);
		system("cls");
	}
}