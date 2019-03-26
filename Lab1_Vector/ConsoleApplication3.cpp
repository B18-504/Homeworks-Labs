// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdio.h>
#include <malloc.h>

struct item {
	float Real = 0;
	float Image = 0;
	bool isComplex;
};

struct vector {
	char type;
	int size;
	int reserved;
	void *endPoint;
	size_t e_size;
};

item sum_item(item i1, item i2) {
	item result;
	result.Image = i1.Image + i2.Image;
	result.Real = i1.Real + i2.Real;
	return result;
}

item mult_item(item i1, item i2) {
	item result;
	result.Real = i1.Real * i2.Real - i1.Image * i2.Image;
	result.Image = i1.Real * i2.Image + i2.Real * i1.Image;
	return result;
}

vector createVector(char type) {
	vector newVector;
	if (type == 'i') {
		newVector.type = 'i';
		newVector.e_size = sizeof(item);
		newVector.reserved = 3;
		newVector.size = 0;
		newVector.endPoint = malloc(newVector.e_size * newVector.reserved);
		return newVector;
	}
	if (type == 'v') {
		newVector.type = 'v';
		newVector.e_size = sizeof(vector);
		newVector.reserved = 3;
		newVector.size = 0;
		newVector.endPoint = malloc(newVector.e_size * newVector.reserved);
		return newVector;
	}
	//Можно брость ошибку
}

vector push_ref(vector v, vector Item) {
	vector *point = (vector*)v.endPoint;
	*point = Item;
	point++;
	v.endPoint = (void*)point;
	v.size++;
	if (v.size == v.reserved) {
		void* startPoint = (void*)((vector*)v.endPoint - v.size);
		point = (vector*)realloc(startPoint, v.e_size * ((3 * v.reserved) / 2));
		v.reserved = (3 * v.reserved) / 2;
		v.endPoint = (void*)(point + v.size);
	}
	return v;
}

vector push_item(vector v, item Item) {
	item *point = (item*)v.endPoint;
	*point = Item;
	point++;
	v.endPoint = (void*)point;
	v.size++;
	if (v.size == v.reserved) {
		void* startPoint = (void*)((item*)v.endPoint - v.size);
		point = (item*)realloc(startPoint, v.e_size * ((3 * v.reserved)/2));
		v.reserved = (3 * v.reserved) / 2;
		v.endPoint = (void*)(point + v.size);
	}
	return v;
}

void* top(vector v) {
	return (void*)(((char*)v.endPoint)-v.e_size);
}

vector pop(vector v) {
	if (v.type == 'i') {
		item *local = (item*)v.endPoint;
		local--;
		v.endPoint = (void*)local;
		v.size--;
		v.reserved--;
	}
	if (v.type == 'v') {
		vector *local = (vector*)v.endPoint;
		local--;
		v.endPoint = (void*)local;
		v.size--;
		v.reserved--;
	}
	return v;
}

void* getItem(vector v, int index) {
	if (v.type == 'i') {
		return (void*)((item*)v.endPoint - v.size + index);
	}
	if (v.type == 'v') {
		return (void*)((vector*)v.endPoint - v.size + index);
	}
}

bool validate(vector v1, vector v2) {
	if (v1.type != v2.type) return false;
	if (v1.size != v2.size) return false;
	if (v1.type == 'v') {
		for (int i = 0; i < v1.size; i++) {
			if (validate(*(vector*)getItem(v1, i), *(vector*)getItem(v2, i)) == false) return false;
		}
	}
	return true;
}

vector vectorSum(vector v1, vector v2) {
	if (v1.type == 'v') {
		vector result = createVector('v');
		for (int i = 0; i < v1.size; i++) {
			result = push_ref(result, vectorSum(*(vector*)getItem(v1, i), *(vector*)getItem(v2, i)));
		}
		return result;
	}
	else {
		vector result = createVector('i');
		for (int i = 0; i < v1.size; i++) {
			item Item = sum_item(*(item*)getItem(v1, i), *(item*)getItem(v2, i));
			result = push_item(result, Item);
		}
		return result;
	}
}

item scalarMultiply(vector v1, vector v2) {
	if (v1.type == 'v') {
		item result;
		for (int i = 0; i < v1.size; i++) {
			result = sum_item(result, scalarMultiply(*(vector*)getItem(v1, i), *(vector*)getItem(v2, i)));
		}
		return result;
	}
	else {
		item result;
		for (int i = 0; i < v1.size; i++) {
			item Item = mult_item(*(item*)getItem(v1, i), *(item*)getItem(v2, i));
			result = sum_item(result, Item);
		}
		return result;
	}
}

