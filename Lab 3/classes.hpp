#ifndef classes_hpp
#define classes_hpp
#include <iostream>
using namespace std;

template <typename T> //Node class
class Node {
private:
    T data;
    Node<T> *left, *right;
    
    Node() {
        left = right = nullptr;
    };
public:
    T getData() {
        return data;
    }
    void changeData(T newData);
    void push(Node<T> *&root, T data);
    void printPLK(Node<T> *&root);
    void printKLP(Node<T> *&root);
    void cleanMemory(Node<T> *&root);
    void deleteNode(Node<T> *&root, T key);
    Node<T>* getSubTree(Node<T> *&root, T key);
    void assembleTree(Node<T> *&var, Node<T> *root, T Key);
    void copyNode(Node<T> *&target, Node<T> *root);
    void setStringPLK(Node<T> *&root, string &buff);
    void setStringKLP(Node<T> *&root, string &buff);
    void checkPresence(Node<T> *root, T key, bool &check);
    void compareNodes(Node<T> *root1, Node<T> *root2, bool &check);
    void checkNodePresence(Node<T> *root1, Node<T> *root2, bool &check);
    void addNode(Node<T> *&target, Node<T> *root);
    void map(Node<T> *&root, void (*f)(Node<T> *&root));
    void where(Node<T> *root, bool (*f)(Node<T> *root));
};

//изменение данных в ноде
template <typename T>
void Node<T>::changeData(T newData) {
    data = newData;
}

//вставка элемента в дерево
template <typename T>
void Node<T>::push(Node<T> *&root, T data) {
    //если нода пустая
    if (root == nullptr) {
        root = new Node<T>;
        root->data = data;
        root->left = root->right = nullptr;
    }
    //если в ноде есть значения
    else if (data > root->data) {
        root->push(root->right, data);
    }
    else {
        root->push(root->left, data);
    }
}

//распечатывание дерева в консоль обходом ПЛК
template <typename T>
void Node<T>::printPLK(Node<T> *&root) {
    if (root != nullptr) {
        root->printPLK(root->right);
        root->printPLK(root->left);
        cout << root->data << " ";
    }
}

//распечатывание дерева в консоль обходом КЛП
template <typename T>
void Node<T>::printKLP(Node<T> *&root) {
    if (root != nullptr) {
        cout << root->data << " ";
        root->printKLP(root->left);
        root->printKLP(root->right);
    }
}

//копирование нод
template <typename T>
void Node<T>::copyNode(Node<T> *&target, Node<T> *root) {
    if (root != nullptr) {
        target = new Node<T>;
        target->data = root->data;
        target->left = target->right = nullptr;
        target->left->copyNode(target->left, root->left);
        target->right->copyNode(target->right, root->right);
    }
}

//получение строки в виде заданного обхода
template <typename T>
void Node<T>::setStringPLK(Node<T> *&root, string &buff) {
    if (root != nullptr) {
        root->getStringPLK(root->right, buff);
        root->getStringPLK(root->left, buff);
        buff += to_string(root->data) + " ";
    }
}

template <typename T>
void Node<T>::setStringKLP(Node<T> *&root, string &buff) {
    if (root != nullptr) {
        buff += to_string(root->data) + " ";
        root->getStringPLK(root->left, buff);
        root->getStringPLK(root->right, buff);
    }
}

//удаление поддерева
template <typename T>
void Node<T>::deleteNode(Node<T> *&root, T key) {
    if (root != nullptr) {
        if  (root->data == key) {
            root->cleanMemory(root);
        }
        else {
            root->right->deleteNode(root->right, key);
            root->left->deleteNode(root->left, key);
        }
    }
}

//очистка памяти
template <typename T>
void Node<T>::cleanMemory(Node<T> *&root) {
    if (root != nullptr) {
        root->right->cleanMemory(root->right);
        root->left->cleanMemory(root->left);
        delete root;
        root = nullptr;
    }
}

//получение поддерева
template <typename T>
Node<T>* Node<T>::getSubTree(Node<T> *&root, T key) {
    Node<T> *var = nullptr;
    var->assembleTree(var, root, key);
    return var;
}

//помощь в получении поддерева
template <typename T>
void Node<T>::assembleTree(Node<T> *&var, Node<T> *root, T key) {
    if (root != nullptr) {
        if (root->data == key) {
            var->copyNode(var, root);
        }
        else {
            var->assembleTree(var, root->right, key);
            var->assembleTree(var, root->left, key);
        }
    }
}

//проверка наличия элемента
template <typename T>
void Node<T>::checkPresence(Node<T> *root, T key, bool &check) {
    if (root != nullptr) {
        if (root->data == key) {
            check = true;
        }
        else {
            root->right->checkPresence(root->right, key, check);
            root->left->checkPresence(root->left, key, check);
        }
    }
}

//сравнение деревьев
template <typename T>
void Node<T>::compareNodes(Node<T> *root1, Node<T> *root2, bool &check) {
    if ((root1 != nullptr) * (root2 != nullptr)) {
        if (root1->data == root2->data) {
            check = true;
            root1->right->compareNodes(root1->right, root2->right, check);
            root1->left->compareNodes(root1->left, root2->left, check);
        }
        else {
            check = false;
        }
    }
}

