#ifndef Header_h
#define Header_h
#include <iostream>
#include "math.h"
using namespace std;

template <class T>
class Vector {
private:
	T* vec;
	int size;
public:
	Vector(int size_ = 10);
	Vector(const Vector<T>& obj);
	~Vector();
	const Vector<T>& operator=(const Vector<T>& obj);
	Vector<T> operator+(const Vector<T>& obj);
	Vector<T> operator-(const Vector<T>& obj);
	double operator*(const Vector<T>& obj) const;
	bool operator==(const Vector<T>& obj) const;
	bool operator!=(const Vector <T>& obj) const;
	double length() const;
	
	friend ostream& operator<<(ostream& out, const Vector<T>& obj) {
		out << "(" << obj.vec[0] << ", ";
		for (int i = 1; i < obj.size - 1; i++) {
			out << obj.vec[i] << ", ";
		}
		out << obj.vec[obj.size-1] << ") ";
		return out;
	}

	friend istream& operator>>(istream& in, Vector<T>& obj) {
		for (int i = 0; i < obj.size; i++) {
			in >> obj.vec[i];
		}
		return in;
	}
};

template <typename T>
Vector <T>::Vector(int size_) {
	if (size_ <= 0)
		throw "size error";
	size = size_;
	vec = new T[size];
}

template <typename T>
Vector <T>::Vector(const Vector <T>& obj) {
	size = obj.size;
	vec = new T[size];
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
}

template <typename T>
Vector <T>::~Vector() {
	if (size > 0)
		delete[] vec;
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector <T>& obj) {
	if (this == &(obj))
		return (*this);
	if (size != obj.size) {
		delete[] vec;
		size = obj.size;
		vec = new T[size];
	}
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
	return (*this);
}

template <typename T>
Vector <T> Vector <T>::operator + (const Vector <T>& obj) {
	if (size != obj.size) {
		throw "Diferent size";
	}
	Vector <T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.vec[i] += obj.vec[i];
	}
	return tmp;
}

template <typename T>
Vector <T> Vector <T>::operator - (const Vector <T>& obj) {
	if (size != obj.size) {
		throw "Diferent spaces";
	}
	Vector <T> tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.vec[i] -= obj.vec[i];
	}
	return tmp;
}

template <typename T>
double Vector <T>::operator * (const Vector <T>& obj) const {
	if (size != obj.size) {
		throw "Diferent spaces";
	}
	T answer = 0;
	for (int i = 0; i < size; i++) {
		answer += vec[i] * obj.vec[i];
	}
	return (double)answer;
}

template <typename T>
bool Vector <T>:: operator==(const Vector<T>& obj) const {
	if (this == &obj)
		return true;
	if (size != obj.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (vec[i] != obj.vec[i])
			return false;
	}
	return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector <T>& obj) const {
	return !((*this) == obj);
}

template <typename T>
double Vector<T>::length() const {
	double len = 0.f;
	for (int i = 0; i < size; i++) {
		len = len + vec[i] * vec[i];
	}
	return sqrt((double)len);
}
#endif
