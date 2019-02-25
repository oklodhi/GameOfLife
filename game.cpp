// Source file containing all function definitions

#include "game.h"

// Prompts for width and height of game board
void prompt_width_height(int &w, int &h) {
	std::cout << "What size board do you want? >> ";
	std::cin >> w >> h;
}

// resizes board based on user input from main()
void resize_board(std::vector<std::vector<int> > &vect, int w, int h) {
	std::cout << "\nYou picked a board of size " + std::to_string(w) + " x " + std::to_string(h) << std::endl << std::endl;
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
	int rn = rand() % 2;

	return rn;
}

// regenerate board with random 1 and 0 index values
void random_state(std::vector<std::vector<int> > &vec) {
	std::cout << "Setting board to random values..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = genRandNum();
		}
	}

	std::cout << "Done! Board is set to random values!" << std::endl << std::endl;
}

// pretty print the board 
void print_board(std::vector<std::vector<int> > &vec) {
	std::cout << "Printing board... " << std::endl;

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
	int count = 0;

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
							count++;
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
						count++;
					}
					if (vec[i + 1][j] == 1) {
						count++;
					}
					if (vec[i + 1][j + 1] == 1) {
						count++;
					}
				}
				else if (i == 0 && j == (vec[i].size() - 1)) {
					//std::cout << "CORNER TOP RIGHT " << i << " Col " << j << std::endl;
					if (vec[i][j - 1] == 1) {
						count++;
					}
					if (vec[i + 1][j - 1] == 1) {
						count++;
					}
					if (vec[i + 1][j] == 1) {
						count++;
					}
				}
				else if (i == (vec.size() - 1) && j == 0) {
					//std::cout << "CORNER BOT LEFT " << i << " Col " << j << std::endl;
					if (vec[i - 1][j] == 1) {
						count++;
					}
					if (vec[i - 1][j + 1] == 1) {
						count++;
					}
					if (vec[i][j + 1] == 1) {
						count++;
					}
				}
				else if (i == (vec.size() - 1) && j == (vec[i].size() - 1)) {
					//std::cout << "CORNER BOT RIGHT " << i << " Col " << j << std::endl;
					if (vec[i - 1][j - 1] == 1) {
						count++;
					}
					if (vec[i - 1][j] == 1) {
						count++;
					}
					if (vec[i][j - 1] == 1) {
						count++;
					}
				}
				else { // or middle = 5 neighbors
					//std::cout << "EDGE Row " << i << " Col " << j << std::endl;
					if (i == 0 && (j > 0 && (j < vec[i].size() - 1))) {
						if (vec[i][j - 1] == 1) {
							count++;
						}
						if (vec[i + 1][j - 1] == 1) {
							count++;
						}
						if (vec[i + 1][j] == 1) {
							count++;
						}
						if (vec[i + 1][j + 1] == 1) {
							count++;
						}
						if (vec[i][j + 1] == 1) {
							count++;
						}
					}
					else if ((i == vec.size() - 1) && (j > 0 && (j < vec[i].size() - 1))) {
						if (vec[i][j - 1] == 1) {
							count++;
						}
						if (vec[i - 1][j - 1] == 1) {
							count++;
						}
						if (vec[i - 1][j] == 1) {
							count++;
						}
						if (vec[i - 1][j + 1] == 1) {
							count++;
						}
						if (vec[i][j + 1] == 1) {
							count++;
						}
					}
					else if ((i > 0 && (i < vec.size() - 1)) && j == 0) {
						if (vec[i - 1][j] == 1) {
							count++;
						}
						if (vec[i - 1][j + 1] == 1) {
							count++;
						}
						if (vec[i][j + 1] == 1) {
							count++;
						}
						if (vec[i + 1][j + 1] == 1) {
							count++;
						}
						if (vec[i + 1][j] == 1) {
							count++;
						}
					}
					else if ((i > 0 && (i < vec.size() - 1)) && (j == vec[i].size() - 1)) {
						if (vec[i - 1][j] == 1) {
							count++;
						}
						if (vec[i - 1][j - 1] == 1) {
							count++;
						}
						if (vec[i][j - 1] == 1) {
							count++;
						}
						if (vec[i + 1][j - 1] == 1) {
							count++;
						}
						if (vec[i + 1][j] == 1) {
							count++;
						}
					}
				}
			}
			// std::cout << i << "," << j << " Alive neighbors: " << aliveNeighborCount << std::endl;

			next_board_state(vec, i, j, count);

			// Have to reset aliveNeighborCount otherwise it sums ALL alive neighbors
			count = 0;
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

void cmd_wait_clear() {
	Sleep(2222);
	system("CLS");
}

void open_and_read(std::ifstream& fio) {
	std::string fname; 

	std::cout << "Enter file name >> "; 
	std::cin >> fname;

	fio.open(fname);

	if (fio.is_open() == true) {

		int n, i = 0;
		std::vector<std::vector<int> > fileData;

		while (fio >> n) {
			
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "\nERROR: Can't open file!" << std::endl << std::endl;
	}
}