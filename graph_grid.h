#ifndef _GRAPH_GRID_H_
#define _GRAPH_GRID_H_

#define GRID_WIDTH 30
#define GRID_HEIGHT 30

#include "graph_node.h"

typedef struct GraphGrid {
	struct GraphNode* position[GRID_WIDTH][GRID_HEIGHT];
} GraphGrid;

// 
GraphGrid* gridInit();


void printGrid(SDL_Renderer* renderer, GraphGrid* grid, int f);
#endif
