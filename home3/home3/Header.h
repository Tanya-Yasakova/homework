#ifndef Header_h
#define Header_h
#include <iostream>
#include <istream>
using namespace std;
class Group {
	struct data {
		int day;
		int month;
		int year;
	};
	struct student {
		string surname;
		string number;
		data birthday;
		string name;
		string lastname;
	};

};
#endif
