#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	Node(T input_data = T(0), Node *input_next_node = nullptr, Node *input_prev_vode = nullptr) {
		data = input_data;
		next_node = input_next_node;
		prev_vode = input_prev_vode;
	};

	Node* get_next_node() {
		return next_node;
	}

	Node* get_prev_node() {
		return prev_vode;
	}

	void set_next_node(Node *input_next_node) {
		next_node = input_next_node;
	}

	void set_prev_node(Node *input_prev_node) {
		prev_vode = input_prev_node;
	}

	void set_data(T input_data) {
		data = input_data;
	}

	T get_data() {
		return data;
	}



	~Node();

private:
	T data;
	Node *next_node, *prev_vode;
};

#endif // !NODE_H
