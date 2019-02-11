#ifndef MAIN_H_
#define	MAIN_H_

//A C++ implementation of Conway's cellular automaton Game of Life
// https://robertheaton.com/2018/07/20/project-2-game-of-life/

#include <iostream> /* io */
#include <string> /* string */
#include <vector> /* vectors */
#include <stdio.h> /* NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */

std::vector<std::vector<int> > boardVect;

int width, height, rn; 

int main(); 

void resize_board(std::vector<std::vector<int> > &vec, int w, int h); 

void dead_state(std::vector<std::vector<int> > &vec);

int genRandNum(); 

void random_state   (std::vector<std::vector<int> > &vec);

void print_board(std::vector<std::vector<int> > &vec);

#endif