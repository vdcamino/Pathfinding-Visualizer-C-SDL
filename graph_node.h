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

#endif


