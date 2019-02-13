#ifndef MAIN_H_
#define	MAIN_H_

//A C++ implementation of Conway's cellular automaton Game of Life
// https://robertheaton.com/2018/07/20/project-2-game-of-life/


// Header file containing all function declarations

#include <iostream> /* io */
#include <string> /* string */
#include <vector> /* vectors */
#include <stdio.h> /* NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */

std::vector<std::vector<int> > boardVect;

int width, height, rn, aliveNeighborCount; 

int main(); 

void resize_board(std::vector<std::vector<int> > &vec, int w, int h); 

void dead_state(std::vector<std::vector<int> > &vec);

int genRandNum(); 

void random_state   (std::vector<std::vector<int> > &vec);

void print_board(std::vector<std::vector<int> > &vec);

void check_neighbors(std::vector<std::vector<int> > &vec);

void next_board_state(std::vector<std::vector<int> > &vec, int i, int j, int count);
#endif