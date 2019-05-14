#ifndef UI_hpp
#define UI_hpp
#include "classes.hpp"
#include <random>

void choicer(int n1, int n2, int &c) {
    cout << "Your choice: ";
    cin >> c;
    while ((c < n1) + (c > n2)) {
        cout << "Wrong choice!" << endl;
        cout << "Your choice: ";
        cin >> c;
    }
}

double randDouble(double n1, double n2) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(n1, n2);
    return dist(mt);
}

int randInt(int n1, int n2) {
    return round(randDouble(n1, n2));
}

string randString(int n1, int n2) {
    int N = randInt(n1, n2);
    string buf = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    for (int i = 0; i < N; i++) {
        result += buf[randInt(0, sizeof(buf) - 1)];
    }
    return result;
}

void intUI(Tree<int> tree) {
    int data;
    int N, c = 1;
    
    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);
        
        if (c == 1) {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);
            
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            
            if (c == 1) {
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.push(data);
                }
            }
            else if (c == 2) {
                for (int i = 0; i < N; i++) {
                    tree.push(randInt(-100, 100));
                }
            }
            
            c = 1;
        }
        else if (c == 2) {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Root - Left - Right" << endl;
            choicer(1, 2, c);
            
            cout << "Your tree:" << endl;
            if (c == 1) {
                tree.printPLK();
            }
            else if (c == 2) {
                tree.printKLP();
            }
            getchar();
            getchar();
            
            c = 2;
        }
        else if (c == 3) {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<int> var;
            var.getSubTree(tree, data);
            cout << "Your subtree:" << endl;
            var.printPLK();
            var.deleteTree();
            getchar();
            getchar();
        }
        else if (c == 4) {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);
            
            if (c == 1) {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
            }
            else if (c == 2) {
                Tree<int> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.push(data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
            }
            getchar();
            getchar();
            c = 4;
        }
        else if (c == 5) {
            cout << "1. +1" << endl;
            cout << "2. -10" << endl;
            choicer(1, 2, c);
            if (c == 1) {
                tree.map(intPlusOne);
            }
            else if (c == 2) {
                tree.map(intMinusTen);
            }
            c = 5;
        }
        else if (c == 6) {
            cout << "1. Check even elements" << endl;
            cout << "2. Check odd elements" << endl;
            choicer(1, 2, c);
            
            cout << "Result:" << endl;
            if (c == 1) {
                tree.where(intIfEven);
            }
            else if (c == 2) {
                tree.where(intIfOdd);
            }
            cout << endl;
            getchar();
            getchar();
            c = 6;
        }
        else if (c == 7) {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
        }
        else if (c == 8) {
            cout << "Creating new tree to merge" << endl;
            Tree<int> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push(data);
            }
            tree.addTree(var);
            var.deleteTree();
        }
        cout << endl;
    }
    tree.deleteTree();
}

void doubleUI(Tree<double> tree) {
    double data;
    int N, c = 1;
    
    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);
        
        if (c == 1) {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);
            
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            
            if (c == 1) {
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.push(data);
                }
            }
            else if (c == 2) {
                for (int i = 0; i < N; i++) {
                    tree.push(randDouble(-100, 100));
                }
            }
            
            c = 1;
        }
        else if (c == 2) {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Root - Left - Right" << endl;
            choicer(1, 2, c);
            
            cout << "Your tree:" << endl;
            
            if (c == 1) {
                tree.printPLK();
            }
            else if (c == 2) {
                tree.printKLP();
            }
            getchar();
            getchar();
            c = 2;
        }
        else if (c == 3) {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<double> var;
            var.getSubTree(tree, data);
            cout << "Your subtree:" << endl;
            var.printPLK();
            var.deleteTree();
            getchar();
            getchar();
        }
        else if (c == 4) {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);
            
            if (c == 1) {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
            }
            else if (c == 2) {
                Tree<double> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.push(data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
            }
            getchar();
            getchar();
            c = 4;
        }
        else if (c == 5) {
            cout << "1. +1" << endl;
            cout << "2. -10" << endl;
            choicer(1, 2, c);
            if (c == 1) {
                tree.map(doublePlusOne);
            }
            else if (c == 2) {
                tree.map(doubleMinusTen);
            }
            c = 5;
        }
        else if (c == 6) {
            cout << "1. > 10" << endl;
            cout << "2. < 0" << endl;
            choicer(1, 2, c);
            
            cout << "Result:" << endl;
            if (c == 1) {
                tree.where(doubleIfLargerThanTen);
            }
            else if (c == 2) {
                tree.where(doubleIfLesserThanZero);
            }
            getchar();
            getchar();
            cout << endl;
            c = 6;
        }
        else if (c == 7) {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
        }
        else if (c == 8) {
            cout << "Creating new tree to merge" << endl;
            Tree<double> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push(data);
            }
            tree.addTree(var);
            var.deleteTree();
        }
        cout << endl;
    }
    tree.deleteTree();
}

void stringUI(Tree<string> tree) {
    string data;
    int N, c = 1;
    
    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);
        
        if (c == 1) {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);
            
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            
            if (c == 1) {
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.push(data);
                }
            }
            else if (c == 2) {
                for (int i = 0; i < N; i++) {
                    tree.push(randString(4, 10));
                }
            }
            
            c = 1;
        }
        else if (c == 2) {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Root - Left - Right" << endl;
            choicer(1, 2, c);
            
            cout << "Your tree:" << endl;
            
            if (c == 1) {
                tree.printPLK();
            }
            else if (c == 2) {
                tree.printKLP();
            }
            getchar();
            getchar();
            
            c = 2;
        }
        else if (c == 3) {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<string> var;
            var.getSubTree(tree, data);
            cout << "Your subtree:" << endl;
            var.printPLK();
            var.deleteTree();
            getchar();
            getchar();
        }
        else if (c == 4) {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);
            
            if (c == 1) {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
            }
            else if (c == 2) {
                Tree<string> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.push(data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
            }
            getchar();
            getchar();
            c = 4;
        }
        else if (c == 5) {
            cout << "1. Change register" << endl;
            cout << "2. Make string less" << endl;
            choicer(1, 2, c);
            if (c == 1) {
                tree.map(stringChangeRegister);
            }
            else if (c == 2) {
                tree.map(stringMakeLess);
            }
            c = 5;
        }
        else if (c == 6) {
            cout << "1. Size of string >= 8" << endl;
            cout << "2. Size of string < 6" << endl;
            choicer(1, 2, c);
            
            cout << "Result:" << endl;
            if (c == 1) {
                tree.where(stringIfLargerThanEight);
            }
            else if (c == 2) {
                tree.where(stringIfLesserThanSix);
            }
            getchar();
            getchar();
            cout << endl;
            c = 6;
        }
        else if (c == 7) {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
        }
        else if (c == 8) {
            cout << "Creating new tree to merge" << endl;
            Tree<string> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push(data);
            }
            tree.addTree(var);
            var.deleteTree();
        }
        cout << endl;
    }
    tree.deleteTree();
}

#endif /* UI_hpp */
