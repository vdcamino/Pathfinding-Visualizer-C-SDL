#ifndef _INTERACTIONS_H_
#define _INTERACTIONS_H_

#include "graph_grid.h"


// Function that handles what the user wants to do according to his clicks
void handleClick(GraphGrid* grid, SDL_Renderer* renderer, int col2, int row2);

// Function that detects user clicks and start SDL events according to user instructions
void ClickDetecter(GraphGrid* grid, SDL_Renderer* renderer);

#endif