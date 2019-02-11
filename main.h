#ifndef MAIN_H_
#define	MAIN_H_

#include <iostream> // io
#include <string> // strings
#include <vector> // vector
#include <cstdlib>
#include <random> 
#include <stdio.h> // NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time

std::vector<std::vector<int> > boardVect;

int width, height, rn; 

int main(); 

void resize_board(std::vector<std::vector<int> > &vec, int w, int h); 

void dead_state(std::vector<std::vector<int> > &vec);

int genRandNum(); 

void random_state   (std::vector<std::vector<int> > &vec);

void print_board(std::vector<std::vector<int> > &vec);

#endif