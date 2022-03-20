#include <stdio.h>
#include <SDL.h>
#include "graph_node.h"
#include "graph_grid.h"
#include "graphics.h"

// Initialize the grid with +inf partout
GraphGrid* gridInit(){
	GraphGrid* grid = (GraphGrid*)malloc(sizeof(GraphGrid));
	int cont = 1;
	for (int row = 0; row < GRID_HEIGHT; row++)
		for (int col = 0; col < GRID_WIDTH; col++){
			grid->position[col][row]->symbol = 0;
			grid->position[col][row]->value = cont; cont++;
			grid->position[col][row]->shortest = 100;
			grid->position[col][row]->previous_column = -10;
			grid->position[col][row]->previous_row = -20;
			grid->position[col][row]->status = -5;
		}
	return grid;
}

void printGrid(SDL_Renderer* renderer, GraphGrid* grid, int f)
{
	int s_cont = 0, m = 0, l = 0, z = 0;
	static int k = 0;

	while (1)
	{
		for (int row = 0; row < GRID_HEIGHT; row++)
		{
			for (int col = 0; col < GRID_WIDTH; col++)
			{
				if (grid->position[col][row]->shortest == s_cont)
				{
					int cell = 0;
					if (row - 1 >= 0)
					{
						cell = grid->position[col][row - 1]->symbol;
					}

					switch (cell)
					{
					case 1:
						if (k == 0 && l == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row - 1, col);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row - 1, col);
							l++;
						}
						if (k == 1 && z == 0)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row - 1, col);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row - 1, col);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row - 1, col);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(renderer, row - 1, col);
						}
						if (col - 1 != 0 && row != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(renderer, row - 1, col);
						}
						else
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row - 1, col);
						}
						break;

					case 5:
						if (k == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row - 1, col);
						}
						break;
					}


					int cell_2 = 0;
					if (col - 1 >= 0)
					{
						cell_2 = grid->position[col - 1][row]->symbol;
					}


					switch (cell_2)
					{
					case 1:
						if (k == 0 && l == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col - 1);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row, col - 1);
							l++;
						}
						if (k == 1 && z == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row, col - 1);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row, col - 1);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row, col - 1);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(renderer, row, col - 1);
						}
						if (col != 0 && row - 1 != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(renderer, row, col - 1);
						}
						else
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col - 1);
						}
						break;

					case 5:
						if (k == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col - 1);
						}
						break;
					}

					int cell_3 = grid->position[col][row + 1]->symbol;

					switch (cell_3)
					{
					case 1:
						if (k == 0 && l == 2)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row + 1, col);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row + 1, col);
							l++;
						}
						if (k == 1 && z == 2)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row + 1, col);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row + 1, col);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row + 1, col);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(renderer, row + 1, col);
						}
						if (col + 1 != 0 && row != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(renderer, row + 1, col);
						}
						else
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row + 1, col);
						}
						break;

					case 5:
						if (k == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row + 1, col);
						}
						break;
					}

					int cell_4 = grid->position[col + 1][row]->symbol;

					switch (cell_4)
					{
					case 1:
						if (k == 0 && l == 3)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col + 1);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row, col + 1);
							l++;
						}
						if (k == 1 && z == 3)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row, col + 1);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(renderer, row, col + 1);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(renderer, row, col + 1);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(renderer, row, col + 1);
						}
						if (col != 0 && row + 1 != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(renderer, row, col + 1);
						}
						else
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col + 1);
						}
						break;

					case 5:
						if (k == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col + 1);
						}
						break;
					}

					if (m >= 1)
						break;
				}
			}
			if (m >= 1)
				break;
		}
		s_cont++;
		if (m >= 1)
			break;
	}

	if (k == 0)
	{
		k = 1;
		printGrid(renderer, grid, f);
	}
}