// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "List.h"
#include "ListIO.h"
#include "complex.h"
#include <string>
#include <ctype.h>

bool my_where(Node<int> node) {
	if (node.get_data() >= 0) {
		return true;
	}
	return false;
}

bool my_where(Node<std::string> node) {
	if (node.get_data().length() >= 2) {
		return true;
	}
	return false;
}

bool my_where(Node<complex> node) {
	if (node.get_data().real >= 0) {
		return true;
	}
	return false;
}

Node<int> my_map(Node<int> node) {
	node.set_data(node.get_data() * 8);
	return node;
}

Node<std::string> my_map(Node<std::string> node) {
	node.set_data(node.get_data() += 'M');
	return node;
}

Node<complex> my_map(Node<complex> node) {
	complex super_node;
	super_node = (node.get_data());
	super_node.image *= 2;
	node.set_data(super_node);
	return node;
}

bool my_dvide(Node<int> node) {
	if (node.get_data() >= 0) {
		return true;
	}
	return false;
}

bool my_dvide(Node<std::string> node) {
	if (node.get_data().length() >= 2) {
		return true;
	}
	return false;
}

bool my_dvide(Node<complex> node) {
	if (node.get_data().real >= 0 && node.get_data().image >= 0) {
		return true;
	}
	return false;
}

template <typename T>
void loop(T type) {
	List<T> list;
	int list_size;
	std::cout << "Enter size of list: ";
	std::cin >> list_size;
	read_list(&list, list_size);
	std::cout << "Select action: 1 - map\n2 - where\n3 - concatenation\n4 - get sublist\n5 - find sublist\n6 - union\n7 - dvide\n8 - show the list\n9 - exit\n";
	while (true) {
		std::cout << "Enter action: ";
		int action;
		std::cin >> action;

		if (action == 1) {
			list.map(my_map);
			print_list(list);
			std::cout << "\n";
		}
		else if (action == 2) {
			List<T> result = list.where(my_where);
			print_list(result);
			std::cout << "\n";
		}
		else if (action == 3) {
			std::cout << "Enter size of appending list: ";
			int size;
			List<T> my_list;
			std::cin >> size;
			read_list(&my_list, size);
			list.append(&my_list);
			print_list(list);
			std::cout << "\n";
		}
		else if (action == 4) {
			std::cout << "Enter start and end points:\nStart point ";
			int start, end;
			std::cin >> start;
			std::cout << "End ";
			std::cin >> end;
			List<T> result;
			result = list.get_sub_list(start, end);
			print_list(result);
			std::cout << "\n";
		}
		else if (action == 5) {
			std::cout << "Enter size of finding list: ";
			int size;
			List<T> my_list;
			std::cin >> size;
			read_list(&my_list, size);
			std::cout << "Result: ";
			if (list.find_sublist(my_list)) {
				std::cout << "true";
			}
			else {
				std::cout << "false";
			}
			std::cout << std::endl;
		}
		else if (action == 6) {
			std::cout << "Enter size of appending list: ";
			int size;
			List<T> my_list, result;
			std::cin >> size;
			read_list(&my_list, size);
			result = list.list_union(my_list);
			print_list(result);
			std::cout << "\n";
		}
		else if (action == 7) {
			list.dvide(my_dvide);
			std::cout << "\n";
		}
		else if (action == 8) {
			print_list(list);
			std::cout << "\n";
		}
		else if (action == 9){
			break;
		}
		else {
			std::cout << "Invalid action!!!\n";
		}
	}
}

int main()
{
	int type;
	
	std::cout << "Select type of list:\n1 - Real\n2 - Complex\n3 - String\n";
	std::cin >> type;

	if (type == 1) {
		int a = 0;
		loop(a);
	}
	else if (type == 2) {
		complex a;
		a.image = 0;
		a.real = 0;
		loop(a);
	}
	else if (type == 3) {
		std::string a = "";
		loop(a);
	}
	else {
		std::cout << "Incorrect type!!!\n" << std::endl;
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
