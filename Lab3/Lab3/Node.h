#pragma once
#ifndef NODE_H
#define NODE_h

template <typename T>
class Node {
public:
	Node(Node<T> *parent = nullptr, Node<T> *left_child = nullptr, Node<T> *right_child = nullptr) {
		parent_node = parent;
		left_child_node = left_child;
		right_child_node = right_child;
	}

	Node<T> copy() {
		Node<T> result = *(new Node<T>);
		result.set_data(data);
		result.set_left_child(left_child_node);
		result.set_right_child(right_child_node);
		return result;
	}

	void set_data(T input_data) {
		data = input_data;
	}

	T get_data() {
		return data;
	}

	Node<T>* get_right_child() {
		return right_child_node;
	}

	Node<T>* get_left_child() {
		return left_child_node;
	}

	void set_right_child(Node<T> *input_node) {
		right_child_node = input_node;
	}

	void set_left_child(Node<T>* input_node) {
		left_child_node = input_node;
	}
private:
	T data;
	Node<T> *parent_node, *left_child_node, *right_child_node;
};

#endif // !NODE_H
