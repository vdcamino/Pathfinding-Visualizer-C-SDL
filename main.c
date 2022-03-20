#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <Windows.h>
#include <math.h>
#include "graph_grid.h"
#include "graph_node.h"

#define WINDOW_WIDTH 601
#define GRID_HEIGHT 30
#define GRID_WIDTH 30

GraphGrid grid;

SDL_Renderer* renderer;

int clicks = 1, f = 0;

void BigBoxPrint(int col, int row)
{
	int row2, col2, cont;

	for (cont = 6; cont >= 0; cont--)
	{
		for (row2 = (20 * row) + cont; row2 <= 20 + (20 * row) - cont; row2++)
			for (col2 = (20 * col) + cont; col2 <= 20 + (20 * col) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		Sleep(10);

		SDL_RenderPresent(renderer);
	}
}

void FullBoxPrint(int col, int row)
{
	int row2, col2, cont;

	for (cont = 6; cont >= 0; cont--)
	{
		for (row2 = (20 * row) + cont; row2 <= 20 + (20 * row) - cont; row2++)
			for (col2 = (20 * col) + cont; col2 <= 20 + (20 * col) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);

		SDL_RenderPresent(renderer);
	}
}
void SmallBoxPrint(int row, int col)
{
	int row2, col2, cont;

	for (cont = 6; cont >= 0; cont--)
	{
		for (row2 = 4 + (20 * col) + cont; row2 <= 16 + (20 * col) - cont; row2++)
			for (col2 = 4 + (20 * row) + cont; col2 <= 16 + (20 * row) - cont; col2++)
				SDL_RenderDrawPoint(renderer, row2, col2);
		Sleep(10);

		SDL_RenderPresent(renderer);
	}
}

void gridInit()
{
	int cont = 1;

	for (int row = 0; row < GRID_HEIGHT; row++)
		for (int col = 0; col < GRID_WIDTH; col++)
		{
			grid.position[col][row].symbol = 0;
			grid.position[col][row].value = cont; cont++;
			grid.position[col][row].shortest = 100;
			grid.position[col][row].previous_column = -10;
			grid.position[col][row].previous_row = -20;
			grid.position[col][row].status = -5;
		}
}

void printGrid()
{
	int s_cont = 0, m = 0, l = 0, z = 0;
	static int k = 0;

	while (1)
	{
		for (int row = 0; row < GRID_HEIGHT; row++)
		{
			for (int col = 0; col < GRID_WIDTH; col++)
			{
				if (grid.position[col][row].shortest == s_cont)
				{
					int cell = 0;
					if (row - 1 >= 0)
					{
						cell = grid.position[col][row - 1].symbol;
					}

					switch (cell)
					{
					case 1:
						if (k == 0 && l == 0)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row - 1, col);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row - 1, col);
							l++;
						}
						if (k == 1 && z == 0)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row - 1, col);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row - 1, col);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row - 1, col);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(row - 1, col);
						}
						if (col - 1 != 0 && row != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(row - 1, col);
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
						cell_2 = grid.position[col - 1][row].symbol;
					}


					switch (cell_2)
					{
					case 1:
						if (k == 0 && l == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col - 1);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row, col - 1);
							l++;
						}
						if (k == 1 && z == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row, col - 1);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row, col - 1);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row, col - 1);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(row, col - 1);
						}
						if (col != 0 && row - 1 != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(row, col - 1);
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

					int cell_3 = grid.position[col][row + 1].symbol;

					switch (cell_3)
					{
					case 1:
						if (k == 0 && l == 2)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row + 1, col);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row + 1, col);
							l++;
						}
						if (k == 1 && z == 2)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row + 1, col);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row + 1, col);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row + 1, col);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(row + 1, col);
						}
						if (col + 1 != 0 && row != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(row + 1, col);
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

					int cell_4 = grid.position[col + 1][row].symbol;

					switch (cell_4)
					{
					case 1:
						if (k == 0 && l == 3)
						{
							SDL_SetRenderDrawColor(renderer, 255, 255, 204, 255);
							BoxPrint(renderer, row, col + 1);

							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row, col + 1);
							l++;
						}
						if (k == 1 && z == 3)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row, col + 1);
							}
							SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
							SmallBoxPrint(row, col + 1);
							z++;
						}
						break;

					case 2:
						if (k == 1)
						{
							if (f == 1)
							{
								SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
								FullBoxPrint(row, col + 1);
							}
							else
								printf("\a");
							SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
							SmallBoxPrint(row, col + 1);
						}
						if (col != 0 && row + 1 != 27)
							m++;
						break;

					case 3:
						if (k == 1)
						{
							SDL_SetRenderDrawColor(renderer, 255, 153, 204, 255);
							FullBoxPrint(row, col + 1);
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
		printGrid();
	}
}

