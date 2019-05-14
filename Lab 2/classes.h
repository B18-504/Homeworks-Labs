#ifndef classes_h
#define classes_h
using namespace std;

class Student {
public:
    string surn;
    string name;
    string patr;
    string group;
    void set_student(string s, string n, string p, string g) {
        surn = s;
        name = n;
        patr = p;
        group = g;
    }
    string student_get() {
        return surn + " " + name + " " + patr + " " + group;
    }
    void student_print() {
        cout << surn << " " << name << " " << patr << " " << group << endl;
    }
    void transform(string str) {
        int i = 0, j = 0, count = 0;
        string buff = str;
        while (buff[i] != ' ') {
            i++;
            count++;
        }
        surn = buff.substr(0, count);
        j = i+1;
        count = 0;
        i++;
        while (buff[i] != ' ') {
            i++;
            count++;
        }
        name = buff.substr(j, count);
        j = i+1;
        count = 0;
        i++;
        while (buff[i] != ' ') {
            i++;
            count++;
        }
        patr = buff.substr(j, count);
        j = i+1;
        count = 0;
        i++;
        while (buff[i] != '\0') {
            i++;
            count++;
        }
        group = buff.substr(j, count);
    }
};

class Func {
public:
    void (*fk)();
    void func_set(void (*f)()) {
        fk = f;
    }
};

template <typename Type> class List {
public:
    Type data;
    List *next;
    void set_head(Type d) {
        data = d;
        next = nullptr;
    }
    void int_print() {
        cout << data << endl;
    }
};

bool choice_fucker(string c) {
    if ((c == "int") + (c == "student") + (c == "func")) {
        return true;
    }
    if (c == "0") {
        exit(0);
    }
    else {
        return false;
    }
}

void print_hello() {
    cout << "Hello, world!" << endl;
}

void print_pi() {
    cout << "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564..." << endl;
}

template <typename Type>
List<Type>* list_create_head(List<Type> *tmp, Type data) {
    tmp = new List<Type>;
    tmp->set_head(data);
    return tmp;
}

template <typename Type>
List<Type>* list_create_continue(List<Type> *tmp, Type data) {
    tmp->next = new List<Type>;
    tmp = tmp->next;
    tmp->set_head(data);
    return tmp;
}

template <typename Type>
List<Type>* list_append(List<Type> *head, Type data) {
    List<Type> *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    list_create_continue(tmp, data);
    return head;
}

template <typename Type>
List<Type>* clear_memory(List<Type> *head) {
    List<Type> *tmp;
    while (head != nullptr) {
        tmp = head;
        free(tmp);
        head = head->next;
    }
    return head;
}

template <typename Type>
List<Type>* operator+ (List<Type> head1, List<Type> head2) {
    List<Type> *tmp = &head1, *headf = nullptr, *tmpf = nullptr;
    tmpf = list_create_head(tmp, tmp->data);
    headf = tmpf;
    tmp = tmp->next;
    while (tmp != nullptr) {
        tmpf = list_create_continue(tmpf, tmp->data);
        tmp = tmp->next;
    }
    tmp = &head2;
    while (tmp != nullptr) {
        tmpf = list_create_continue(tmpf, tmp->data);
        tmp = tmp->next;
    }
    return headf;
}

template <typename Type>
List<Type>* list_map(List<Type> *head, void (*f)(List<Type>*)) {
    List<Type> *tmp = head;
    while (tmp != nullptr) {
        f(tmp);
        tmp = tmp->next;
    }
    return head;
}

template <typename Type>
List<Type>* list_where(List<Type> *head, bool (*f)(List<Type>*), int N) {
    List<Type> *tmp = head, *headf = nullptr, *tmpf = nullptr;
    N = 0;
    while (tmp != nullptr) {
        if (f(tmp)) {
            if (headf == nullptr) {
                tmpf = list_create_head(tmpf, tmp->data);
                headf = tmpf;
            }
            else {
                tmpf = list_create_continue(tmpf, tmp->data);
            }
            N++;
        }
        tmp = tmp->next;
    }
    head = clear_memory(head);
    return headf;
}

template <typename Type>
int list_reduce(List<Type> *head, int (*f)(List<Type>*, const int), const int c, int N) {
    List<Type> *tmp = head;
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            result = f(tmp, c);
        }
        else {
            result = f(tmp, result);
        }
        tmp = tmp->next;
    }
    return result;
}

template <typename Type>
List<Type>* list_get_subsequence(List<Type> *head, const int ind1, const int ind2) {
    List<Type> *tmp = head, *headf = nullptr, *tmpf = nullptr;
    for (int i = 1; i < ind1; i++) {
        tmp = tmp->next;
    }
    tmpf = new List<Type>;
    tmpf = list_create_head(tmpf, tmp->data);
    headf = tmpf;
    tmp = tmp->next;
    for (int i = ind1; i < ind2; i++) {
        tmpf = list_create_continue(tmpf, tmp->data);
        tmp = tmp->next;
    }
    return headf;
}

#endif
