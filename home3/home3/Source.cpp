#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Group::Group() {
    size = 0;
    maxsize = 0;
}


Group::Group(int size, int maxsize) : size(size), maxsize(maxsize) {
    students = new student[maxsize];
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
    maxsize = size*2;
    students = new student[maxsize];

    for (int i = 0; i < size; i++) {
        student s;
        char dot;
        file >> s.name >> s.surname >> s.lastname
            >> s.birthday.day >> dot >> s.birthday.month >> dot >> s.birthday.year
            >> s.number;
        students[i] = s;
    }

}

void Group::removeStudent(int* find, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = find[i]; j < size - 1; j++) {
            students[j] = students[j + 1];
        }
        students[size - 1] = student();
        size = size - 1;
        for (int m = i; m < k; m++)
            find[m] -=  1;
    }
    return;
}
int* Group::findStudentBySurname(const string& surname, int& k) {
    k = 0;
    for (int i = 0; i < size; i++) {
        if  (students[i].surname == surname) {
            k++;
        }
    }
    int* find = new int[k];
    int m = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].surname == surname) {
            find[m] = i;
            m++;
          
        }
    }
    return find;
}



int Group::findStudentByNumber(const string& number) {
    for (int i = 0; i < size; i++) {
        if (students[i].number == number) {
            return i;
        }
    }
    return -1;
}
void Group::removeStudentN(const int& index) {
    for (int j = index; j < size - 1; j++) {
        students[j] = students[j + 1];
    }
    students[size - 1] = student();
    size = size - 1;
    return;
}

void Group::addNewStudent() {
    if (size == maxsize) {
        maxsize = maxsize * 2;
        student* add = new student[maxsize];
        for (int i = 0; i < size; i++) {
            add[i] = students[i];
        }
        delete[] students;
        students = add;
    }

    student new_student;
    cin >> new_student;

    students[size] = new_student;
    size++;
}