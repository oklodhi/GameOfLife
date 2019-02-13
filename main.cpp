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

	srand((unsigned int)time(NULL));
	random_state(boardVect); 

	print_board(boardVect); 

	check_neighbors(boardVect);

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
				std::cout << "."; 
			}
			else if (vec[i][j] == 1) {
				std::cout << "#";
			}
		}
		std::cout << " ]" << std::endl;
	}
}

// check neighboring indexes
void check_neighbors(std::vector<std::vector<int> > &vec) {
	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {

			// If current index is not a border index
			if ((i > 0 && j > 0) && (i < (vec.size() - 1) && j < (vec[i].size() - 1))) {
				// loop through each neighboring index
				//std::cout << "MIDDLE Row " << i << " Col " << j << std::endl;
				for (std::size_t row = (i - 1); row < (i + 2); row++) {
					for (std::size_t col = (j - 1); col < (j + 2); col++) {
						// if not (i,j) aka center index
						if (((row != i) && (col != j)) && (vec[row][col] == 1)) {
							//if (vec[row][col] == 1) {
								// add to the count of alive neightbors, will use this to perform conditionals
							aliveNeighborCount++; 
							//}
						}
					}
				}

				// Checks neighbor index 1 by 1
				/*if (vec[i + 1][j + 1] == 1) {
					aliveNeighborCount++;
				}*/
			}
			else { // If border index, then its either corner = 3 neighbors
				if ((i == 0 && j == 0)) {
					//std::cout << "CORNER TOP LEFT " << i << " Col " << j << std::endl;
					if (vec[i][j + 1] == 1) {
						aliveNeighborCount++; 
					}
					if (vec[i + 1][j] == 1) {
						aliveNeighborCount++; 
					}
					if (vec[i + 1][j + 1] == 1) {
						aliveNeighborCount++;
					}
				}
				else if (i == 0 && j == (vec[i].size() - 1)) {
					//std::cout << "CORNER TOP RIGHT " << i << " Col " << j << std::endl;
					if (vec[i][j - 1] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i + 1][j - 1] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i + 1][j] == 1) {
						aliveNeighborCount++;
					}
				}
				else if (i == (vec.size() - 1) && j == 0) {
					//std::cout << "CORNER BOT LEFT " << i << " Col " << j << std::endl;
					if (vec[i - 1][j] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i - 1][j + 1] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i][j + 1] == 1) {
						aliveNeighborCount++;
					}
				}
				else if (i == (vec.size() - 1) && j == (vec[i].size() - 1)) {
					//std::cout << "CORNER BOT RIGHT " << i << " Col " << j << std::endl;
					if (vec[i - 1][j - 1] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i - 1][j] == 1) {
						aliveNeighborCount++;
					}
					if (vec[i][j - 1] == 1) {
						aliveNeighborCount++;
					}
				}
				else { // or middle = 5 neighbors
					//std::cout << "EDGE Row " << i << " Col " << j << std::endl;
					if (i == 0 && (j > 0 && (j < vec[i].size() - 1))) {
						if (vec[i][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j + 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i][j + 1] == 1) {
							aliveNeighborCount++;
						}
					}
					else if ((i == vec.size() - 1) && (j > 0 && (j < vec[i].size() - 1))) {
						if (vec[i][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i - 1][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i - 1][j] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i - 1][j + 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i][j + 1] == 1) {
							aliveNeighborCount++;
						}
					}
					else if ((i > 0 && (i < vec.size() - 1)) && j == 0) {
						if (vec[i - 1][j] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i - 1][j + 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i][j + 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j + 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j] == 1) {
							aliveNeighborCount++;
						}
					}
					else if ((i > 0 && (i < vec.size() - 1)) && (j == vec[i].size() - 1)) {
						if (vec[i - 1][j] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i - 1][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j - 1] == 1) {
							aliveNeighborCount++;
						}
						if (vec[i + 1][j] == 1) {
							aliveNeighborCount++;
						}
					}
				}
			}
			// std::cout << i << "," << j << " Alive neighbors: " << aliveNeighborCount << std::endl;

			next_board_state(vec, i, j, aliveNeighborCount); 

			// Have to reset aliveNeighborCount otherwise it sums ALL alive neighbors
			aliveNeighborCount = 0; 

			print_board(vec);
		}
	}
}

// generates next board state based on conditionals with AliveNeighborCount
void next_board_state(std::vector<std::vector<int> > &vec, int i, int j, int count) {
	if (count == 0 || count == 1) {
		vec[i][j] = 0; 
	}
	else if (count == 2 || count == 3) {
		vec[i][j] = 1;
	}
	else if (count == 3 && vec[i][j] == 0) {
		vec[i][j] = 1;
	}
	else {
		vec[i][j] = 0;
	}
}