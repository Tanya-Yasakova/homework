#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "rus");
    string filepath;
    cout << "Enter the file path: ";
    getline(cin, filepath);

    Group group;
    group.readStudentsFromFile(filepath);

    group.printGroup();

    

    cout << "Add a new student: " << "\n";
    group.addNewStudent();
    group.printGroup();

    string name, surname, lastname;
    cout << "Delete a student. Enter the student's last name:  " << "\n";
    cin >> name >> surname >> lastname;
    int found_student = group.findStudentBySurname(name, surname, lastname);
    if (found_student != 0) {
        cout << "Student found: " << students[found_student].name<< " " << students[found_student].surname << students[found_student].lastname << "\n";
        cout << "Delete..." << "\n";
        group.removeStudent(surname);
        group.printGroup();
    }
    else {
        cout << "Student with last name " << surname << " not found.\n";
    }

    string number;
    cout << "Delete a student. Enter the student's number:  " << "\n";
    cin >> number;
    student* found_student = group.findStudentBySurname(name, surname, lastname);
    if (found_student != nullptr) {
        cout << "Student found: " << found_student->name << " " << found_student->surname << found_student->lastname << "\n";
        cout << "Delete..." << "\n";
        group.removeStudent(surname);
        group.printGroup();
    }
    else {
        cout << "Student with last name " << surname << " not found.\n";
    }

    return 0;
}
