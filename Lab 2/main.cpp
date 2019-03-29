#include "UI.h"
//Linked list realisation

int main(int argc, const char * argv[]) {
    Student lev;
    lev.set_student("Marder", "Lev", "Mikhaylovich", "B18-504");
    cout << "Developed by " << lev.student_get() << endl;
    string c;
    cout << "Type: ";
    cin >> c;
    while (not choice_fucker(c)) {
        cout << "ERROR: Type is not supported" << endl;
        cout << "Type: ";
        cin >> c;
    }
    if (c == "int") {
        int_UI();
    }
    else if (c == "student") {
        stud_UI();
    }
    else if (c == "func") {
        func_UI();
    }
    return 0;
}
