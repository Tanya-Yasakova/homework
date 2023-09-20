#ifndef Header_h
#define Header_h
#include <iostream>
#include <istream>
#include <cmath>
using namespace std;

class Vector
{
private:
    int n;
    float* x;

public:
    Vector();
    Vector(const Vector& vector);
    void completion();
    float GetLength() const;

    const float GetCos(const Vector& vector);

    Vector operator+(const Vector& vector);
    Vector operator-(const Vector& vector);
    float operator*(const Vector& vector);
    const Vector& operator=(const Vector& vector);

    bool operator==(const Vector& vector) const;
    bool operator!=(const Vector& vector) const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);
};
#endif
