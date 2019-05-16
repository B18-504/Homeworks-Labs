#pragma once
#ifndef LIST_H
#define LIST_H

template <typename T>
class Node
{
public:
	Node(Node<T> *input_next_node = nullptr, Node<T> *input_prev_vode = nullptr) {
		//data = *input_data;
		next_node = input_next_node;
		prev_vode = input_prev_vode;
		priority = 0;
	};

	Node<T>* get_next_node() {
		return next_node;
	}

	Node<T>* get_prev_node() {
		return prev_vode;
	}

	void set_next_node(Node<T> *input_next_node) {
		next_node = input_next_node;
	}

	void set_prev_node(Node<T> *input_prev_node) {
		prev_vode = input_prev_node;
	}

	void set_data(T input_data) {
		data = input_data;
	}

	T get_data() {
		return data;
	}

	void set_priority(int num) {
		priority = num;
	}

	int get_priority() {
		return priority;
	}
	
private:
	T data;
	Node *next_node, *prev_vode;
	int priority;
};


template <typename T>
class List
{
public:
	List() {
		last_node = nullptr;
		fst_node = nullptr;
		tmp = nullptr;
		size = 0;
	};

	void add_node(Node<T> input_node) {
		add(input_node.get_data(), input_node.get_priority());
	}

	void add(T input_data, int priority) {
		Node<T> *local_input_node = new Node<T>;
		local_input_node->set_data(input_data);
		local_input_node->set_priority(priority);
		if (fst_node == nullptr) {
			fst_node = local_input_node;
			last_node = local_input_node;
			return;
		}

		if (last_node->get_priority() >= local_input_node->get_priority()) {
			last_node->set_next_node(local_input_node);
			local_input_node->set_prev_node(last_node);
			last_node = local_input_node;
			return;
		}

		Node<T>* local_last_node = last_node;
		while (local_last_node != nullptr) {
			if (local_last_node->get_priority() < local_input_node->get_priority()) {
				local_last_node = local_last_node->get_prev_node();
			}
			else {
				Node<T>* node = local_last_node->get_next_node();
				local_last_node->set_next_node(local_input_node);
				local_input_node->set_prev_node(local_last_node);
				local_input_node->set_next_node(node);
				node->set_prev_node(local_input_node);
				return;
			}
		}

		fst_node->set_prev_node(local_input_node);
		local_input_node->set_next_node(fst_node);
		fst_node = local_input_node;
	}

	Node<T> get_node(int index) {
		Node<T> *result_node = fst_node;
		for (int i = 0; i < index; i++) {
			result_node = result_node->get_next_node();
		}
		return *result_node;
	}

	List<T> get_sub_list(int start, int end) {
		List<T> sub_list;
		Node<T> *local_fst_node = fst_node;
		for (int i = 0; i < start; i++) {
			local_fst_node = local_fst_node->get_next_node();
		}
		for (int i = start; i <= end; i++) {
			sub_list.add(local_fst_node->get_data(), local_fst_node->get_priority());
			local_fst_node = local_fst_node->get_next_node();
		}
		return sub_list;
	}

	void map(Node<T> f(Node<T>)) {
		Node<T> *node = fst_node;
		while (node != nullptr) {
			*node = f(*node);
			node = node->get_next_node();

		}
	} 

	List<T> where(bool f(Node<T>)) {
		List<T> result_list;
		Node<T> *node = fst_node;
		while (node != nullptr) {
			if (f(*node)) {
				result_list.add_node(*node);
			}
			node = node->get_next_node();
		}
		return result_list;

	}

	Node<T> reduce(Node<T> f(Node<T>, Node<T>), Node<T> CONST) {
		if (tmp == nullptr) {
			tmp = get_fst_node_ptr();
		}
		else {
			tmp = tmp->get_next_node();
		}

		if (tmp->get_next_node() == nullptr) {
			tmp = nullptr;
			return f(*tmp, CONST);
		}
		reduce(*tmp->get_next_node(), f(*tmp, CONST));
	}

	void dvide(bool f(Node<T>)) {
		List<T> true_list, false_list;
		List<List<T>>result_list;
		Node<T>* node = fst_node;
		while (node != nullptr) {
			if (f(*node)) {
				true_list.add_node(*node);
			}
			else {
				false_list.add_node(*node);
			}
			node = node->get_next_node();
		}
		
		std::cout << "False list: ";
		print_list(false_list);
		std::cout << "\nTrue list: ";
		print_list(true_list);
	}

	List<T> list_union(List<T> input_list) {
		List<T> result_list;
		Node<T> *node = get_fst_node_ptr();
		while (node != nullptr) {
			result_list.add_node(*node);
			node = node->get_next_node();
		}
		node = input_list.get_fst_node_ptr();
		while (node != nullptr) {
			if (!find_node(*node)) {
				result_list.add_node(*node);
			}
			node = node->get_next_node();
		}
		return result_list;
	}

	bool find_node(Node<T> input_node) {
		Node<T>* node = get_fst_node_ptr();
		while (node != nullptr) {
			if (input_node.get_data() == node->get_data()) return true;
			node = node->get_next_node();
		}
		return false;
	}

	bool find_sublist(List<T> sublist) {
		Node<T> *node = fst_node;
		while (node != nullptr) {
			if (node->get_data() == sublist.get_node(0).get_data()) {
				Node<T> *sublist_node = &sublist.get_node(0);
				Node<T> *local_node = node;
				bool flag = true;
				while (sublist_node != nullptr) {
					if (local_node == nullptr) return false;
					if (sublist_node->get_data() != local_node->get_data()) {
						flag = false;
						break;
					}
					sublist_node = sublist_node->get_next_node();
					local_node = local_node->get_next_node();
				}
				if (flag) return true;
			}
			node = node->get_next_node();

		}
		return false;
	}

	void append(List<T> *input_list) {
		last_node->set_next_node(input_list->get_fst_node_ptr());
		input_list->get_fst_node_ptr()->set_prev_node(get_last_node_ptr());
	}

	Node<T> *get_fst_node_ptr() {
		return fst_node;
	}

	Node<T> *get_last_node_ptr() {
		return last_node;
	}

private:
	Node<T> *last_node;
	Node<T> *fst_node;
	Node<T>* tmp;
	unsigned long int size;
};

#endif // !LIST_H

