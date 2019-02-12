// Source file containing all function definitions

// include the header file
#include "main.h"

int main() {
	// Prompt user input for board size
	std::cout << "What size board do you want? >> ";
	std::cin >> width >> height; 

	resize_board(boardVect, width, height);
	dead_state(boardVect); 

	print_board(boardVect); 

	srand(time(NULL));
	random_state(boardVect); 

	print_board(boardVect);  

	return 0; 
}

// resizes board based on user input from main()
void resize_board(std::vector<std::vector<int> > &vect, int w, int h) {
	std::cout << "\nYou picked a board of size " + std::to_string(width) + " x " + std::to_string(height) << std::endl << std::endl;
	std::cout << "Resizing..." << std::endl; 

	vect.resize(w);
	for (auto &it : vect) {
		it.resize(h); 
	}

	std::cout << "Game board is ready!" << std::endl << std::endl;
}


// generates a board of size nxn to 0
void dead_state(std::vector<std::vector<int> > &vec) {
	std::cout << "Initializing board values to NULL..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = 0; 
		}
	}

	std::cout << "Done! Board is set to NULL!" << std::endl << std::endl;
}

// generate random number based on time seed in main
int genRandNum() {
	rn = rand() % 2; 

	return rn; 
}

// regenerate board with random 1 and 0 index values
void random_state(std::vector<std::vector<int> > &vec) {
	std::cout << "\nSetting board to random values..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = genRandNum();
		}
	}

	std::cout << "Done! Board is set to random values!" << std::endl << std::endl;
}

// pretty print the board 
void print_board(std::vector<std::vector<int> > &vec) {
	std::cout << "Printing current board... " << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		std::cout << "[ ";
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == 0) {
				std::cout << "  "; 
			}
			else if (vec[i][j] == 1) {
				std::cout << "# ";
			}
		}
		std::cout << "]" << std::endl;
	}
}

// check neighboring indexes
void check_neighbors(std::vector<std::vector<int> > &vec) {
	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {

			// If current index is not a border index
			if ((i > 0 && i < vec.size()) && (j > 0 && j < vec[i].size())) {
				// loop through each neighboring index
				for (int a = (i - 1); a <= (i + 1); a++) {
					for (int b = (j - 1); b <= (j + 1); b++) {
						// if not (i,j) aka center index
						if ((a != i) && (b != j)) {
							if (vec[a][b] == 1) {
								// add to the count of alive neightbors,				will use this to perform conditionals
								aliveNeighborCount++; 
							}
						}
					}
				}
				// Checks neighbor index 1 by 1
				/*if (vec[i + 1][j + 1] == 1) {
					aliveNeighborCount++;
				}*/
			}
			// else if border element, then must be corner index
			else if ((i == 0 && j == 0) || (i == 0 && j == n) || (i == n && j == 0) || (i == n && j == n)) {

			}
			// or side index
			else {

			}
		}
	}
}

// generates next board state based on conditionals with AliveNeighborCount
void next_board_state(std::vector<std::vector<int> > &vec) {
	
}