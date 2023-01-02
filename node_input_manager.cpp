#include"헤더.h"
#include<algorithm>
NodeInputManager::NodeInputManager(struct NODE* node) {
	//input
	std::string str,str_2;
	std::cout << "그래프의 차수를 입력해주세요>>>>>";
	std::cin >> node->node_size;

	start_node = new int[node->node_size];
	end_node = new int[node->node_size];

	std::cout << "시작 노드를 입력해주세요";
	std::cin >> str;
	for (int i = 0; i < node->node_size; i++) {
		start_node[i] = (int)str.c_str()[i] - 48;
	}

	std::cout << "도착노드를 입력해주세요";
	std::cin >> str_2;
	for (int i = 0; i < node->node_size; i++) {
		end_node[i] = (int)str_2.c_str()[i] - 48;
	}
	node->node = new int[node->node_size];
	node->end_node = new int[node->node_size];
	node->distance = 0;
	node->node_route = "";
	//input
}
NODE NodeInputManager::get_NODE(struct NODE* node) {
	std::copy(start_node, &start_node[node->node_size], node->node);
	std::copy(end_node, &end_node[node->node_size], node->end_node);

	
	struct NODE n = { node->node_size, start_node , end_node, 0, "" };
	return n;

}


void EDGE::g(int edge_number,struct NODE* n) {


	int save_data;
	for (int i = 0; i < edge_number; i++) {
		save_data = n->node[i];
		n->node[i] = n->node[i + edge_number];
		n->node[i + edge_number] = save_data;
	}

	std::string a = "";
	for (int i = 0; i < n->node_size; i++) {
		a = a + (char)(n->node[i] + 48);
	}
	char c[2] = { 'g',(char)edge_number + 48 };
	n->node_route = n->node_route + "->" + 'g', (char)(edge_number + 48) + "->" + a;
	n->distance++;
}
void EDGE::u(int edge_number, struct NODE* n) {


	int save_data;
	save_data = n->node[0];
	n->node[0] = n->node[edge_number - 1];
	n->node[edge_number - 1] = save_data;


	std::string a = "";
	for (int i = 0; i < n->node_size; i++) {
		a = a + (char)(n->node[i] + 48);
	}
	n->node_route = n->node_route + "->" + 'u', (char)(edge_number + 48) + "->" + a;
	n->distance++;
}
