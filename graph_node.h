#ifndef _GRAPH_NODE_H_
#define _GRAPH_NODE_H_

typedef struct GraphNode {
	int value;
	int shortest;
	int previous_row;
	int previous_column;
	int symbol;
	int status;
} GraphNode;

// Function that prints a box 
void BoxPrint(SDL_Renderer* renderer, int col, int row);

#endif