//проверка наличия поддерева
template <typename T>
void Node<T>::checkNodePresence(Node<T> *root1, Node<T> *root2, bool &check) {
    if (root2 != nullptr) {
        if (root1->data == root2->data) {
            root1->compareNodes(root1, root2, check);
        }
        else {
            root2->right->checkNodePresence(root1, root2->right, check);
            root2->left->checkNodePresence(root1, root2->left, check);
        }
    }
}

//слияние деревьев
template <typename T>
void Node<T>::addNode(Node<T> *&target, Node<T> *root) {
    if (target == nullptr) {
        target->copyNode(target, root);
    }
    else if (root->data > target->data) {
        target->right->addNode(target->right, root);
    }
    else {
        target->left->addNode(target->left, root);
    }
}

//map
template <typename T>
void Node<T>::map(Node<T> *&root, void (*f)(Node<T> *&root)) {
    if (root != nullptr) {
        root->right->map(root->right, f);
        root->left->map(root->left, f);
        f(root);
    }
}

/*map functions*/

//int

void intPlusOne(Node<int> *&root) {
    root->changeData(root->getData() + 1);
}

void intMinusTen(Node<int> *&root) {
    root->changeData(root->getData() - 10);
}

//double

void doublePlusOne(Node<double> *&root) {
    root->changeData(root->getData() + 1);
}

void doubleMinusTen(Node<double> *&root) {
    root->changeData(root->getData() - 10);
}

//string

void stringChangeRegister(Node<string> *&root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        if (isupper(u[i])) {
            u[i] = tolower(u[i]);
        }
        else if (isupper(u[i]) == 0) {
            u[i] = toupper(u[i]);
        }
        i++;
    }
    root->changeData(u);
}

void stringMakeLess(Node<string> *&root) {
    string u = root->getData();
    u[sizeof(u) - 1] = '\0';
    root->changeData(u);
}

//where
template <typename T>
void Node<T>::where(Node<T> *root, bool (*f)(Node<T> *root)) {
    if (root != nullptr) {
        root->right->where(root->right, f);
        root->left->where(root->left, f);
        if (f(root)) {
            cout << root->data << " ";
        }
    }
}

/*Where functions*/

//int

bool intIfEven(Node<int> *root) {
    if (root->getData() % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool intIfOdd(Node<int> *root) {
    if (root->getData() % 2 != 0) {
        return true;
    }
    else {
        return false;
    }
}

//double

bool doubleIfLargerThanTen(Node<double> *root) {
    if (root->getData() > 10) {
        return true;
    }
    else {
        return false;
    }
}

bool doubleIfLesserThanZero(Node<double> *root) {
    if (root->getData() < 0) {
        return true;
    }
    else {
        return false;
    }
}

//string

bool stringIfLargerThanEight(Node<string> *root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        i++;
    }
    if (i + 1 >= 8) {
        return true;
    }
    else {
        return false;
    }
}

bool stringIfLesserThanSix(Node<string> *root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        i++;
    }
    if (i + 1 < 6) {
        return true;
    }
    else {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> //Tree class как оболочка над нодой
class Tree {
private:
    Node<T> *root;
public:
    Tree() { root = nullptr; };
    void push(T data);
    void addTree(Tree<T> tree);
    void printPLK();
    void printKLP();
    void map(void (*f)(Node<T> *&root));
    void where(bool (*f)(Node<T> *root));
    void deleteNode(T key);
    string getStringPLK();
    string getStringKLP();
    void deleteTree();
    Node<T>* getRoot();
    void getSubTree(Tree<T> tree, T key);
    bool checkPresence(T key);
    bool compareTrees(Tree<T> tree);
    bool checkPresence(Tree<T> tree);
};

//методы для деревьев
template <typename T>
void Tree<T>::push(T data) {
    root->push(root, data);
}

template <typename T>
void Tree<T>::addTree(Tree<T> tree) {
    root->addNode(root, tree.root);
}

template <typename T>
void Tree<T>::printPLK() {
    root->printPLK(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printKLP() {
    root->printKLP(root);
    cout << endl;
}

template <typename T>
Node<T>* Tree<T>::getRoot() {
    return root;
}

template <typename T>
void Tree<T>::map(void (*f)(Node<T> *&root)) {
    root->map(root, f);
}

template <typename T>
void Tree<T>::where(bool (*f)(Node<T> *root)) {
    root->where(root, f);
}

template <typename T>
void Tree<T>::deleteNode(T key) {
    root->deleteNode(root, key);
}

template <typename T>
string Tree<T>::getStringPLK() {
    string buff = "";
    root->setStringPLK(root, buff);
    return buff;
}

template <typename T>
string Tree<T>::getStringKLP() {
    string buff = "";
    root->setStringKLP(root, buff);
    return buff;
}

template <typename T>
void Tree<T>::getSubTree(Tree<T> tree, T key) {
    root = tree.root->getSubTree(tree.root, key);
}

template <typename T>
void Tree<T>::deleteTree() {
    root->cleanMemory(root);
}

template <typename T>
bool Tree<T>::checkPresence(T key) {
    bool check = false;
    root->checkPresence(root, key, check);
    return check;
}

template <typename T>
bool Tree<T>::compareTrees(Tree<T> tree) {
    bool check = false;
    root->compareNodes(root, tree.root, check);
    return check;
}

template <typename T>
bool Tree<T>::checkPresence(Tree<T> tree) {
    bool check = false;
    root->checkNodePresence(tree.root, root, check);
    return check;
}

#endif /* main_classes */
