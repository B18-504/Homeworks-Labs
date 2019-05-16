#pragma once
#ifndef LISTIO_H
#define LISTIO_H
#include "List.h"

template <typename T>
void read_list(List<T> *list, int size) {
	T data;
	int preority;
	for (int i = 0; i < size; i++) {
		std::cin >> data;
		std::cin >> preority;
		list->add(data, preority);
	}
}

template <typename T>
void print_list(List<T> list) {
	Node<T> *node = list.get_fst_node_ptr();
	while (node != nullptr) {
		std::cout << node->get_data() << " ";
		node = node->get_next_node();
	}
	std::cout << "\n";
}

#endif // !LISTIO_H
