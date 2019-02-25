// Main function file

// include the header file
#include "game.h"

int main() {
	int width = 0, height = 0, userChoice;
	bool quit = false;
	std::vector<std::vector<int> > boardVect;
	std::ifstream fio;

	while (quit != true) {
		std::cout << "1. Initialize random soup" << std::endl;
		std::cout << "2. Import from .txt file" << std::endl;
		std::cout << "3. Quit" << std::endl;
		std::cout << "What would you like to do? >> "; 
		std::cin >> userChoice;

		switch (userChoice) {
		case 1:
			prompt_width_height(width, height);

			resize_board(boardVect, width, height);
			dead_state(boardVect);

			print_board(boardVect);

			cmd_wait_clear();

			// Random number generator with seed = time
			// Best way to get a "truly" random number
			srand((unsigned int)time(NULL));
			random_state(boardVect);

			print_board(boardVect);

			cmd_wait_clear();

			while (true) {
				check_neighbors(boardVect);
				cmd_wait_clear();
				print_board(boardVect);
			}

			return 0;
			break;
		case 2:
			open_and_read(fio);
			break;
		case 3:
			quit = true;
			break;
		}
	}
}