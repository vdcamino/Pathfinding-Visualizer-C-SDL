#ifndef _GRAPH_GRID_H_
#define _GRAPH_GRID_H_

#define GRID_WIDTH 30
#define GRID_HEIGHT 30

#include "graph_node.h"

typedef struct GraphGrid {
	GraphNode position[GRID_WIDTH][GRID_HEIGHT];
} GraphGrid;

#endif
