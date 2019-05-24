// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tree.h"
#include <string>

Node<int> map(Node<int> a) {
	a.set_data(a.get_data() + 2);
	return a;
}

Node<float> map(Node<float> a) {
	a.set_data(a.get_data() + 2);
	return a;
}

Node<std::string> map(Node<std::string> a) {
	a.set_data(a.get_data() + "pp");
	return a;
}

bool where(Node<int> a) {
	if (a.get_data() > 54) return true;
	return false;
}

bool where(Node<float> a) {
	if (a.get_data() > 54) return true;
	return false;
}

bool where(Node<std::string> a) {
	if (a.get_data().length() > 10) return true;
	return false;
}

template <typename T>
void loop(T type) {
	std::vector<T> v;
	Tree<T> tree;
	int tree_size;
	std::cout << "Enter size of tree: ";
	std::cin >> tree_size;
	for (int i = 0; i < tree_size; i++) {
		T data;
		std::cin >> data;
		Node<T> node;
		node.set_data(data);
		tree.add(node);
	}
	std::cout << "Select action:\n1 - map\n2 - where\n3 - union\n4 - get subtree\n5 - find subtree\n6 - find node\n7 - show PKL\n8 - show LKP\n9 - exit\n";
	while (true) {
		std::cout << "Enter action: ";
		int action;
		T dt;
		std::cin >> action;
		Tree<T> result = *new Tree<T>;
		Tree<T> appending_tree = *new Tree<T>;

		if (action == 1) {
			tree.map(map, tree.get_root(), &result);
			tree = result;
		}
		else if (action == 2) {
			tree.where(where, tree.get_root(), &result);
			tree = result;
		}
		else if (action == 3) {
			std::cout << "Enter size of appending tree: ";
			std::cin >> tree_size;
			for (int i = 0; i < tree_size; i++) {
				T data;
				std::cin >> data;
				Node<T> node;
				node.set_data(data);
				appending_tree.add(node);
			}
			tree = tree.tree_union(appending_tree);
		}
		else if (action == 4) {
			std::cout << "Enter data: ";
			std::cin >> dt;
			if (tree.get_subtree(dt, &result)) {
				std::cout << "1 - show result PKL\n2 - show result LKP\n3 - don't show result\n";
				int showType;
				std::cin >> showType;
				if (showType == 1) {
					result.showPKL();
				}
				else if (showType == 2) {
					result.showLKP();
				}
			}
			else {
				std::cout << "Can't found root node " << dt << std::endl;
			}
		}
		else if (action == 5) {
			std::cout << "Enter size of finding subtree: ";
			Tree<T> subtree;
			std::cin >> tree_size;
			for (int i = 0; i < tree_size; i++) {
				T data;
				std::cin >> data;
				Node<T> node;
				node.set_data(data);
				subtree.add(node);
			}
			v.clear();
			result.PKL(subtree.get_root(), &v);
			for (int i = 0; i < v.size(); i++) {
				std::cout << v[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Result: ";
			if (tree.find_subtree(&subtree)) {
				std::cout << "true";
			}
			else {
				std::cout << "false";
			}
			std::cout << std::endl;
		}
		else if (action == 6) {
			std::cout << "Enter data: ";
			T a;
			std::cin >> a;
			Node<T> node;
			node.set_data(a);
			if (tree.find_node(tree.get_root(), node)) {
				std::cout << "Result: true\n";
			}
			else {
				std::cout << "Result: false\n";
			}
		}
		else if (action == 7) {
			tree.showPKL();
		}
		else if (action == 8) {
			tree.showLKP();
		}
		else if (action == 9) {
			break;
		}
		else {
			std::cout << "Invalid action!!!\n";
		}
	}
}

int main()
{
	std::string str = " ";
	float flt = 0.0;
	int it = 0;
	std::cout << "Select input data type: \n1 - Integer\n2 - Float\n3 - String\n";
	int type;
	std::cin >> type;
	if (type == 1) {
		loop(it);
	}
	else if (type == 2) {
		loop(flt);
	}
	else if (type == 3) {
		loop(str);
	}
	else {
		std::cout << "Invalid type!!!\n";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
