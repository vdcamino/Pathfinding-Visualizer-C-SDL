#ifndef _GRAPH_GRID_H_
#define _GRAPH_GRID_H_

#define GRID_WIDTH 30
#define GRID_HEIGHT 30

#include "graph_node.h"

typedef struct GraphGrid {
	struct GraphNode* position[GRID_WIDTH][GRID_HEIGHT];
	int n;
	int f;
	int clicks;
} GraphGrid;

// 
GraphGrid* gridInit(int grid_width, int grid_height);


void printGrid(SDL_Renderer* renderer, GraphGrid* grid);
#endif
