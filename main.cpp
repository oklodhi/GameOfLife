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
	std::cout << "\nYou picked a board of " + std::to_string(width) + " x " + std::to_string(height) + " size." << std::endl << std::endl;
	std::cout << "Resizing..." << std::endl; 

	vect.resize(w);
	for (auto &it : vect) {
		it.resize(h); 
	}

	std::cout << "Game board is ready!" << std::endl << std::endl;
}

void dead_state(std::vector<std::vector<int> > &vec) {
	std::cout << "Initializing board values to 0..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = 0; 
		}
	}

	std::cout << "Done! Board is set to 0!" << std::endl << std::endl;
}

int genRandNum() {
	rn = rand() % 2; 

	return rn; 
	 
}

void random_state(std::vector<std::vector<int> > &vec) {
	std::cout << "\nSetting board values to random 1's and 0's..." << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			vec[i][j] = genRandNum();
		}
	}

	std::cout << "Done! Board is set to random 1's and 0's!" << std::endl << std::endl;
}

void print_board(std::vector<std::vector<int> > &vec) {
	std::cout << "Printing current board... " << std::endl;

	for (std::size_t i = 0; i < vec.size(); i++) {
		std::cout << "[ ";
		for (std::size_t j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " "; 
		}
		std::cout << "]" << std::endl;
	}
}