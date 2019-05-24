#pragma once
#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <vector>

template <typename T>
class Tree {
public:
	Tree(Node<T>* input_data = nullptr) {
		root = input_data;
		if (root != nullptr) {
			depth = 1;
			size = 1;
		}
		else {
			depth = 1;
			size = 1;
		}
	}

	Node<T>* get_root() {
		return root;
	}

	void set_root(Node<T> *input_node) {
		root = input_node;
	}

	bool get_ref(Node<T> *current_node,T data, Node<T>* result) {
		if (current_node == nullptr) return false;
		if (current_node->get_data() == data) { *result = current_node->copy();
		return true; }
		if (get_ref(current_node->get_left_child(), data, result) || get_ref(current_node->get_right_child(), data, result)) return true;
		return false;
	}

	void balance(Node<T>* current_node, Node<T>* input_node) {
		if (input_node->get_data() >= current_node->get_data()) {// Right child
			if (current_node->get_right_child() == nullptr) {
				current_node->set_right_child(input_node);
			}
			else {
				balance(current_node->get_right_child(), input_node);
			}
		}
		else {// Left child
			if (current_node->get_left_child() == nullptr) {
				current_node->set_left_child(input_node);
			}
			else {
				balance(current_node->get_left_child(), input_node);
			}
		}
	}

	void add(Node<T> input_node) {
		Node<T> *buff = new Node<T>;
		buff->set_data(input_node.get_data());
		if (root == nullptr) {
			root = buff;
		}
		else {
			balance(root, buff);
		}
	}

	void map(Node<T> f(Node<T>), Node<T> *current_node, Tree<T> *result_tree) {
		if (current_node == nullptr) return;
		result_tree->add(f(*current_node));
		map(f, current_node->get_left_child(), result_tree);
		map(f, current_node->get_right_child(), result_tree);
	}

	void where(bool f(Node<T>), Node<T>* current_node, Tree<T>* result_tree) {
		if (current_node == nullptr) return;
		if (f(*current_node)) {
			result_tree->add(*current_node);
		}
		where(f, current_node->get_left_child(), result_tree);
		where(f, current_node->get_right_child(), result_tree);
	}

	bool get_subtree(T data, Tree<T> *result_tree) {
		Node<T>* current_node = new Node<T>;
		if (get_ref(root, data, current_node) == false) return false;
		result_tree->set_root(current_node);
		return true;
	}

	bool check_subtree(Node<T> *current_tree_node, Node<T> *current_subtree_node) {
		if (current_subtree_node == nullptr) return true;
		if ((current_subtree_node == nullptr || current_tree_node == nullptr) && current_subtree_node != current_tree_node) return false;
		if (current_subtree_node == nullptr && current_tree_node == nullptr) return true;
		if (check_subtree(current_tree_node->get_left_child(), current_subtree_node->get_left_child()) && check_subtree(current_tree_node->get_right_child(), current_subtree_node->get_right_child())) {
			if (current_subtree_node->get_data() == current_tree_node->get_data()) return true;
			return false;
		}
		return false;
	}

	bool find_subtree(Tree<T> *input_tree) {
		Node<T>* incoming_node = new Node<T>;
		if (get_ref(root, input_tree->get_root()->get_data(), incoming_node)) {
			if (check_subtree(incoming_node, input_tree->get_root())) return true;
		}
		return false;
	}

	bool find_node(Node<T> *current_node, Node<T> input_node) {
		if (current_node == nullptr) return false;
		if (current_node->get_data() == input_node.get_data()) return true;
		if (find_node(current_node->get_left_child(), input_node) || find_node(current_node->get_right_child(), input_node)) return true;
		return false;
	}

	void add_tree(Tree<T>* current_tree, Node<T>* input_node) {
		if (input_node == nullptr) return;
		current_tree->add(*input_node);
		add_tree(current_tree, input_node->get_left_child());
		add_tree(current_tree, input_node->get_right_child());
	}

	Tree<T> tree_union(Tree<T> input_tree) {
		Tree<T> result;
		result.add_tree(&result, root);
		result.add_tree(&result, input_tree.get_root());
		return result;
	}

	void PKL(Node<T> *current_node, std::vector<T>* result) {
		if (current_node->get_right_child() != nullptr) PKL(current_node->get_right_child(), result);
		result->push_back(current_node->get_data());
		if (current_node->get_left_child() != nullptr)PKL(current_node->get_left_child(), result);
	}

	void LKP(Node<T>* current_node, std::vector<T>* result) {
		if (current_node->get_left_child() != nullptr) LKP(current_node->get_left_child(), result);
		result->push_back(current_node->get_data());
		if (current_node->get_right_child() != nullptr) LKP(current_node->get_right_child(), result);
	}

	void showPKL() {
		std::vector<T> v;
		v.clear();
		PKL(root, &v);
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}

	void showLKP() {
		std::vector<T> v;
		v.clear();
		LKP(root, &v);
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	Node<T> *root;
	int depth, size;
};

#endif // !TREE_H

