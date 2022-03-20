#include <stdio.h>
#include <SDL.h>
#include "graphics.h"

// Function that prints a box 
void BoxPrint(SDL_Renderer* renderer, int col, int row){
	int row2, col2, cont;
	for (cont = 10; cont >= 0; cont--){
		for (row2 = 1 + (20 * row) + cont; row2 <= 19 + (20 * row) - cont; row2++)
			for (col2 = 1 + (20 * col) + cont; col2 <= 19 + (20 * col) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		SDL_RenderPresent(renderer);
	}
}

// Function that prints a box 
void FullBoxPrint(SDL_Renderer* renderer, int col, int row){
	int row2, col2, cont;
	for (cont = 6; cont >= 0; cont--) {
		for (row2 = (20 * row) + cont; row2 <= 20 + (20 * row) - cont; row2++)
			for (col2 = (20 * col) + cont; col2 <= 20 + (20 * col) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		SDL_RenderPresent(renderer);
	}
}

// Function that prints a small box (start node and final node)
void SmallBoxPrint(SDL_Renderer* renderer, int row, int col){
	int row2, col2, cont;
	for (cont = 6; cont >= 0; cont--){
		for (row2 = 4 + (20 * col) + cont; row2 <= 16 + (20 * col) - cont; row2++)
			for (col2 = 4 + (20 * row) + cont; col2 <= 16 + (20 * row) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		Sleep(10);
		SDL_RenderPresent(renderer);
	}
}

// Function that prints a small box (obstacle nodes)
void BigBoxPrint(SDL_Renderer* renderer, int col, int row){
	int row2, col2, cont;
	for (cont = 6; cont >= 0; cont--){
		for (row2 = (20 * row) + cont; row2 <= 20 + (20 * row) - cont; row2++)
			for (col2 = (20 * col) + cont; col2 <= 20 + (20 * col) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		Sleep(10);
		SDL_RenderPresent(renderer);
	}
}

// Function that prints the lines of the grid
void printLines(SDL_Renderer* renderer){
	int col, row;
	SDL_SetRenderDrawColor(renderer, 205, 205, 155, 255);
	for (row = 0; row <= 600 * 2; row += 20)
		for (col = 0; col <= 600 * 2; col++)
			SDL_RenderDrawPoint(renderer, col, row);
	for (col = 0; col <= 600 * 2; col += 20)
		for (row = 0; row <= 600 * 2; row++)
			SDL_RenderDrawPoint(renderer, col, row);
	SDL_RenderPresent(renderer);
}

// Function that prints the repare lines of the grid
void repareLines(SDL_Renderer* renderer, int row, int col){
	int col2, row2;
	SDL_SetRenderDrawColor(renderer, 205, 205, 155, 255);
	for (row2 = row * 20; row2 <= (row * 20) + 20; row2 += 20)
		for (col2 = col * 20; col2 <= (col * 20) + 20; col2++)
			SDL_RenderDrawPoint(renderer, col2, row2);
	for (col2 = col * 20; col2 <= (col * 20) + 20; col2 += 20)
		for (row2 = row * 20; row2 <= (row * 20) + 20; row2++)
			SDL_RenderDrawPoint(renderer, col2, row2);
	SDL_RenderPresent(renderer);
}