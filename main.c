#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <Windows.h>
#include <math.h>
#include "graph_grid.h"
#include "graph_node.h"
#include "graphics.h"

#define WINDOW_WIDTH 601
#define GRID_HEIGHT 30
#define GRID_WIDTH 30

GraphGrid* grid;
SDL_Renderer* renderer;

int main(){
	SDL_Window* window;
	GraphGrid* grid;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Shortest Path Finder");
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	printLines(renderer);

	grid = gridInit(GRID_WIDTH, GRID_HEIGHT);

	ClickDetecter(grid);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}