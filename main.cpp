#include "main.h"

int main() {
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

void resize_board(std::vector<std::vector<int> > &vect, int w, int h) {
	std::cout << "\nYou picked a board of size " + std::to_string(width) + " x " + std::to_string(height) << std::endl << std::endl;
	std::cout << "Resizing..." << std::endl; 

	vect.resize(w);
	for (auto &it : vect) {
		it.resize(h); 
	}

	std::cout << "Game board is ready!" << std::endl << std::endl;
}

void dead_state(std::vector<std::vector<int> > &vec) {
	std::cout << "Initializing board values to NULL..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = 0; 
		}
	}

	std::cout << "Done! Board is set to NULL!" << std::endl << std::endl;
}

int genRandNum() {
	rn = rand() % 2; 

	return rn; 
}

void random_state(std::vector<std::vector<int> > &vec) {
	std::cout << "\nSetting board to random values..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = genRandNum();
		}
	}

	std::cout << "Done! Board is set to random values!" << std::endl << std::endl;
}

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