#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

// Function that prints a box 
void BoxPrint(SDL_Renderer* renderer, int col, int row);

// Function that prints a box 
void FullBoxPrint(SDL_Renderer* renderer, int col, int row);

// Function that prints a small box (start node and final node)
void SmallBoxPrint(SDL_Renderer* renderer, int row, int col);

// Function that prints a small box (obstacle nodes)
void BigBoxPrint(SDL_Renderer* renderer, int col, int row);

// Function that prints the lines of the grid
void printLines(SDL_Renderer* renderer);

// Function that prints the repare lines of the grid
void repareLines(SDL_Renderer* renderer, int row, int col);

#endif

