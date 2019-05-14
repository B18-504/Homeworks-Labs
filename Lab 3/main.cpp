#include "UI.hpp"

bool typeChoice(string type) {
    if ((type == "int") + (type == "string") + (type == "double")) {
        return false;
    }
    else {
        return true;
    }
}

int main(int argc, const char * argv[]) {
    string type;
    cout << "Type: ";
    cin >> type;
    while (typeChoice(type)) {
        cout << "Wrong choice!" << endl;
        cout << "Type: ";
        cin >> type;
    }
    
    if (type == "int") {
        Tree<int> tree;
        intUI(tree);
        tree.deleteTree();
    }
    else if (type == "double") {
        Tree<double> tree;
        doubleUI(tree);
        tree.deleteTree();
    }
    else if (type == "string") {
        Tree<string> tree;
        stringUI(tree);
        tree.deleteTree();
    }
    
    return 0;
}
