// Main function file

// include the header file
#include "game.h"

int main() {
	int width = 0, height = 0;
	std::vector<std::vector<int> > boardVect;

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
}