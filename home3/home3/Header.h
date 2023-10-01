#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>
using namespace std;

struct date {
    int day;
    int month;
    int year;
    date(int d = 0, int m = 0, int y = 0) {
        day = d;
        month = m;
        year = y;
    }
};

struct student {
    string name;
    string surname;
    string lastname;
    string number;
    date birthday;
    void Set(string _surname, string _name, string _lastname, date _birthday, string _number) {
        name = _name;
        surname = _surname;
        lastname = _lastname;
        birthday = _birthday;
        number = _number;
    }
    friend ostream& operator<<(ostream& out, const student& obj) {
        out << "Name: " << obj.name << "\n";
        out << "Surname: " << obj.surname << "\n";
        out << "Lastname: " << obj.lastname << "\n";
        out << "Number: " << obj.number << "\n";
        out << "Birthday: " << obj.birthday.day << "."
            << obj.birthday.month << "."
            << obj.birthday.year << "\n";
        return out;
    }

    friend istream& operator>>(istream& in, student& obj) {
        cout << "Enter details for student:\n";
        cout << "Name: ";
        in >> obj.name;
        cout << "Surname: ";
        in >> obj.surname;
        cout << "Lastname: ";
        in >> obj.lastname;
        cout << "Birthday (day month year): ";
        in >> obj.birthday.day >> obj.birthday.month >> obj.birthday.year;
        cout << "Number: ";
        in >> obj.number;

        return in;
    }
};

class Group {
private:
    int size;
    int maxsize;

public:
    student* students;
    Group();
    Group(int size, int maxsize);
    ~Group();
    void removeStudent(const int& index);
    void removeStudentN(const int& index);
    int findStudentBySurname(const string& name, const string& surname, const string& lastname);
    int findStudentByNumber(const string& number);
    void readStudentsFromFile(const string& filepath);
    void addNewStudent();

    friend ostream& operator<<(ostream& out, const Group& group) {
        for (int i = 0; i < group.size; ++i) {
            out << "Студент " << i + 1 << ":\n";
            out << group.students[i] << "\n";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Group& group) {
        for (int i = 0; i < group.size; i++) {
            cout << "Enter details for student " << (i + 1) << ":\n";
            in >> group.students[i];
        }
        return in;
    }
};

#endif