void dijkstra()
{
	int n = 1, row, col, m = 0;
	int k = 0;

	while (1)
	{
		f = 0;
		for (row = 0; row < GRID_HEIGHT; row++)
		{
			for (col = 0; col < GRID_WIDTH; col++)
			{
				if (grid.position[col][row].shortest == k)
				{
					if (col - 1 != 0 && row != 27 || col + 1 != 0 && row != 27 || col != 0 && row + 1 != 27)
						if (col - 1 >= 0)
							if (grid.position[col - 1][row].symbol == 2 || grid.position[col][row + 1].symbol == 2 || grid.position[col + 1][row].symbol == 2)
							{
								grid.position[col][row + 1].previous_row = row;
								grid.position[col][row + 1].previous_column = col;
								grid.position[col][row].symbol = 3;

								int x, y;
								while (1)
								{
									for (row = 0; row < GRID_HEIGHT; row++)
									{
										for (col = 0; col < GRID_WIDTH; col++)
										{
											if (grid.position[col][row].symbol == 3)
											{
												x = grid.position[col][row].previous_column;
												y = grid.position[col][row].previous_row;

												if (grid.position[x][y].symbol == 1)
												{
													m++;
													f = 1;
													break;
												}

												grid.position[x][y].symbol = 3;
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

					grid.position[col][row].status = -6;

					if (row - 1 >= 0 && grid.position[col][row - 1].status == -5 && grid.position[col][row - 1].symbol != 4)
					{
						grid.position[col][row - 1].symbol = 5;
						grid.position[col][row - 1].shortest = k + 1;
						grid.position[col][row - 1].status = -6;
						grid.position[col][row - 1].previous_row = row;
						grid.position[col][row - 1].previous_column = col;
						f = 1;
					}

					if (col - 1 >= 0 && grid.position[col - 1][row].status == -5 && grid.position[col - 1][row].symbol != 4)
					{
						grid.position[col - 1][row].symbol = 5;
						grid.position[col - 1][row].shortest = k + 1;
						grid.position[col - 1][row].status = -6;
						grid.position[col - 1][row].previous_row = row;
						grid.position[col - 1][row].previous_column = col;
						f = 1;
					}

					if (col + 1 < GRID_WIDTH && grid.position[col + 1][row].status == -5 && grid.position[col + 1][row].symbol != 4)
					{
						grid.position[col + 1][row].symbol = 5;
						grid.position[col + 1][row].shortest = k + 1;
						grid.position[col + 1][row].status = -6;
						grid.position[col + 1][row].previous_row = row;
						grid.position[col + 1][row].previous_column = col;
						f = 1;
					}

					if (row + 1 < GRID_HEIGHT && grid.position[col][row + 1].status == -5 && grid.position[col][row + 1].symbol != 4)
					{
						grid.position[col][row + 1].symbol = 5;
						grid.position[col][row + 1].shortest = k + 1;
						grid.position[col][row + 1].status = -6;
						grid.position[col][row + 1].previous_row = row;
						grid.position[col][row + 1].previous_column = col;
						f = 1;
					}
				}
			}

			if (m > 0)
				break;
		}
		if (f == 0)
			break;

		if (m > 0)
			break;
		k++;
	}
}

void printLines()
{
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

void repareLines(int row, int col)
{
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

int n = 2;

void handleClick(int col2, int row2)
{
	static int z = 0;
	int row = row2 / 20;
	int col = col2 / 20;

	switch (clicks)
	{
	case 1:
		grid.position[col][row].symbol = 1;
		grid.position[col][row].shortest = 0;
		grid.position[col][row].status = -6;

		SDL_SetRenderDrawColor(renderer, 255, 102, 0, 255);
		SmallBoxPrint(row, col);

		clicks++;
		break;

	case 2:
		if (grid.position[col][row].symbol == 1)
		{
			grid.position[col][row].symbol = 0;
			grid.position[col][row].shortest = 100;
			grid.position[col][row].status = -5;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SmallBoxPrint(row, col);

			clicks--;
			break;
		}
		if (grid.position[col][row].symbol == 0)
		{
			grid.position[col][row].symbol = 2;
			grid.position[col][row].shortest = -3;
			grid.position[col][row].status = -6;

			SDL_SetRenderDrawColor(renderer, 102, 255, 51, 255);
			SmallBoxPrint(row, col);

			clicks++;
			break;
		}
	case 3:
		if (grid.position[col][row].symbol == 2)
		{
			grid.position[col][row].symbol = 0;
			grid.position[col][row].shortest = 100;
			grid.position[col][row].status = -5;

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SmallBoxPrint(row, col);

			clicks--;
			break;
		}
	default:
		if (n == 0 || n == 1)
			if (grid.position[col][row].symbol == 4)
			{
				grid.position[col][row].symbol = 0;

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				BigBoxPrint(row, col);
				repareLines(row, col);

				clicks++;
				n = 1;
				break;
			}
		if (n == 0 || n == 2)
			if (grid.position[col][row].symbol == 0)
			{
				grid.position[col][row].symbol = 4;

				SDL_SetRenderDrawColor(renderer, 0, 51, 102, 255);
				BigBoxPrint(row, col);

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

				dijkstra();

				printGrid();

				n = 3;
			}
		}
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
}

int main(void)
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Shortest Path Finder");
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	printLines();

	gridInit();

	ClickDetecter();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}