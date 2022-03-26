#include <stdio.h>
#include <SDL.h>
#include "graph_node.h"
#include "graph_grid.h"
#include "graphics.h"
#include "interactions.h"
#include "dijkstra.h"

void handleClick(GraphGrid* grid, SDL_Renderer* renderer, int col2, int row2)
{
	static int z = 0;
	int row = row2 / 20;
	int col = col2 / 20;

	switch (grid->clicks)
	{
	case 1:
		grid->position[col][row]->symbol = 1;
		grid->position[col][row]->shortest = 0;
		grid->position[col][row]->status = -6;

		SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
		SmallBoxPrint(renderer, row, col);

		grid->clicks++;
		break;

	case 2:
		if (grid->position[col][row]->symbol == 1)
		{
			grid->position[col][row]->symbol = 0;
			grid->position[col][row]->shortest = 100;
			grid->position[col][row]->status = -5;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SmallBoxPrint(renderer, row, col);

			grid->clicks--;
			break;
		}
		if (grid->position[col][row]->symbol == 0)
		{
			grid->position[col][row]->symbol = 2;
			grid->position[col][row]->shortest = -3;
			grid->position[col][row]->status = -6;

			SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
			SmallBoxPrint(renderer, row, col);

			grid->clicks++;
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

			grid->clicks--;
			break;
		}
	default:
		if (grid->n == 0 || grid->n == 1)
			if (grid->position[col][row]->symbol == 4)
			{
				grid->position[col][row]->symbol = 0;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				BigBoxPrint(renderer, row, col);
				repareLines(renderer, row, col);

				grid->clicks++;
				grid->n = 1;
				break;
			}
		if (grid->n == 0 || grid->n == 2)
			if (grid->position[col][row]->symbol == 0)
			{
				grid->position[col][row]->symbol = 4;

				SDL_SetRenderDrawColor(renderer, 0, 51, 102, 255);
				BigBoxPrint(renderer, row, col);

				grid->clicks++;
				grid->n = 2;
				break;
			}
	}
}

void ClickDetecter(GraphGrid* grid, SDL_Renderer* renderer)
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
				handleClick(grid, renderer, x, y);
			}
			else if (grid->clicks > 3)
			{
				handleClick(grid, renderer, x, y);
			}
		}
		else
		{
			grid->n = 0;
			mousePressed = 0;
		}

		if (buttons & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			if (rightPressed == 0)
			{
				rightPressed = 1;

				dijkstra(renderer, grid);

				printGrid(renderer, grid);

				grid->n = 3;
			}
		}
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
}