vector vectorMultiply(vector v1, vector v2) {
	if (v1.type == 'v') {
		vector result = createVector('v');
		for (int i = 0; i < v1.size; i++) {
			result = push_ref(result, vectorMultiply(*(vector*)getItem(v1, i), *(vector*)getItem(v2, i)));
		}
		return result;
	}
	else {
		if (v1.size != 3) {
			printf("Bad vectors\n");
		}
		vector result = createVector('i');
		item ax = *(item*)getItem(v1, 0), ay = *(item*)getItem(v1, 1), az = *(item*)getItem(v1, 2);
		item bx = *(item*)getItem(v2, 0), by = *(item*)getItem(v2, 1), bz = *(item*)getItem(v2, 2);
		item x1 = mult_item(ay, bz), x2 = mult_item(az, by);
		item y1 = mult_item(az, bx), y2 = mult_item(ax, bz);
		item z1 = mult_item(ax, by), z2 = mult_item(bx, ay);
		x2.Real = (-1)*x2.Real; x2.Image = (-1)*x2.Image;
		y2.Real = (-1)*y2.Real; y2.Image = (-1)*y2.Image;
		z2.Real = (-1)*z2.Real; z2.Image = (-1)*z2.Image;
		result = push_item(result, sum_item(x1, x2));
		result = push_item(result, sum_item(y1, y2));
		result = push_item(result, sum_item(z1, z2));
		return result;
	}
}

void printVector(vector v, char outputType) {
	if (v.type == 'v') {
		for (int i = 0; i < v.size; i++) {
			printVector(*(vector*)getItem(v, i), outputType);
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < v.size; i++) {
			if (outputType == 'c') {
				printf("%f+(%fi) ", ((item*)getItem(v, i))->Real, ((item*)getItem(v, i))->Image);
			}
			else if (outputType == 'r') {
				printf("%f ", ((item*)getItem(v, i))->Real);
			}
			else {
				printf("Invalid output method!\n");
				return;
			}
		}
		printf("\n");
	}
}

vector readVector(int I, int J, int K, char inputType) {
	vector V = createVector('v');
	for (int i = 0; i < I; i++) {
		vector V1 = createVector('v');
		for (int j = 0; j < J; j++) {
			vector V2 = createVector('i');
			for (int k = 0; k < K; k++) {
				item Item;
				if (inputType == 'c') {
					scanf_s("%f+(%fi)", &Item.Real, &Item.Image);
				}
				else if (inputType == 'r'){
					scanf_s("%f", &Item.Real);
				}
				else {
					printf("Invalid input method!!!\n");
					return V2;
				}
				V2 = push_item(V2, Item);
			}
			V1 = push_ref(V1, V2);
		}
		V = push_ref(V, V1);
	}
	return V;
}

int main()
{
		char inputType, outputType;
		int I, J, K;
		printf("Select input/output method:\nr - Real\nc - Complex(Input/output format 'Real+(Image)')\nInput: ");
		scanf_s("%c", &inputType);
		outputType = inputType;
		printf("Input 1st vector parametrs:\n");
		scanf_s("%d%d%d", &I, &J, &K);
		printf("Input 1st vector:\n");
		vector V1 = readVector(I, J, K, inputType);
		printf("\n");
		printf("Input 2nd vector parametrs:\n");
		scanf_s("%d%d%d", &I, &J, &K);
		printf("Input 2nd vector:\n");
		vector V2 = readVector(I, J, K, inputType);
		printf("\n");
		while (true) {
			int action;
			printf("Select action:\n1 - Calculate the sum of vectors\n2 - Calculate the scalar multiplication of vectors\n3 - Calculate Vector multiplication of vectors(Expected view vector {I, J, 3})\n0 - Exit");
			printf("\nInput: ");
			scanf_s("%d", &action);
			if (!action) {
				return 0;
			}
			else if (action == 1) {
				if (validate(V1, V2)) {
					vector V = vectorSum(V1, V2);
					printf("Result:\n");
					printVector(V, outputType);
				}
				else {
					printf("Invalid vectors\n\n");
				}
			}
			else if (action == 2) {
				if (validate(V1, V2)) {
					item Item = scalarMultiply(V1, V2);
					printf("Result: ");
					if (outputType == 'r') {
						printf("%f\n", Item.Real);
					}
					else if (outputType == 'c') {
						printf("%f+(%fi)\n", Item.Real, Item.Image);
					}
					else {
						printf("Invalid output method\n");
					}
					printf("\n");
				}
				else {
					printf("Invalid vectors\n\n");
				}
			}
			else if (action == 3) {
				if (validate(V1, V2) && ((vector*)top((*(vector*)top(V1))))->size == 3) {
					vector V = vectorMultiply(V1, V2);
					printf("Result:\n");
					printVector(V, outputType);
				}
				else {
					printf("Invalid vectors\n\n");
				}
			}
			else {
				printf("Invalid action\n\n");
			}
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
