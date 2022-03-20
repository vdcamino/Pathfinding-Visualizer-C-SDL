#include <stdio.h>
#include <SDL.h>

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