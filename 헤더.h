#pragma once
#include<vector>
#include<iostream>
struct NODE {
	int node_size;

	int* node;
	int* end_node;

	int distance;
	std::string node_route;
	
};

class NodeInputManager {
private:
	int* start_node;
	int* end_node;
public:
	NodeInputManager(struct NODE* node);
	struct NODE get_NODE(struct NODE* node);
};


class EDGE {
public:
	void g(int a, struct NODE* b);
	void u(int a, struct NODE* b);
};