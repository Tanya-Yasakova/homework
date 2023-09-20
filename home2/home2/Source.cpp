#include "Header.h"
#include <iostream>
#include <istream>
#include <math.h>
using namespace std;
Vector::Vector()
{
    n = 0;
    x = NULL;
}

Vector::Vector(const Vector& vector)
{
    n = vector.n;
    x = new float[n];
    for (int i = 0; i < n; ++i) {
        x[i] = vector.x[i];
    }
}

float Vector::GetLength()const {
    float len = 0.f;
    for (int i = 0; i < n; i++) {
        len = len + x[i] * x[i];
    }
    return sqrt(len);
}

void Vector::completion() {
    cout << "Enter the size of the vector: " << endl;
    cin >> n;
    x = new float[n];
    cout << "Enter the coordinates of the vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
}

float Vector::operator*(const Vector& vector) {
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s += x[i] * vector.x[i];
	}
	return s;
}
const float Vector::GetCos(const Vector& vector) {
    float s = (*this) * vector;
    float comp = GetLength() * vector.GetLength();
    return (s / comp);
}

Vector Vector::operator+(const Vector& vector)
{
	Vector b(vector);
	for (int i = 0; i < n; i++)
	{
		b.x[i] += x[i];
	}
	return b;
}

Vector Vector::operator-(const Vector& vector)
{
	Vector b(*this);
	for (int i = 0; i < n; i++)
	{
		b.x[i] -= vector.x[i];
	}
	return b;
}


const Vector& Vector::operator=(const Vector& vector) {
	if ((*this) == vector) {
		return *this;
	}
	if (n != vector.n) {
		delete[] x;
		x = new float[vector.n];
		n = vector.n;
	}
	for (int i = 0; i < n; ++i) {
		x[i] = vector.x[i];
	}
	return *this;
}

bool Vector::operator==(const Vector& vector) const{
	if (n != vector.n) {
		return false;
	}
	for (int i = 0; i < n; ++i) {
		if (x[i] != vector.x[i]) {
			return false;
		}
	}
	return true;
}

bool Vector::operator!=(const Vector& vector) const{
	return !((*this) == vector);
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
	out << "( ";
	for (int i = 0; i < v.n; ++i) {
		out << v.x[i] << " ";
	}
	out << ")" << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
	in >> v.n;
	for (int i = 0; i < v.n; i++)
	{
		in >> v.x[i];
	}
	return in;
}

