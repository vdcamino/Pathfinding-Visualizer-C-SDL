#ifndef _GRAPH_NODE_H_
#define _GRAPH_NODE_H_

#include <stdbool.h>

typedef struct GraphNode {
	bool isVisited;
	int prev_row;
	int prev_col;
} GraphNode;

#endif


