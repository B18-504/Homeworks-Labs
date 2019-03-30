#ifndef UI_h
#define UI_h
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "classes.h"

bool int_choices(int c, List<int> *head) {
    if (head == nullptr) {
        if ((c < 0) + (c > 1)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if ((c < 0) + (c > 8)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
}

bool stud_choices(int c, List<Student> *head) {
    if (head == nullptr) {
        if ((c < 0) + (c > 1)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if ((c < 0) + (c > 8)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
}

bool func_choices(int c, List<Func> *head) {
    if (head == nullptr) {
        if ((c < 0) + (c > 2)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if ((c < 0) + (c > 6)) {
            cout << "!Wrong choice!" << endl;
            return false;
        }
        else {
            return true;
        }
    }
}

/*MAP ONES*/

//INTS

void int_plus_10(List<int> *tmp) {
    tmp->data += 10;
}

void int_minus_1(List<int> *tmp) {
    tmp->data -= 1;
}

//STUDENTS

void stud_change_register(List<Student> *tmp) {
    int i = 0;
    while (tmp->data.name[i] != '\0') {
        cout << isupper(tmp->data.name[i]);
        if (isupper(tmp->data.name[i])) {
            tmp->data.name[i] = tolower(tmp->data.name[i]);
        }
        else if (isupper(tmp->data.name[i]) == 0) {
            tmp->data.name[i] = toupper(tmp->data.name[i]);
        }
        i++;
    }
    i = 0;
    while (tmp->data.surn[i] != '\0') {
        if (isupper(tmp->data.surn[i])) {
            tmp->data.surn[i] = tolower(tmp->data.surn[i]);
        }
        else if (isupper(tmp->data.surn[i]) == 0) {
            tmp->data.surn[i] = toupper(tmp->data.surn[i]);
        }
        i++;
    }
    i = 0;
    while (tmp->data.patr[i] != '\0') {
        if (isupper(tmp->data.patr[i])) {
            tmp->data.patr[i] = tolower(tmp->data.patr[i]);
        }
        else if (isupper(tmp->data.patr[i]) == 0) {
            tmp->data.patr[i] = toupper(tmp->data.patr[i]);
        }
        i++;
    }
}

void stud_change_groups(List<Student> *tmp) {
    if (tmp->data.group[0] == 'b') {
        cout << "yeah ye ye" << endl;
        tmp->data.group[0] = 's';
    }
    else if (tmp->data.group[0] == 'B') {
        tmp->data.group[0] = 'S';
    }
}

/*WHERE ONES*/

//INTS

bool int_if_even(List<int> *tmp) {
    if (tmp->data % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool int_if_odd(List<int> *tmp) {
    if (tmp->data % 2 == 0) {
        return false;
    }
    else {
        return true;
    }
}

//STUDENTS

bool student_if_b18504(List<Student> *tmp) {
    if ((tmp->data.group == "b18-504") + (tmp->data.group == "B18-504")) {
        return true;
    }
    else {
        return false;
    }
}

bool student_if_not_b18504(List<Student> *tmp) {
    if ((tmp->data.group == "b18-504") + (tmp->data.group == "B18-504")) {
        return false;
    }
    else {
        return true;
    }
}

/*REDUCE ONES*/

//INTS

int int_sum(List<int> *tmp, const int c) {
    return 2*tmp->data + 3*c;
}

int int_generic(List<int> *tmp, const int c) {
    return 2*tmp->data*c;
}

//STUDENTS

int student_sum(List<Student> *tmp, const int c) {
    return (int)tmp->data.name.length() + 2*(int)tmp->data.surn.length() + 3*(int)tmp->data.patr.length() + 4*c;
}

int student_generic(List<Student> *tmp, const int c) {
    return (int)tmp->data.name.length()*(int)tmp->data.surn.length()*(int)tmp->data.patr.length()*c;
}

void int_UI() {
    srand((unsigned)time(NULL));
    int c = 0, N = 0, Nb = 0;
    List<int> *head = nullptr, *tmp = nullptr, *bonus = nullptr;
    while (1) {
        cout << "Menu: " << endl;
        if (head == nullptr) {
            cout << "1. Create list" << endl;
            cout << "0. Exit" << endl;
        }
        else {
            cout << "1. Recreate list" << endl;
            cout << "2. Print list" << endl;
            cout << "3. Sort list" << endl;
            cout << "4. Map" << endl;
            cout << "5. Where" << endl;
            cout << "6. Reduce" << endl;
            cout << "7. Print subsequence" << endl;
            if (bonus == nullptr) {
                cout << "8. Create another list" << endl;
            }
            else {
                cout << "8. Merge lists and print result" << endl;
            }
            cout << "0. Exit" << endl;
        }
        cout << "Choose wisely: ";
        cin >> c;
        while(not int_choices(c, head)) {
            cout << "Choose wisely: ";
            cin >> c;
        }
        
        if (c == 1) {
            head = clear_memory(head);
            cout << "Manual/Automatic? (1/0): ";
            cin >> c;
            while ((c > 1) + (c < 0)) {
                cout << "!Wrong choice!" << endl;
                cout << "Manual/Automatic? (1/0): ";
                cin >> c;
            }
            if (c == 1) {
                head = clear_memory(head);
                int data;
                cout << "N: ";
                cin >> N;
                while (N < 1) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Enter data in line order: ";
                cin >> data;
                tmp = list_create_head(tmp, data);
                head = tmp;
                for (int i = 0; i < N-1; i++) {
                    cin >> data;
                    tmp = list_create_continue(tmp, data);
                }
            }
            else if (c == 0) {
                head = clear_memory(head);
                int data;
                cout << "N: ";
                cin >> N;
                while (N < 1) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                data = rand() % (100-(-100)) - 100;
                tmp = list_create_head(tmp, data);
                head = tmp;
                for (int i = 0; i < N-1; i++) {
                    data = rand() % (100-(-100)) - 100;
                    tmp = list_create_continue(tmp, data);
                }
            }
            c = 1;
        }
        
        if (c == 2) {
            cout << "Your list: " << endl;
            tmp = head;
            while (tmp != nullptr) {
                tmp->int_print();
                tmp = tmp->next;
            }
            getchar();
            getchar();
        }
        
        if (c == 3) {
            tmp = head;
            for (int i = 0; i < N-1; i++) {
                tmp = head;
                for (int j = 0; j < N-i-1; j++) {
                    if (tmp->data > tmp->next->data) {
                        List<int> *swap = new List<int>;
                        swap->data = tmp->data;
                        tmp->data = tmp->next->data;
                        tmp->next->data = swap->data;
                        free(swap);
                    }
                    tmp = tmp->next;
                }
            }
            cout << "Sorted!" << endl;
        }
        
        if (c == 4) {
            cout << "List of map functions: " << endl;
            cout << "1. Number + 10" << endl;
            cout << "2. Number - 1" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                head = list_map(head, int_plus_10);
            }
            else if (c == 2) {
                head = list_map(head, int_minus_1);
            }
            c = 4;
        }
        
        if (c == 5) {
            cout << "List of where functions: " << endl;
            cout << "1. Delete even numbers" << endl;
            cout << "2. Delete odd numbers" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                head = list_where(head, int_if_odd, N);
            }
            else if (c == 2) {
                head = list_where(head, int_if_even, N);
            }
            c = 5;
        }
        
        if (c == 6) {
            cout << "List of reduce functions: " << endl;
            cout << "1. F(x,y) = 2*x + 3*y" << endl;
            cout << "2. F(x,y) = 2*x*y" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                cout << "Starting constant: ";
                cin >> c;
                cout << "Reduce value: ";
                cout << list_reduce(head, int_sum, c, N) << endl;
            }
            else if (c == 2) {
                cout << "Starting constant: ";
                cin >> c;
                cout << "Reduce value: ";
                cout << list_reduce(head, int_generic, c, N) << endl;
            }
            c = 6;
            getchar();
            getchar();
        }
        
        if (c == 7) {
            List<int> *mem = nullptr;
            int i1 = 0, i2 = 0;
            cout << "Enter indexes from 1 to N" << endl;
            cout << "Choice: ";
            cin >> i1;
            cin >> i2;
            while ((i1 < 1) + (i2 > N) + (i1 > i2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            mem = list_get_subsequence(head, i1, i2);
            tmp = mem;
            while (tmp != nullptr) {
                tmp->int_print();
                tmp = tmp->next;
            }
            free(mem);
            getchar();
            getchar();
        }
        
        if ((c == 8) * (bonus == nullptr)) {
            cout << "Manual/Automatic? (1/0): ";
            cin >> c;
            while ((c > 1) + (c < 0)) {
                cout << "!Wrong choice!" << endl;
                cout << "Manual/Automatic? (1/0): ";
                cin >> c;
            }
            if (c == 1) {
                int data;
                cout << "N: ";
                cin >> Nb;
                cout << "Enter data in line order: ";
                cin >> data;
                tmp = list_create_head(tmp, data);
                bonus = tmp;
                for (int i = 0; i < Nb-1; i++) {
                    cin >> data;
                    tmp = list_create_continue(tmp, data);
                }
            }
            else if (c == 0) {
                int data;
                cout << "N: ";
                cin >> Nb;
                while (Nb < 1) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> Nb;
                }
                data = rand() % (100-(-100)) - 100;
                tmp = list_create_head(tmp, data);
                bonus = tmp;
                for (int i = 0; i < Nb-1; i++) {
                    data = rand() % (100-(-100)) - 100;
                    tmp = list_create_continue(tmp, data);
                }
            }
            c = 8;
        }
        else if ((c == 8) * (bonus != nullptr)) {
            List<int> *mem = nullptr;
            mem = *head + *bonus;
            clear_memory(bonus);
            bonus = nullptr;
            cout << "Result of merging: " << endl;
            tmp = mem;
            while (tmp != nullptr) {
                tmp->int_print();
                tmp = tmp->next;
            }
            clear_memory(mem);
            getchar();
            getchar();
        }
        
        if (c == 0) {
            head = clear_memory(head);
            cout << "Bye!" << endl;
            exit(0);
        }
    }
}

void stud_UI() {
    int c = 0, N = 0, Nb = 0;
    List<Student> *head = nullptr, *tmp = nullptr, *bonus = nullptr;
    while (1) {
        cout << "Menu: " << endl;
        if (head == nullptr) {
            cout << "1. Create list" << endl;
            cout << "0. Exit" << endl;
        }
        else {
            cout << "1. Recreate list" << endl;
            cout << "2. Print list" << endl;
            cout << "3. Sort list" << endl;
            cout << "4. Map" << endl;
            cout << "5. Where" << endl;
            cout << "6. Reduce" << endl;
            cout << "7. Print subsequence" << endl;
            if (bonus == nullptr) {
                cout << "8. Create another list" << endl;
            }
            else if (bonus != nullptr) {
                cout << "8. Merge lists" << endl;
            }
            cout << "0. Exit" << endl;
        }
        cout << "Choose wisely: ";
        cin >> c;
        while(not stud_choices(c, head)) {
            cout << "Choose wisely: ";
            cin >> c;
        }
        
        if (c == 1) {
            head = clear_memory(head);
            Student data;
            cout << "Manual/From base? (1/0): ";
            cin >> c;
            if (c == 1) {
                cout << "N: ";
                cin >> N;
                while (N < 1) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                while (N < 1) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Enter data: ";
                cin >> data.surn >> data.name >> data.patr >> data.group;
                tmp = list_create_head(tmp, data);
                head = tmp;
                for (int i = 0; i < N-1; i++) {
                    cout << "Enter data: ";
                    cin >> data.surn >> data.name >> data.patr >> data.group;
                    tmp = list_create_continue(tmp, data);
                }
            }
            else if (c == 0) {
                cout << "N (Nmax = 41): ";
                cin >> N;
                while ((N > 41) + (N < 1)) {
                    cout << "!Wrong choice!" << endl;
                    cout << "N (Nmax = 41): ";
                    cin >> N;
                }
                ifstream file("/Users/levmarder/Documents/Прога/Studying(lab 2)/Studying(lab 2)/students.txt");
                string memoria;
                getline(file, memoria);
                data.transform(memoria);
                tmp = list_create_head(tmp, data);
                head = tmp;
                for (int i = 0; i < N-1; i++) {
                    getline(file, memoria);
                    data.transform(memoria);
                    tmp = list_create_continue(tmp, data);
                }
                file.close();
            }
            c = 1;
        }
        
        if (c == 2) {
            cout << "Your list: " << endl;
            tmp = head;
            while (tmp != nullptr) {
                tmp->data.student_print();
                tmp = tmp->next;
            }
            getchar();
            getchar();
        }
        
        if (c == 3) {
            tmp = head;
            for (int i = 0; i < N-1; i++) {
                tmp = head;
                for (int j = 0; j < N-i-1; j++) {
                    if (tmp->data.surn > tmp->next->data.surn) {
                        List<Student> *swap = new List<Student>;
                        swap->data = tmp->data;
                        tmp->data = tmp->next->data;
                        tmp->next->data = swap->data;
                        free(swap);
                    }
                    tmp = tmp->next;
                }
            }
            cout << "Sorted!" << endl;
        }
        
        if (c == 4) {
            cout << "List of map functions: " << endl;
            cout << "1. Change register" << endl;
            cout << "2. Change groups to specialist or bachelor" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                head = list_map(head, stud_change_register);
            }
            else if (c == 2) {
                head = list_map(head, stud_change_groups);
            }
            c = 4;
        }
        
        if (c == 5) {
            cout << "List of where functions: " << endl;
            cout << "1. Delete students from other than B18-504 group" << endl;
            cout << "2. Delete students from B18-504 group" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                head = list_where(head, student_if_b18504, N);
            }
            else if (c == 2) {
                head = list_where(head, student_if_not_b18504, N);
            }
            c = 5;
        }
        
        if (c == 6) {
            cout << "A = length of surname, B = length of name, C = length of patronage, D = const" << endl;
            cout << "List of reduce functions: " << endl;
            cout << "1. F(A,B,C,D) = A + 2*B + 3*C + 4*D" << endl;
            cout << "2. F(A,B,C,D) = A*B*C*D" << endl;
            cout << "Choice: ";
            cin >> c;
            while ((c < 0) + (c > 2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            if (c == 1) {
                cout << "Starting constant: ";
                cin >> c;
                cout << "Reduce value: ";
                cout << list_reduce(head, student_sum, c, N) << endl;
            }
            else if (c == 2) {
                cout << "Starting constant: ";
                cin >> c;
                cout << "Reduce value: ";
                cout << list_reduce(head, student_generic, c, N) << endl;
            }
            c = 6;
            getchar();
            getchar();
        }
        
        if (c == 7) {
            List<Student> *mem = nullptr;
            int i1 = 0, i2 = 0;
            cout << "Enter indexes from 1 to N" << endl;
            cout << "Choice: ";
            cin >> i1;
            cin >> i2;
            while ((i1 < 1) + (i2 > N) + (i1 > i2)) {
                cout << "!Wrong choice!" << endl;
                cout << "Choice: ";
                cin >> c;
            }
            mem = list_get_subsequence(head, i1, i2);
            tmp = mem;
            while (tmp != nullptr) {
                tmp->data.student_print();
                tmp = tmp->next;
            }
            free(mem);
            getchar();
            getchar();
        }
        
        if ((c == 8) * (bonus == nullptr)) {
            Student data;
            cout << "N: ";
            cin >> Nb;
            while (Nb < 1) {
                cout << "!Wrong choice!" << endl;
                cout << "N: ";
                cin >> Nb;
            }
            cout << "Enter data: ";
            cin >> data.surn >> data.name >> data.patr >> data.group;
            tmp = list_create_head(tmp, data);
            bonus = tmp;
            for (int i = 0; i < Nb-1; i++) {
                cout << "Enter data: ";
                cin >> data.surn >> data.name >> data.patr >> data.group;
                tmp = list_create_continue(tmp, data);
            }
        }
        else if ((c == 8) * (bonus != nullptr)) {
            List<Student> *mem = nullptr;
            mem = *head + *bonus;
            clear_memory(bonus);
            bonus = nullptr;
            cout << "Result of merging: " << endl;
            tmp = mem;
            while (tmp != nullptr) {
                tmp->data.student_print();
                tmp = tmp->next;
            }
            clear_memory(mem);
            getchar();
            getchar();
        }
        
        if (c == 0) {
            head = clear_memory(head);
            cout << "Bye!" << endl;
            exit(0);
        }
    }
}

void func_UI() {
    srand((unsigned)time(NULL));
    int c = 0, N = 0;
    List<Func> *head = nullptr, *tmp = nullptr;
    while (1) {
        cout << "Menu: " << endl;
        if (head == nullptr) {
            cout << "1. Create list" << endl;
            cout << "0. Exit" << endl;
        }
        else {
            cout << "1. Recreate list" << endl;
            cout << "2. Evaluate functions" << endl;
            cout << "0. Exit" << endl;
        }
        cout << "Choose wisely: ";
        cin >> c;
        while(not func_choices(c, head)) {
            cout << "Choose wisely: ";
            cin >> c;
        }
        
        if (c == 1) {
            head = clear_memory(head);
            Func f;
            int ci;
            cout << "Manual/Automatic? (1/0): ";
            cin >> ci;
            while ((ci > 1) + (ci < 0)) {
                cout << "!Wrong choice!" << endl;
                cout << "Manual/Automatic? (1/0): ";
                cin >> ci;
            }
            cout << "N: ";
            cin >> N;
            while (N < 1) {
                cout << "!Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            for (int i = 0; i < N; i++) {
                if (ci == 1) {
                    cout << "List of functions to add to List:" << endl;
                    cout << "1. Print \"Hello World!\"" << endl;
                    cout << "2. Print PI" << endl;
                    cout << "Choose wisely: ";
                    cin >> c;
                }
                else if (ci == 0) {
                    c = rand() % 2 + 1;
                    cout << c << endl;
                }
                if (head == nullptr) {
                    if (c == 1) {
                        f.func_set(print_hello);
                        tmp = list_create_head(tmp, f);
                    }
                    else if (c == 2) {
                        f.func_set(print_pi);
                        tmp = list_create_head(tmp, f);
                    }
                    head = tmp;
                }
                else {
                    if (c == 1) {
                        f.func_set(print_hello);
                        tmp = list_create_continue(tmp, f);
                    }
                    else if (c == 2) {
                        f.func_set(print_pi);
                        tmp = list_create_continue(tmp, f);
                    }
                }
            }
            c = 1;
        }
        
        if (c == 2) {
            tmp = head;
            cout << "Evaluating functions in list:" << endl;
            while (tmp != nullptr) {
                tmp->data.fk();
                tmp = tmp->next;
            }
            getchar();
            getchar();
        }
        
        if (c == 0) {
            head = clear_memory(head);
            cout << "Bye!" << endl;
            exit(0);
        }
    }
}


#endif
