#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Group::Group() {
   size = 0;
}


Group::Group(int size) : size(size) {
    students = new student[size];
}

Group::~Group() {
    delete[] students;
}


void Group::readStudentsFromFile(const string& filepath) {
    ifstream file(filepath);
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return;
    }

    int _size;
    file >> _size;

    size = _size;
    students = new student[size];

    for (int i = 0; i < size; i++) {
        student s;
        char dot;
        file >> s.name >> s.surname >> s.lastname
            >> s.birthday.day >> dot >> s.birthday.month >> dot >> s.birthday.year
            >> s.number;
        students[i] = s;
    }

}

void Group::printGroup() {
    for (int i = 0; i < this->size; i++) {
        if (!this->students[i].name.empty()) {
            cout << "Студент " << i + 1 << ":\n";
            cout << "Имя: " << this->students[i].name << "\n";
            cout << "Фамилия: " << this->students[i].surname << "\n";
            cout << "Отчество: " << this->students[i].lastname << "\n";
            cout << "Номер телефона: " << this->students[i].number << "\n";
            cout << "Дата рождения: " << this->students[i].birthday.day << "."
                << this->students[i].birthday.month << "."
                << this->students[i].birthday.year << "\n\n";
        }
    }
}








void Group::removeStudent(const string& surname) {
    for (int i = 0; i < size; i++) {
        if (students[i].surname == surname) {
            for (int j = i; j < size - 1; j++) {
                students[j] = students[j + 1];
            }
            students[size - 1] = student();
            return;
        }
    }
    cout << "Student with surname " << surname << " not found.\n";
}

int Group::findStudentBySurname(const string& name, const string& surname, const string& lastname) {
    for (int i = 0; i < size; i++) {
        if ((students[i].name == name) && (students[i].surname == surname) && (students[i].lastname == lastname)) {
            return i;
        }
    }
    return 0;
}

int Group::findStudentByNumber(const string& number) {
    for (int i = 0; i < size; i++) {
        if (students[i].number == number) {
            return i;
        }
    }
    return 0;
}

void Group::addNewStudent() {
    size++;
    student* add = new student[size];
    for (int i = 0; i < size-1; i++) {
        add[i] = students[i];
    }
    delete[] students;
    student new_student;
    cout << "Enter student's name: ";
    cin >> new_student.name;
    cout << "Enter student's surname: ";
    cin >> new_student.surname;
    cout << "Enter student's lastname: ";
    cin >> new_student.lastname;
    cout << "Enter student's birthday (day month year): ";
    cin >> new_student.birthday.day >> new_student.birthday.month >> new_student.birthday.year;
    cout << "Enter student's number: ";
    cin >> new_student.number;
    add[size - 1] = new_student;
    students = add;
}


