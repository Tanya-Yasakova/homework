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
};

class Group {
private:
    student* students;
    int size;

public:
    Group();
    Group(int size);
    ~Group();
    void addStudent(const student& new_student);
    void removeStudent(const std::string& surname);
    student* findStudentBySurname(const std::string& surname);
    void printGroup();
    void readStudentsFromFile(const string& filepath);
    void addNewStudent();
};

#endif
