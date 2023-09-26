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

    string surname;
    cout << "Delete a student. Enter the student's last name:  " << "\n";
    cin >> surname;
    student* found_student = group.findStudentBySurname(surname);
    if (found_student != nullptr) {
        cout << "Student found: " << found_student->name << " " << found_student->surname << "\n";
        cout << "Delete..." << "\n";
        group.removeStudent(surname);
        group.printGroup();
    }
    else {
        cout << "Student with last name " << surname << " not found.\n";
    }

    return 0;
}
