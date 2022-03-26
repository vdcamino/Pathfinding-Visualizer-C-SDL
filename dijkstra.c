#include <stdio.h>
#include <SDL.h>
#include "dijkstra.h"
#include "graph_grid.h"

void dijkstra(SDL_Renderer* renderer, GraphGrid* grid){
	int n = 1, row, col, m = 0;
	int k = 0;

	while (1)
	{
		grid->f = 0;
		for (row = 0; row < GRID_HEIGHT; row++)
		{
			for (col = 0; col < GRID_WIDTH; col++)
			{
				if (grid->position[col][row]->shortest == k)
				{
					if (col - 1 != 0 && row != 27 || col + 1 != 0 && row != 27 || col != 0 && row + 1 != 27)
						if (col - 1 >= 0)
							if (grid->position[col - 1][row]->symbol == 2 || grid->position[col][row + 1]->symbol == 2 || grid->position[col + 1][row]->symbol == 2)
							{
								grid->position[col][row + 1]->previous_row = row;
								grid->position[col][row + 1]->previous_column = col;
								grid->position[col][row]->symbol = 3;

								int x, y;
								while (1)
								{
									for (row = 0; row < GRID_HEIGHT; row++)
									{
										for (col = 0; col < GRID_WIDTH; col++)
										{
											if (grid->position[col][row]->symbol == 3)
											{
												x = grid->position[col][row]->previous_column;
												y = grid->position[col][row]->previous_row;

												if (grid->position[x][y]->symbol == 1)
												{
													m++;
													grid->f = 1;
													break;
												}

												grid->position[x][y]->symbol = 3;
											}
										}
										if (m > 0)
											break;
									}
									if (m > 0)
										break;
								}

								break;
							}

					grid->position[col][row]->status = -6;

					if (row - 1 >= 0 && grid->position[col][row - 1]->status == -5 && grid->position[col][row - 1]->symbol != 4)
					{
						grid->position[col][row - 1]->symbol = 5;
						grid->position[col][row - 1]->shortest = k + 1;
						grid->position[col][row - 1]->status = -6;
						grid->position[col][row - 1]->previous_row = row;
						grid->position[col][row - 1]->previous_column = col;
						grid->f = 1;
					}

					if (col - 1 >= 0 && grid->position[col - 1][row]->status == -5 && grid->position[col - 1][row]->symbol != 4)
					{
						grid->position[col - 1][row]->symbol = 5;
						grid->position[col - 1][row]->shortest = k + 1;
						grid->position[col - 1][row]->status = -6;
						grid->position[col - 1][row]->previous_row = row;
						grid->position[col - 1][row]->previous_column = col;
						grid->f = 1;
					}

					if (col + 1 < GRID_WIDTH && grid->position[col + 1][row]->status == -5 && grid->position[col + 1][row]->symbol != 4)
					{
						grid->position[col + 1][row]->symbol = 5;
						grid->position[col + 1][row]->shortest = k + 1;
						grid->position[col + 1][row]->status = -6;
						grid->position[col + 1][row]->previous_row = row;
						grid->position[col + 1][row]->previous_column = col;
						grid->f = 1;
					}

					if (row + 1 < GRID_HEIGHT && grid->position[col][row + 1]->status == -5 && grid->position[col][row + 1]->symbol != 4)
					{
						grid->position[col][row + 1]->symbol = 5;
						grid->position[col][row + 1]->shortest = k + 1;
						grid->position[col][row + 1]->status = -6;
						grid->position[col][row + 1]->previous_row = row;
						grid->position[col][row + 1]->previous_column = col;
						grid->f = 1;
					}
				}
			}

			if (m > 0)
				break;
		}
		if (grid->f == 0)
			break;

		if (m > 0)
			break;
		k++;
	}
}
