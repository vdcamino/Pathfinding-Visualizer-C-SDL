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

int clicks = 1, f = 0;

int n = 2;

void handleClick(int col2, int row2)
{
	static int z = 0;
	int row = row2 / 20;
	int col = col2 / 20;

	switch (clicks)
	{
	case 1:
		grid->position[col][row]->symbol = 1;
		grid->position[col][row]->shortest = 0;
		grid->position[col][row]->status = -6;

		SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
		SmallBoxPrint(renderer, row, col);

		clicks++;
		break;

	case 2:
		if (grid->position[col][row]->symbol == 1)
		{
			grid->position[col][row]->symbol = 0;
			grid->position[col][row]->shortest = 100;
			grid->position[col][row]->status = -5;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SmallBoxPrint(renderer, row, col);

			clicks--;
			break;
		}
		if (grid->position[col][row]->symbol == 0)
		{
			grid->position[col][row]->symbol = 2;
			grid->position[col][row]->shortest = -3;
			grid->position[col][row]->status = -6;

			SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
			SmallBoxPrint(renderer, row, col);

			clicks++;
			break;
		}
	case 3:
		if (grid->position[col][row]->symbol == 2)
		{
			grid->position[col][row]->symbol = 0;
			grid->position[col][row]->shortest = 100;
			grid->position[col][row]->status = -5;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SmallBoxPrint(renderer, row, col);

			clicks--;
			break;
		}
	default:
		if (n == 0 || n == 1)
			if (grid->position[col][row]->symbol == 4)
			{
				grid->position[col][row]->symbol = 0;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				BigBoxPrint(renderer, row, col);
				repareLines(renderer, row, col);

				clicks++;
				n = 1;
				break;
			}
		if (n == 0 || n == 2)
			if (grid->position[col][row]->symbol == 0)
			{
				grid->position[col][row]->symbol = 4;

				SDL_SetRenderDrawColor(renderer, 0, 51, 102, 255);
				BigBoxPrint(renderer, row, col);

				clicks++;
				n = 2;
				break;
			}
	}
}

void ClickDetecter()
{
	int mousePressed = 0;
	int rightPressed = 0;

	SDL_Event event;

	while (1)
	{
		unsigned int buttons;
		int x, y;

		buttons = SDL_GetMouseState(&x, &y);

		if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			if (mousePressed == 0)
			{
				mousePressed = 1;
				handleClick(x, y);
			}
			else if (clicks > 3)
			{
				handleClick(x, y);
			}
		}
		else
		{
			n = 0;
			mousePressed = 0;
		}

		if (buttons & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			if (rightPressed == 0)
			{
				rightPressed = 1;

				dijkstra(renderer, grid, f);

				printGrid(renderer, grid, f);

				n = 3;
			}
		}
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
}

int main(void){
	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Shortest Path Finder");
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	printLines(renderer);

	grid = gridInit();

	ClickDetecter();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}