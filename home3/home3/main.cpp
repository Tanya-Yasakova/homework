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
    cout << group;


    cout << "Add a new student: " << "\n";
    group.addNewStudent();
    cout << group;
    int k = 0;
    string surname;
    cout << "Delete a student. Enter the student fio:  " << "\n";
    cin >>  surname ;
    int* found_student = group.findStudentBySurname(surname, k);
        cout << "Delete..." << "\n";
        for (int i = 0; i < k; i++) {
            cout << found_student[i];
        }
        group.removeStudent(found_student, k);
        cout << group;;


    string number;
    cout << "Delete a student. Enter the student's number:  " << "\n";
    cin >> number;
    int found_student_by_number = group.findStudentByNumber(number);
    if (found_student_by_number != -1) {
        cout << "Student found" <<  group.students[found_student_by_number] << "\n";
        cout << "Delete..." << "\n";
        group.removeStudentN(found_student_by_number);
        cout << group;
    }
    else {
        cout << "Student with number " << number << " not found.\n";
    }

    return 0;
}